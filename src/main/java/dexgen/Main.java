package dexgen;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import dexgen.model.Species;
import dexgen.parser.FamiliesParser;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;


import java.io.InputStream;
import java.nio.file.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Path projectRoot = Paths.get("").toAbsolutePath();
        Path dataOut = projectRoot.resolve("data");         // write JSON here
        Files.createDirectories(dataOut);

        // 1) Read dex order from resources/data/input_data/pokedex.xlsx
        Map<String,Integer> nameToDex = loadDexOrder("/data/input_data/pokedex.xlsx");

        // 2) Parse families headers
        FamiliesParser fp = new FamiliesParser();
        Map<String, Species> byId = fp.parseAll(
                resourcePath("data/input_data/gen_1_families.h"),
                resourcePath("data/input_data/gen_2_families.h"),
                resourcePath("data/input_data/gen_3_families.h"),
                resourcePath("data/input_data/gen_4_families.h"),
                resourcePath("data/input_data/gen_5_families.h"),
                resourcePath("data/input_data/gen_6_families.h"),
                resourcePath("data/input_data/gen_7_families.h"),
                resourcePath("data/input_data/gen_8_families.h"),
                resourcePath("data/input_data/gen_9_families.h")
        );
        System.out.println("Parsed species blocks: " + byId.size());
        byId.values().stream().limit(5)
                .forEach(s -> System.out.println(" ex: " + s.speciesId() + " -> " + s.name()));
        Map<String,String> lvlSymMap = fp.getLevelSymbols();
        var movesParser = new dexgen.parser.MovesParser();
        Map<String, java.util.List<dexgen.model.LearnMove>> lvlBySym =
                movesParser.parse(
                        resourcePath("data/input_data/level_up_learnsets/gen_9.h")
                );
        var eggParser = new dexgen.parser.EggMovesParser();
        Map<String, java.util.List<String>> eggBySym =
                eggParser.parse(resourcePath("data/input_data/egg_moves.h"));

        var teachParser = new dexgen.parser.TeachableParser();
        Map<String, java.util.List<String>> teachBySym =
                teachParser.parse(resourcePath("data/input_data/teachable_learnsets.h"));


        Map<String,String> pre = new HashMap<>();
        for (Species s : byId.values()) {
            if (s.evolution() == null) continue;
            for (var e : s.evolution()) pre.put(e.toSpeciesId(), s.speciesId());
        }

        var encParser = new dexgen.parser.EncountersParser();
        Map<String, java.util.List<dexgen.model.Encounter>> enc =
                encParser.parse(resourcePath("data/input_data/wild_encounters.h"));
        enc.values().forEach(list -> list.removeIf(e -> e.area().startsWith("Battle Pyramid_")));
        enc.entrySet().removeIf(e -> e.getValue().isEmpty());

        dexgen.TranslationIO.writeAreaBucketSkeleton(enc, dataOut);


        // 3) Join: keep only obtainable species (present in Excel by display name)
        List<Map<String,Object>> index = new ArrayList<>();
        ObjectMapper M = new ObjectMapper().enable(SerializationFeature.INDENT_OUTPUT);

        int kept = 0, skipped = 0, shown = 0;

        for (Species s : byId.values()) {
            if (s.name() == null) { skipped++; continue; }

            String displayName = s.name();
            Integer dex = nameToDex.get(normalizeName(displayName));

            // Skip Gigantamax/GMAX forms entirely
            if (s.speciesId().contains("_GMAX") || s.speciesId().contains("_GIGANTAMAX")) {
                skipped++;
                continue;
            }

            // Always map MEGAs to the base dex and rename for display
            if (s.speciesId().contains("_MEGA")) {
                String baseId = s.speciesId().replaceFirst("_MEGA(?:_[A-Z])?$", ""); // _MEGA, _MEGA_X, _MEGA_Y
                Species base = byId.get(baseId);
                if (base != null) {
                    dex = nameToDex.get(normalizeName(base.name()));
                    if (s.speciesId().endsWith("_MEGA_X"))      displayName = base.name() + " - Mega X";
                    else if (s.speciesId().endsWith("_MEGA_Y")) displayName = base.name() + " - Mega Y";
                    else                                        displayName = base.name() + " - Mega";

                    // put the new display name back into s so downstream uses see it
                    s = new Species(
                            s.dex(), s.speciesId(), displayName,
                            s.types(), s.abilities(), s.evYield(),
                            s.malePct(), s.femalePct(), s.catchRate(), s.baseExp(),
                            s.eggGroups(), s.hatchSteps(), s.heightM(), s.weightKg(),
                            s.growthRate(), s.color(), s.category(), s.friendship(),
                            s.description(), base.speciesId(), s.evolution(), s.baseStats(),
                            s.heldItems(), s.levelUpMoves(), s.eggMoves(), s.teachableMoves(), s.encounters()
                    );
                }
            }

            if (dex == null) {
                if (shown < 15) {
                    System.out.println("No dex match: '" + displayName + "'  (" + s.speciesId() + ")");
                    shown++;
                }
                skipped++;
                continue;
            }

            kept++;

            String lvlSym = lvlSymMap.getOrDefault(s.speciesId(), null);
            List<dexgen.model.LearnMove> lvlMoves =
                    (lvlSym != null) ? lvlBySym.getOrDefault(lvlSym, java.util.List.of()) : java.util.List.of();

            String symBase = (lvlSym == null) ? null
                    : lvlSym.replaceFirst("LevelUpLearnset$", "").replaceFirst("^s", "");


            List<String> eggMoves =
                    (symBase != null) ? eggBySym.getOrDefault("s" + symBase + "EggMoveLearnset", java.util.List.of()) : java.util.List.of();

            List<String> teachableMoves =
                    (symBase != null) ? teachBySym.getOrDefault("s" + symBase + "TeachableLearnset", java.util.List.of()) : java.util.List.of();


            if (eggMoves.isEmpty() || teachableMoves.isEmpty()) {
                // find root species (walk pre-evolution chain)
                String rootId = s.speciesId();
                while (pre.get(rootId) != null) rootId = pre.get(rootId);

                // root's level-up symbol -> strip "LevelUpLearnset" to get base
                String rootLvlSym = lvlSymMap.get(rootId); // e.g. sBulbasaurLevelUpLearnset
                String rootBaseSym = (rootLvlSym == null) ? null
                        : rootLvlSym.replaceFirst("LevelUpLearnset$", "").replaceFirst("^s", "");

                if (eggMoves.isEmpty() && rootBaseSym != null) {
                    eggMoves = eggBySym.getOrDefault("s" + rootBaseSym + "EggMoveLearnset", List.of());
                }
                if (teachableMoves.isEmpty() && rootBaseSym != null) {
                    teachableMoves = teachBySym.getOrDefault("s" + rootBaseSym + "TeachableLearnset", List.of());
                }

            }




            Species withDex = new Species(
                    dex, s.speciesId(), s.name(), s.types(), s.abilities(), s.evYield(),
                    s.malePct(), s.femalePct(), s.catchRate(), s.baseExp(), s.eggGroups(),
                    s.hatchSteps(), s.heightM(), s.weightKg(), s.growthRate(),
                    s.color(), s.category(), s.friendship(), s.description(),
                    pre.get(s.speciesId()),            // preEvolutionId
                    s.evolution(),                     // evolution
                    s.baseStats(),                     // baseStats
                    s.heldItems(),                     // heldItems
                    lvlMoves,                          // levelUpMoves
                    eggMoves,                          // eggMoves
                    teachableMoves,                    // teachableMoves
                    enc.getOrDefault(s.speciesId(), java.util.List.of()) // encounters
            );





            // write per-species JSON
            String file = String.format("%03d_%s.json", dex, s.speciesId());
            M.writeValue(dataOut.resolve(file).toFile(), withDex);

            Map<String,Object> idx = new LinkedHashMap<>();
            idx.put("dex", dex);
            idx.put("speciesId", s.speciesId());        // was "species_id"
            idx.put("name", s.name());
            idx.put("types", s.types());
            idx.put("abilities", s.abilities());        // allow searching by ability
            idx.put("color", s.color());
            idx.put("file", file);                      // explicit filename
            index.add(idx);
        }

        System.out.println("Kept: " + kept + "  Skipped: " + skipped);

        var mip = new dexgen.parser.MoveTypeParser();
        Map<String, Map<String,Object>> moveInfo =
                mip.parse(resourcePath("data/input_data/moves_info.h"));

        M.writeValue(dataOut.resolve("move_types.json").toFile(), moveInfo);




        // 4) write index.json sorted by dex
        index.sort(Comparator.<Map<String,Object>, Integer>comparing(o -> (Integer)o.get("dex"))
                .thenComparing(o -> (String)o.get("speciesId")));
        M.writeValue(dataOut.resolve("index.json").toFile(), index);

        System.out.println("Wrote JSON to: " + dataOut.toAbsolutePath());
    }


    // --- helpers ---
    private static String normalizeName(String n){
        if (n == null) return "";
        return n.toLowerCase(Locale.ROOT)
                .replace('é','e')
                .replace("♀"," female")
                .replace("♂"," male")
                .replace("’","'")
                .replace(".", "")
                .replace("-", " ")
                .replace("_", " ")
                .replaceAll("\\s+"," ")
                .trim();
    }


    private static Map<String,Integer> loadDexOrder(String resourceXlsx) throws Exception {
        Map<String,Integer> map = new HashMap<>();
        try (InputStream in = Main.class.getResourceAsStream(resourceXlsx);
             Workbook wb = new XSSFWorkbook(in)) {
            Sheet sh = wb.getSheetAt(0);
            // find header row and name column
            Row header = sh.getRow(sh.getFirstRowNum());
            int nameCol = -1;
            for (Cell c : header) {
                String v = c.getStringCellValue().trim().toLowerCase(Locale.ROOT);
                if (List.of("name","pokemon","pokémon","species").contains(v)) { nameCol = c.getColumnIndex(); break; }
            }
            if (nameCol < 0) throw new IllegalStateException("Name column not found");

            int dex = 1;
            for (int r = header.getRowNum()+1; r <= sh.getLastRowNum(); r++){
                Row row = sh.getRow(r); if (row==null) continue;
                Cell c = row.getCell(nameCol); if (c==null) continue;
                String name = c.getStringCellValue(); if (name==null || name.isBlank()) continue;
                map.put(name.trim().toLowerCase(Locale.ROOT), dex++);
            }
        }
        return map;
    }

    private static Path resourcePath(String res) throws Exception {
        // copy resource to a temp file then return its Path, or load from working dir if you placed headers there.
        return Paths.get("src/main/resources").resolve(res);
    }
}
