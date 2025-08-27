package dexgen.parser;

import dexgen.model.Species;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;

public class FamiliesParser {

    // block: [SPECIES_BULBASAUR] = { ... },
    private static final Pattern BLOCK = Pattern.compile(
            "\\[\\s*(SPECIES_[A-Z0-9_]+)\\s*]\\s*=\\s*\\{([\\s\\S]*?)\\}\\s*,?",
            Pattern.MULTILINE);
    private static final Pattern P_INT_OR_MACRO =
            Pattern.compile("\\.(expYield|friendship)\\s*=\\s*([A-Z_]+)(?:\\(([^)]+)\\))?");

    private static final Pattern P_NAME     = Pattern.compile("speciesName\\s*=\\s*_\\(\"([^\"]+)\"\\)");
    // .speciesName = _("Bulbasaur")
    private static final Pattern P_NAME_SIMPLE =
            Pattern.compile("speciesName\\s*=\\s*_\\(\"([^\"]+)\"\\)");
    // .speciesName = HANDLE_EXPANDED_SPECIES_NAME("Short", "Long")
    private static final Pattern P_NAME_HANDLE =
            Pattern.compile("speciesName\\s*=\\s*HANDLE_EXPANDED_SPECIES_NAME\\s*\\(\\s*\"([^\"]+)\"\\s*,\\s*\"([^\"]+)\"\\s*\\)");
    private static final Pattern P_CATEGORY = Pattern.compile("categoryName\\s*=\\s*_\\(\"([^\"]+)\"\\)");
    private static final Pattern P_DESC_BLOCK =
            Pattern.compile("description\\s*=\\s*COMPOUND_STRING\\(([^)]*)\\)");
    private static final Pattern P_QSTR =
            Pattern.compile("\"([\\s\\S]*?)\"");
    private static final Pattern P_TYPES =
            Pattern.compile("\\.?types\\s*=\\s*MON_TYPES\\s*\\(([^)]+)\\)");
    private static final Pattern P_ABIL     = Pattern.compile("abilities\\s*=\\s*\\{\\s*(ABILITY_[A-Z_]+)(?:\\s*,\\s*(ABILITY_[A-Z_]+))?(?:\\s*,\\s*(ABILITY_[A-Z_]+))?\\s*}");
    private static final Pattern P_COLOR    = Pattern.compile("bodyColor\\s*=\\s*(BODY_COLOR_[A-Z_]+)");
    private static final Pattern P_GROWTH   = Pattern.compile("growthRate\\s*=\\s*(GROWTH_[A-Z_]+)");
    private static final Pattern P_EGG      = Pattern.compile("eggGroups\\s*=\\s*MON_EGG_GROUPS\\(([^)]+)\\)");
    private static final Pattern P_GENDER   = Pattern.compile("genderRatio\\s*=\\s*(PERCENT_FEMALE\\(([^)]+)\\)|MON_MALE|MON_FEMALE|MON_GENDERLESS)");
    private static final Pattern P_INT      = Pattern.compile("\\.(catchRate|expYield|eggCycles|friendship|height|weight)\\s*=\\s*([0-9.]+)");
    private static final Pattern P_EVS      = Pattern.compile("evYield_([A-Za-z]+)\\s*=\\s*(\\d+)");
    private static final Pattern P_EVOS =
            Pattern.compile("\\.evolutions\\s*=\\s*EVOLUTION\\(([^)]*)\\)");
    private static final Pattern P_EVO_TUPLE =
            Pattern.compile("\\{\\s*(EVO_[A-Z_]+)\\s*,\\s*([^,\\}]+)\\s*,\\s*(SPECIES_[A-Z0-9_]+)\\s*\\}");
    private static final Pattern P_BASE =
            Pattern.compile("\\.base(HP|Attack|Defense|SpAttack|SpDefense|Speed)\\s*=\\s*(\\d+)");
    private static final Pattern P_LVLUP_SYM =
            Pattern.compile("levelUpLearnset\\s*=\\s*([A-Za-z0-9_]+)");
    private static final Pattern P_ITEMS =
            Pattern.compile("\\.(?:item1|itemCommon|itemRare|item2)\\s*=\\s*(ITEM_[A-Z0-9_]+)");



    public Map<String, Species> parseAll(Path... headers) throws IOException {
        Map<String, Species> out = new LinkedHashMap<>();
        for (Path p : headers) parseOne(p, out);
        return out;
    }
    private static String mapTypeToken(String tok) {
        tok = tok.trim();
        // common family-type macros -> pick modern value
        if (tok.equals("TOGEPI_FAMILY_TYPE")) return "Fairy";
        // strip casts or extra parens
        tok = tok.replaceAll("[()]", "");
        if (tok.startsWith("TYPE_")) return mapType(tok);
        // fallback: unknown macro -> null
        return null;
    }

    private void parseOne(Path header, Map<String, Species> sink) throws IOException {
        String text = Files.readString(header, StandardCharsets.UTF_8);

        // find `[SPECIES_X] = {` headers
        Pattern head = Pattern.compile("\\[\\s*(SPECIES_[A-Z0-9_]+)\\s*]\\s*=\\s*\\{", Pattern.MULTILINE);
        Matcher m = head.matcher(text);
        while (m.find()) {
            String speciesId = m.group(1);
            int bodyStart = m.end() - 1; // points at the '{'
            int bodyEnd = findMatchingBrace(text, bodyStart);
            if (bodyEnd < 0) continue;

            String body = text.substring(bodyStart + 1, bodyEnd); // inside {...}

            String name = null;
            Matcher mhName = P_NAME_HANDLE.matcher(body);
            if (mhName.find()) {
                name = mhName.group(2);                // take the long/full name (e.g., "Centiskorch")
            } else {
                Matcher msName = P_NAME_SIMPLE.matcher(body);
                if (msName.find()) name = msName.group(1);
            }
            String category = find(P_CATEGORY, body);
            String desc = null;
            Matcher db = P_DESC_BLOCK.matcher(body);
            if (db.find()) {
                String inside = db.group(1);
                StringBuilder sb = new StringBuilder();
                Matcher qs = P_QSTR.matcher(inside);
                while (qs.find()) sb.append(qs.group(1));
                desc = sb.toString().replace("\\n", "\n").replace("\\\"", "\"");
            }

            int catchRate = 0, expYield = 0, eggCycles = 0, friendship = 0;
            double heightM = 0, weightKg = 0;
            Matcher ni = P_INT.matcher(body);
            while (ni.find()) {
                switch (ni.group(1)) {
                    case "catchRate" -> catchRate = toInt(ni.group(2));
                    case "expYield"  -> expYield  = toInt(ni.group(2));
                    case "eggCycles" -> eggCycles = toInt(ni.group(2));
                    case "friendship"-> friendship= toInt(ni.group(2));
                    case "height"    -> heightM   = toInt(ni.group(2)) / 10.0;
                    case "weight"    -> weightKg  = toInt(ni.group(2)) / 10.0;
                }
            }
            Matcher mm = P_INT_OR_MACRO.matcher(body);
            while (mm.find()) {
                String key = mm.group(1);
                String macro = mm.group(2);
                String arg = mm.group(3); // may be null

                if ("expYield".equals(key)) {
                    // prefer number inside parentheses if present
                    if (arg != null && arg.matches("\\d+")) {
                        expYield = Integer.parseInt(arg);
                    } else if (macro.matches("\\d+")) {
                        expYield = Integer.parseInt(macro);
                    } // else leave as parsed numeric (or 0)
                } else if ("friendship".equals(key)) {
                    if ("STANDARD_FRIENDSHIP".equals(macro)) friendship = 70;
                    else if (arg != null && arg.matches("\\d+")) friendship = Integer.parseInt(arg);
                    else if (macro.matches("\\d+")) friendship = Integer.parseInt(macro);
                }
            }

            Map<String,Integer> evs = new HashMap<>();
            Matcher evm = P_EVS.matcher(body);
            while (evm.find()) evs.put(simplifyStat(evm.group(1)), Integer.parseInt(evm.group(2)));

            Map<String,Integer> base = new LinkedHashMap<>();
            Matcher bm = P_BASE.matcher(body);
            while (bm.find()) {
                String k = switch (bm.group(1)) {
                    case "HP" -> "hp";
                    case "Attack" -> "atk";
                    case "Defense" -> "def";
                    case "SpAttack" -> "spa";
                    case "SpDefense" -> "spd";
                    case "Speed" -> "spe";
                    default -> bm.group(1).toLowerCase(Locale.ROOT);
                };
                base.put(k, Integer.parseInt(bm.group(2)));
            }

            String lvlSym = null;
            Matcher ls = P_LVLUP_SYM.matcher(body);
            if (ls.find()) lvlSym = ls.group(1);
            if (lvlSym != null) speciesToLvlSymbol.put(speciesId, lvlSym);

            Map<String,String> items = new LinkedHashMap<>();
            Matcher im = P_ITEMS.matcher(body);
            while (im.find()) {
                String token = im.group(1);                 // ITEM_*
                String nice = trimEnum(token, "ITEM_");
                // guess common/rare by first insertion order if both present
                if (!items.containsKey("common")) items.put("common", nice);
                else if (!items.containsKey("rare")) items.put("rare", nice);
            }

            List<String> types = new ArrayList<>(2);
            Matcher t = P_TYPES.matcher(body);
            if (t.find()) {
                for (String raw : t.group(1).split(",")) types.add(mapTypeToken(raw.trim()));
            }
            types.removeIf(Objects::isNull);
            if (types.size() == 1) types.add(null);


            List<String> abilities = new ArrayList<>(3);
            Matcher a = P_ABIL.matcher(body);
            if (a.find()) {
                abilities.add(mapAbility(a.group(1)));
                abilities.add(a.group(2) == null ? null : mapAbility(a.group(2)));
                abilities.add(a.group(3) == null ? null : mapAbility(a.group(3)));
            }

            List<String> eggGroups = new ArrayList<>();
            Matcher eg = P_EGG.matcher(body);
            if (eg.find()) for (String tok : eg.group(1).split(",")) eggGroups.add(mapEgg(tok.trim()));

            Double male = null, female = null;
            Matcher g = P_GENDER.matcher(body);
            if (g.find()) {
                String raw = g.group(1);
                if (raw.startsWith("PERCENT_FEMALE")) { double f = Double.parseDouble(g.group(2)); female=f; male=100.0-f; }
                else if ("MON_MALE".equals(raw)) { male=100.0; female=0.0; }
                else if ("MON_FEMALE".equals(raw)) { male=0.0; female=100.0; }
            }

            String growth = mapGrowth(find(P_GROWTH, body));
            String color  = mapColor(find(P_COLOR, body));

            List<dexgen.model.Evo> evos = new ArrayList<>();
            Matcher ev = P_EVOS.matcher(body);
            if (ev.find()) {
                String inside = ev.group(1);
                Matcher tup = P_EVO_TUPLE.matcher(inside);
                while (tup.find()) {
                    String method = tup.group(1).replace("EVO_","").toLowerCase(Locale.ROOT);
                    String param  = tup.group(2).trim();
                    String toId   = tup.group(3);
                    evos.add(new dexgen.model.Evo(toId, method, param));
                }
            }


            Species sp = new Species(
                    -1, speciesId, name, types, abilities, evs,
                    male, female, catchRate, expYield, eggGroups,
                    eggCycles * 256, heightM, weightKg, growth, color,
                    category, friendship == 0 ? null : friendship, desc,
                    null,                      // preEvolutionId (filled later in Main)
                    evos,                      // evolution
                    base,                      // baseStats
                    items,                     // heldItems
                    null,                      // levelUpMoves (filled in Main)
                    null,                      // eggMoves (filled in Main)
                    null,                      // teachableMoves (filled in Main)
                    java.util.List.of()        // encounters (filled in Main)
            );


            sink.put(speciesId, sp);
        }
    }

    /** finds the index of the matching '}' for the '{' at startIdx */
    private static int findMatchingBrace(String s, int startIdx) {
        int depth = 0; boolean inStr = false; char prev = 0;
        for (int i = startIdx; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '"' && prev != '\\') inStr = !inStr;
            if (!inStr) {
                if (c == '{') depth++;
                else if (c == '}' && --depth == 0) return i;
            }
            prev = c;
        }
        return -1;
    }

    private final Map<String,String> speciesToLvlSymbol = new HashMap<>();
    public Map<String,String> getLevelSymbols() { return speciesToLvlSymbol; }

    private static int toInt(String s) { return (int)Math.round(Double.parseDouble(s)); }

    private static String find(Pattern p, String body) {
        Matcher m = p.matcher(body);
        return m.find() ? m.group(1) : null;
    }

    private static String unescapeCompound(String qstr) {
        if (qstr == null) return null;
        // strip surrounding quotes, keep \n as newline
        String s = qstr.substring(1, qstr.length()-1);
        return s.replace("\\n", "\n").replace("\\\"", "\"");
    }

    // --- trivial mappers. Replace with real lookup tables later if needed.
    // replace your trimEnum + helpers with this:

    private static String trimEnum(String s, String prefix) {
        if (s == null) return null;
        String base = s.startsWith(prefix) ? s.substring(prefix.length()) : s;
        base = base.toLowerCase(Locale.ROOT).replace('_', ' ').trim();
        return capitalizeWords(base);
    }

    private static String capitalizeWords(String in) {
        StringBuilder sb = new StringBuilder(in.length());
        boolean up = true;
        for (int i = 0; i < in.length(); i++) {
            char ch = in.charAt(i);
            if (Character.isLetter(ch)) {
                sb.append(up ? Character.toUpperCase(ch) : ch);
                up = false;
            } else {
                sb.append(ch);
                up = Character.isWhitespace(ch);
            }
        }
        return sb.toString();
    }


    private static String mapType(String t)     { return trimEnum(t, "TYPE_"); }
    private static String mapAbility(String a)  { return trimEnum(a, "ABILITY_"); }
    private static String mapEgg(String e)      { return trimEnum(e, "EGG_GROUP_"); }
    private static String mapGrowth(String g)   { return trimEnum(g, "GROWTH_"); }
    private static String mapColor(String c)    { return trimEnum(c, "BODY_COLOR_"); }

    private static String simplifyStat(String s){
        switch (s.toLowerCase(Locale.ROOT)) {
            case "hp": return "hp";
            case "attack": return "atk";
            case "defense": return "def";
            case "spattack", "sp_atk", "spatk": return "spa";
            case "spdefense", "sp_def", "spdef": return "spd";
            case "speed": return "spe";
            default: return s;
        }
    }

}
