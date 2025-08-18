package dexgen.parser;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;

public class MoveTypeParser {

    private static final Pattern BLOCK = Pattern.compile(
            "\\[MOVE_([A-Z0-9_]+)]\\s*=\\s*\\{([\\s\\S]*?)\\},",
            Pattern.MULTILINE);

    private static final Pattern FIELD = Pattern.compile("\\.(\\w+)\\s*=\\s*([^,]+)\\s*,", Pattern.MULTILINE);
    private static final Pattern TYPE  = Pattern.compile("TYPE_([A-Z]+)");
    private static final Pattern CAT   = Pattern.compile("DAMAGE_CATEGORY_([A-Z]+)");
    private static final Pattern BOOL  = Pattern.compile("\\b(TRUE|FALSE)\\b");
    private static final Pattern INT   = Pattern.compile("^-?\\d+$");
    private static final Pattern TARGET= Pattern.compile("MOVE_TARGET_([A-Z_]+)");
    private static final Pattern EFFECT= Pattern.compile("EFFECT_([A-Z_]+)");

    // .name/.description use COMPOUND_STRING("..." "..." ...)
    private static final Pattern COMPOUND = Pattern.compile("COMPOUND_STRING\\s*\\(([^)]*)\\)", Pattern.DOTALL);
    private static final Pattern QUOTED   = Pattern.compile("\"([\\s\\S]*?)\"");

    public Map<String, Map<String,Object>> parse(Path header) throws IOException {
        String text = Files.readString(header, StandardCharsets.UTF_8);
        Map<String, Map<String,Object>> out = new HashMap<>();

        Matcher b = BLOCK.matcher(text);
        while (b.find()) {
            String moveToken = b.group(1);         // e.g. KARATE_CHOP
            String body      = b.group(2);

            Map<String,Object> m = new LinkedHashMap<>();
            m.put("token", "MOVE_" + moveToken);

            // Collect raw fields
            Matcher f = FIELD.matcher(body);
            Map<String,String> raw = new HashMap<>();
            while (f.find()) raw.put(f.group(1), f.group(2).trim());

            // Pretty name/description
            m.put("name", readCompound(body, "name"));
            m.put("description", readCompound(body, "description"));

            // Type / Category / Target / Effect
            m.put("type", tidyType(raw.get(".type".substring(1))));                // fall through below too
            m.put("category", tidyEnum(raw.get("category"), CAT));
            m.put("target", tidyEnum(raw.get("target"), TARGET));
            m.put("effect", tidyEnum(raw.get("effect"), EFFECT));

            // Simple numerics with fallback to raw token
            m.put("power", tidyNumberOrToken(raw.get("power")));
            m.put("accuracy", tidyNumberOrToken(raw.get("accuracy")));
            m.put("pp", tidyNumberOrToken(raw.get("pp")));
            m.put("priority", tidyNumberOrToken(raw.get("priority")));
            m.put("crit", tidyNumberOrToken(raw.getOrDefault("criticalHitStage", raw.get("criticalHitRatio"))));

            // Booleans / flags
            m.put("makesContact", tidyBoolean(raw.get("makesContact")));

            // Keep raw target/category/effect token too (useful later)
            m.put("_rawTarget", raw.get("target"));
            m.put("_rawCategory", raw.get("category"));
            m.put("_rawEffect", raw.get("effect"));

            // Friendly Title Case key
            String key = tidyMove(moveToken);
            // Ensure type again from explicit pattern if missing
            if (m.get("type") == null) m.put("type", tidyEnum(raw.get("type"), TYPE));

            out.put(key, m);
        }
        return out;
    }

    // Helpers

    private static String readCompound(String body, String field) {
        // Find ".field = COMPOUND_STRING(...),"
        Pattern p = Pattern.compile("\\." + Pattern.quote(field) + "\\s*=\\s*COMPOUND_STRING\\s*\\(([^)]*)\\)\\s*,", Pattern.DOTALL);
        Matcher m = p.matcher(body);
        if (!m.find()) return null;
        String inside = m.group(1);
        // Concatenate every quoted bit
        StringBuilder sb = new StringBuilder();
        Matcher q = QUOTED.matcher(inside);
        while (q.find()) sb.append(q.group(1));
        // Unescape C-style "\n"
        return sb.toString().replace("\\n", "\n");
    }

    private static Object tidyNumberOrToken(String v) {
        if (v == null) return null;
        v = v.trim();
        if (INT.matcher(v).matches()) return Integer.parseInt(v);
        return v; // token like ACC_NEVER_MISS, or a macro
    }

    private static Boolean tidyBoolean(String v) {
        if (v == null) return null;
        Matcher m = BOOL.matcher(v);
        if (m.find()) return "TRUE".equals(m.group(1));
        return null;
    }

    private static String tidyEnum(String v, Pattern pat) {
        if (v == null) return null;
        Matcher m = pat.matcher(v);
        if (!m.find()) return null;
        String token = m.group(1).toLowerCase(Locale.ROOT).replace('_',' ');
        return Character.toUpperCase(token.charAt(0)) + token.substring(1);
    }

    private static String tidyType(String v) {
        return tidyEnum(v, TYPE);
    }

    private static String tidyMove(String token) {
        String base = token.toLowerCase(Locale.ROOT).replace('_',' ').trim();
        StringBuilder sb = new StringBuilder(base.length());
        boolean up = true;
        for (char c : base.toCharArray()) {
            if (Character.isLetter(c)) { sb.append(up ? Character.toUpperCase(c) : c); up=false; }
            else { sb.append(c); up=true; }
        }
        return sb.toString();
    }
}