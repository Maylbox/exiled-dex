package dexgen.parser;

import java.nio.file.*; import java.nio.charset.StandardCharsets;
import java.util.*; import java.util.regex.*;

public class EggMovesParser {
    private static final Pattern ARRAY = Pattern.compile(
            "static\\s+const\\s+u16\\s+(s[A-Za-z0-9_]+EggMoveLearnset)\\s*\\[\\s*]\\s*=\\s*\\{([\\s\\S]*?)\\};",
            Pattern.MULTILINE);
    private static final Pattern MOVE = Pattern.compile("MOVE_([A-Z0-9_]+)");

    public Map<String,List<String>> parse(Path header) throws Exception {
        String text = Files.readString(header, StandardCharsets.UTF_8);
        Map<String,List<String>> out = new HashMap<>();

        Matcher a = ARRAY.matcher(text);
        while (a.find()) {
            String sym  = a.group(1);   // e.g. sBulbasaurEggMoveLearnset
            String body = a.group(2);
            List<String> moves = new ArrayList<>();
            Matcher m = MOVE.matcher(body);
            while (m.find()) {
                String tok = m.group(1);
                if ("UNAVAILABLE".equals(tok)) break;          // MOVE_UNAVAILABLE
                moves.add(tidyMove(tok));
            }
            // sort + dedup
            moves = moves.stream().distinct().sorted().toList();
            out.put(sym, moves);
        }
        return out;
    }

    private static String tidyMove(String tokenNoPrefix) {
        String base = tokenNoPrefix.toLowerCase(Locale.ROOT).replace('_',' ').trim();
        StringBuilder sb = new StringBuilder(base.length());
        boolean up = true;
        for (char c : base.toCharArray()) {
            if (Character.isLetter(c)) { sb.append(up?Character.toUpperCase(c):c); up=false; }
            else { sb.append(c); up = Character.isWhitespace(c); }
        }
        return sb.toString();
    }
}
