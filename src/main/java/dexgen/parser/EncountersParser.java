package dexgen.parser;

import dexgen.model.Encounter;
import java.nio.file.*; import java.nio.charset.StandardCharsets;
import java.util.*; import java.util.regex.*;

public class EncountersParser {
    private static final Pattern BLOCK = Pattern.compile(
            "const\\s+struct\\s+WildPokemon\\s+g([A-Za-z0-9_]+)_([A-Za-z]+)Mons\\s*\\[\\s*]\\s*=\\s*\\{([\\s\\S]*?)\\};");
    private static final Pattern ROW   = Pattern.compile(
            "\\{\\s*(\\d+)\\s*,\\s*(\\d+)\\s*,\\s*SPECIES_([A-Z0-9_]+)\\s*}\\s*,?");
    private static final Pattern EXCLUDE_AREA = Pattern.compile("(?i)^BattlePyramid_\\d+$"); // NEW

    public Map<String,List<Encounter>> parse(Path header) throws Exception {
        String text = Files.readString(header, StandardCharsets.UTF_8);
        Map<String,List<Encounter>> out = new HashMap<>();

        Matcher b = BLOCK.matcher(text);
        while (b.find()) {
            String areaRaw = b.group(1);
            if (EXCLUDE_AREA.matcher(areaRaw).matches()) continue;
            String bucket  = b.group(2);
            String body    = b.group(3);

            // find matching Info rate
            Pattern infoForThis = Pattern.compile(
                    "const\\s+struct\\s+WildPokemonInfo\\s+g" + areaRaw + "_" + bucket + "MonsInfo\\s*=\\s*\\{\\s*(\\d+)\\s*,\\s*g" + areaRaw + "_" + bucket + "Mons\\s*\\};");
            Matcher im = infoForThis.matcher(text);
            Integer rateBase = im.find() ? Integer.valueOf(im.group(1)) : null;

            int slot = 0;
            Matcher r = ROW.matcher(body);
            while (r.find()) {
                int min = Integer.parseInt(r.group(1));
                int max = Integer.parseInt(r.group(2));
                String speciesId = "SPECIES_" + r.group(3);

                out.computeIfAbsent(speciesId, k -> new ArrayList<>())
                        .add(new Encounter(prettify(areaRaw), prettifyBucket(bucket), rateBase, min, max, slot++));
            }
        }
        return out;
    }

    private static String prettify(String raw){
        String s = raw.replaceAll("(?<=[a-z])(?=[A-Z])"," ");
        s = s.replaceAll("Route\\s*(\\d+)","Route $1");
        return s.trim();
    }
    private static String prettifyBucket(String b){
        return b.replace("RockSmash","Rock Smash");
    }
}
