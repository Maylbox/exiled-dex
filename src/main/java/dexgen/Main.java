package dexgen;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import dexgen.model.Species;
import dexgen.parser.FamiliesParser;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;


import java.io.InputStream;
import java.nio.file.*;
import java.util.*;

import java.util.regex.*;

public class Main {
    private static boolean isExiled(String id) {
        return id != null && id.startsWith("SPECIES_EXILED_");
    }
    // What the Excel specifies: which bases exist + which tags are allowed per base.
    private record DexPlan(Map<String,Integer> baseDex, Map<String,Set<String>> allowedTags) {}

    private static final Set<String> VALID_TAGS = Set.of("M","MX","MY","E","A","H","G","P");
// A=Alolan, H=Hisuian, G=Galarian, P=Paldean, E=Exiled, M/MX/MY=Mega

    // Return tag code for an id, or null for the "blanket/base" form
    private static String tagForId(String id){
        if (id == null) return null;
        if (id.contains("_MEGA_X")) return "MX";
        if (id.contains("_MEGA_Y")) return "MY";
        if (id.contains("_MEGA"))   return "M";
        if (id.startsWith("SPECIES_EXILED_")) return "E";
        if (id.endsWith("_ALOLAN"))  return "A";
        if (id.endsWith("_HISUIAN")) return "H";
        if (id.endsWith("_GALARIAN"))return "G";
        if (id.endsWith("_PALDEAN")) return "P";
        return null;
    }

    // Map any tagged id back to its *base* species id (no EXILED/REGIONAL/MEGA suffixes)
    private static String baseIdOf(String id){
        if (id == null) return null;
        String base = id;
        base = base.replaceFirst("^SPECIES_EXILED_", "SPECIES_");
        base = base.replaceFirst("_MEGA(?:_[A-Z])?$", "");
        base = base.replaceFirst("_(ALOLAN|HISUIAN|GALARIAN|PALDEAN)$", "");
        return base;
    }
    public static void main(String[] args) throws Exception {
        Path projectRoot = Paths.get("").toAbsolutePath();
        Path dataOut = projectRoot.resolve("data");         // write JSON here
        Files.createDirectories(dataOut);

        Path speciesOut = dataOut.resolve("species");
        Files.createDirectories(speciesOut);

        // 1) Read dex order from resources/data/input_data/pokedex.xlsx
        DexPlan plan = parseDexPlan("/data/input_data/updated_pokedex.xlsx");
        Map<String,Integer> nameToDex = plan.baseDex(); // keep old variable if you like


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

        int nextDex = nameToDex.values().stream().mapToInt(Integer::intValue).max().orElse(0);

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
            // === Inclusion check from spreadsheet ===
            String tag = tagForId(s.speciesId());          // null for base/blanket forms
            String baseId = baseIdOf(s.speciesId());
            Species baseSp = byId.getOrDefault(baseId, s);  // fall back to itself
            String baseKey = normalizeName(baseSp.name());

// If the base isn’t listed at all -> exclude
            Integer dexFromPlan = plan.baseDex().get(baseKey);
            if (dexFromPlan == null) { skipped++; continue; }

            if (tag != null) {
                Set<String> allowedTags = plan.allowedTags().getOrDefault(baseKey, Set.of());
                boolean ok = allowedTags.contains(tag)
                        || (("MX".equals(tag) || "MY".equals(tag)) && allowedTags.contains("M")); // M allows MX/MY
                if (!ok) { skipped++; continue; }
            }

            String displayName = s.name();
            Integer dex = dexFromPlan;   // share the base dex position from the plan


            // Skip Gigantamax/GMAX forms entirely
            if (s.speciesId().contains("_GMAX") || s.speciesId().contains("_GIGANTAMAX")) {
                skipped++;
                continue;
            }

            // Always map MEGAs to the base dex and rename for display
            Species base = s;

            if (s.speciesId().contains("_MEGA")) {
                String baseIdMega = s.speciesId().replaceFirst("_MEGA(?:_[A-Z])?$", "");
                base = byId.getOrDefault(baseIdMega, s);

                if (s.speciesId().endsWith("_MEGA_X"))      displayName = base.name() + " - Mega X";
                else if (s.speciesId().endsWith("_MEGA_Y")) displayName = base.name() + " - Mega Y";
                else                                        displayName = base.name() + " - Mega";

                s = new Species(
                        s.dex(), s.speciesId(), displayName,
                        s.types(), s.abilities(), s.evYield(),
                        s.malePct(), s.femalePct(), s.catchRate(), s.baseExp(),
                        s.eggGroups(), s.hatchSteps(), s.heightM(), s.weightKg(),
                        s.growthRate(), s.color(), s.category(), s.friendship(),
                        s.description(), base.speciesId(), s.evolution(), s.baseStats(),
                        s.heldItems(), s.levelUpMoves(), s.eggMoves(), s.teachableMoves(), s.encounters()
                );

            } else if (s.speciesId().startsWith("SPECIES_EXILED_")) {
                String baseIdExiled = s.speciesId().replaceFirst("^SPECIES_EXILED_", "SPECIES_");
                base = byId.getOrDefault(baseIdExiled, s);
                displayName = "Exiled " + base.name();

                s = new Species(
                        s.dex(), s.speciesId(), displayName,
                        s.types(), s.abilities(), s.evYield(),
                        s.malePct(), s.femalePct(), s.catchRate(), s.baseExp(),
                        s.eggGroups(), s.hatchSteps(), s.heightM(), s.weightKg(),
                        s.growthRate(), s.color(), s.category(), s.friendship(),
                        s.description(), s.preEvolutionId(), s.evolution(), s.baseStats(),
                        s.heldItems(), s.levelUpMoves(), s.eggMoves(), s.teachableMoves(), s.encounters()
                );

            } else {
                String region = regionalAdjective(s.speciesId());
                if (region != null) {
                    String baseIdRegional = regionalBaseId(s.speciesId());   // e.g. SPECIES_VULPIX
                    base = byId.getOrDefault(baseIdRegional, s);
                    displayName = region + " " + base.name();                 // "Alolan Vulpix"

                    s = new Species(
                            s.dex(), s.speciesId(), displayName,
                            s.types(), s.abilities(), s.evYield(),
                            s.malePct(), s.femalePct(), s.catchRate(), s.baseExp(),
                            s.eggGroups(), s.hatchSteps(), s.heightM(), s.weightKg(),
                            s.growthRate(), s.color(), s.category(), s.friendship(),
                            s.description(), s.preEvolutionId(), s.evolution(), s.baseStats(),
                            s.heldItems(), s.levelUpMoves(), s.eggMoves(), s.teachableMoves(), s.encounters()
                    );
                }
            }



            if (dex == null) {
                if (shown < 15) System.out.println("No dex match: '" + displayName + "'  (" + s.speciesId() + ")");
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
            String filename = String.format("%03d_%s.json", dex, s.speciesId());
            M.writeValue(speciesOut.resolve(filename).toFile(), withDex);

// index entry
            Map<String,Object> idx = new LinkedHashMap<>();
            idx.put("dex", dex);
            idx.put("speciesId", s.speciesId());        // was "species_id"
            idx.put("name", s.name());
            idx.put("types", s.types());
            idx.put("abilities", s.abilities());        // allow searching by ability
            idx.put("color", s.color());
// IMPORTANT: include subfolder so the SPA fetches data/species/<file>
            idx.put("file", "species/" + filename);
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
        String s = n.toLowerCase(Locale.ROOT)
                .replace('é','e')
                .replace("♀"," female")
                .replace("♂"," male")
                .replace("’","'")
                .replace(".", "")
                .replace("-", " ")
                .replace("_", " ")
                .replaceAll("\\s+"," ")
                .trim();

        // Handle sheet shorthands for Nidoran
        if (s.matches("^nidoran\\s*f$") || s.matches("^nidoran\\s*\\(f\\)$"))
            return "nidoran female";
        if (s.matches("^nidoran\\s*m$") || s.matches("^nidoran\\s*\\(m\\)$"))
            return "nidoran male";

        return s;
    }

    private static String regionalAdjective(String id){
        if (id.endsWith("_ALOLAN"))  return "Alolan";
        if (id.endsWith("_GALARIAN"))return "Galarian";
        if (id.endsWith("_HISUIAN")) return "Hisuian";
        if (id.endsWith("_PALDEAN")) return "Paldean";
        return null;
    }
    private static String regionalBaseId(String id){
        return id.replaceFirst("_(ALOLAN|GALARIAN|HISUIAN|PALDEAN)$", "");
    }



    private static DexPlan parseDexPlan(String resourceXlsx) throws Exception {
        Map<String,Integer> baseDex = new LinkedHashMap<>();
        Map<String,Set<String>> allowed = new HashMap<>();

        try (InputStream in = Main.class.getResourceAsStream(resourceXlsx);
             Workbook wb = new XSSFWorkbook(in)) {

            Sheet sh = wb.getSheetAt(0);
            if (sh == null) return new DexPlan(baseDex, allowed);

            int first = sh.getFirstRowNum();
            int last  = sh.getLastRowNum();

            // Regex: "Charizard - MX" -> base="Charizard", tag="MX"
            Pattern FORM = Pattern.compile("^\\s*(.*?)\\s+-\\s+([A-Za-z]+)\\s*$");

            int dex = 1;
            for (int r = first; r <= last; r++) {
                Row row = sh.getRow(r);
                if (row == null) continue;

                // Column A defines base order if it has a base name
                String a = readCell(row.getCell(0));
                if (!a.isBlank()) {
                    String baseName = a.replaceFirst("\\s+-\\s+([A-Za-z]+)\\s*$", "").trim();
                    String key = normalizeName(baseName);
                    if (!baseDex.containsKey(key)) baseDex.put(key, dex++);
                }

                // Scan *all* non-empty cells in the row to collect explicit allowed tags
                short lastCell = row.getLastCellNum();
                for (int c = 0; c < (lastCell < 0 ? 0 : lastCell); c++) {
                    String txt = readCell(row.getCell(c));
                    if (txt.isBlank()) continue;

                    Matcher m = FORM.matcher(txt);
                    if (m.matches()) {
                        String baseName = m.group(1).trim();
                        String tag      = m.group(2).trim().toUpperCase(Locale.ROOT);
                        if (!VALID_TAGS.contains(tag)) continue;
                        String key2 = normalizeName(baseName);
                        if (!baseDex.containsKey(key2)) baseDex.put(key2, dex++);
                        allowed.computeIfAbsent(key2, k -> new LinkedHashSet<>()).add(tag);
                    } else {
                        // Plain name (may include hyphens like "Porygon-Z")
                        String key2 = normalizeName(txt.trim());
                        if (!key2.isBlank() && !baseDex.containsKey(key2)) baseDex.put(key2, dex++);
                    }
                }
            }
        }
        return new DexPlan(baseDex, allowed);
    }

    private static String readCell(Cell c){
        if (c == null) return "";
        return switch (c.getCellType()) {
            case STRING -> c.getStringCellValue();
            case NUMERIC -> (int)c.getNumericCellValue() + "";
            case BOOLEAN -> String.valueOf(c.getBooleanCellValue());
            default -> "";
        };
    }



    private static Path resourcePath(String res) throws Exception {
        // copy resource to a temp file then return its Path, or load from working dir if you placed headers there.
        return Paths.get("src/main/resources").resolve(res);
    }
}
