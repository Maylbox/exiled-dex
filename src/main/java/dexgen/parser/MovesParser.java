package dexgen.parser;

import dexgen.model.LearnMove;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;
import java.util.regex.*;

public class MovesParser {
    private static final Pattern ARRAY = Pattern.compile(
            "static\\s+const\\s+struct\\s+LevelUpMove\\s+(s[A-Za-z0-9_]+)\\s*\\[\\s*]\\s*=\\s*\\{([\\s\\S]*?)\\};",
            Pattern.MULTILINE);
    private static final Pattern MOVE = Pattern.compile(
            "LEVEL_UP_MOVE\\s*\\(\\s*(\\d+)\\s*,\\s*MOVE_([A-Z0-9_]+)\\)");

    public Map<String, List<LearnMove>> parse(Path... headers) throws IOException {
        Map<String, List<LearnMove>> out = new HashMap<>();

        for (Path h : headers) {
            String text = Files.readString(h, StandardCharsets.UTF_8);
            Matcher a = ARRAY.matcher(text);
            while (a.find()) {
                String sym  = a.group(1);          // e.g., sBulbasaurLevelUpLearnset
                String body = a.group(2);

                List<LearnMove> list = new ArrayList<>();
                Matcher m = MOVE.matcher(body);
                while (m.find()) {
                    int lvl = Integer.parseInt(m.group(1));
                    String move = tidyMove(m.group(2));   // already without MOVE_
                    list.add(new LearnMove(lvl, move));
                }

                // merge if the same symbol shows up in another file
                out.computeIfAbsent(sym, k -> new ArrayList<>()).addAll(list);
            }
        }

        // sort + dedup per symbol
        for (List<LearnMove> ls : out.values()) {
            ls.sort(Comparator.comparingInt(LearnMove::level).thenComparing(LearnMove::move));
            // dedup identical (level, move) pairs
            List<LearnMove> dedup = new ArrayList<>();
            LearnMove prev = null;
            for (LearnMove lm : ls) {
                if (prev == null || prev.level() != lm.level() || !prev.move().equals(lm.move())) {
                    dedup.add(lm);
                    prev = lm;
                }
            }
            ls.clear();
            ls.addAll(dedup);
        }

        return out;
    }

    private static String tidyMove(String tokenNoPrefix) {
        String base = tokenNoPrefix.toLowerCase(Locale.ROOT).replace('_', ' ').trim();
        StringBuilder sb = new StringBuilder(base.length());
        boolean up = true;
        for (char c : base.toCharArray()) {
            if (Character.isLetter(c)) { sb.append(up ? Character.toUpperCase(c) : c); up = false; }
            else { sb.append(c); up = Character.isWhitespace(c); }
        }
        return sb.toString();
    }
}
