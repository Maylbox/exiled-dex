package dexgen;

import dexgen.model.Encounter;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import java.nio.file.*; import java.util.*;

public final class TranslationIO {
    private TranslationIO() {}

    /** Writes data/i18n/areas.template.json with all area/bucket keys and empty values. */
    public static void writeAreaBucketSkeleton(Map<String, List<Encounter>> encBySpecies, Path dataOut) throws Exception {
        Set<String> areaKeys   = new TreeSet<>();
        Set<String> bucketKeys = new TreeSet<>();
        for (var list : encBySpecies.values()) {
            for (var e : list) {
                areaKeys.add(e.areaKey());
                bucketKeys.add(e.bucketKey());
            }
        }
        Map<String,Object> root = new LinkedHashMap<>();
        root.put("lang", "TEMPLATE"); // change to "en", "nl" when you fill it
        root.put("area",   toEmptyMap(areaKeys));
        root.put("bucket", toEmptyMap(bucketKeys));

        Path i18nDir = dataOut.resolve("i18n");
        Files.createDirectories(i18nDir);
        var M = new ObjectMapper().enable(SerializationFeature.INDENT_OUTPUT);
        M.writeValue(i18nDir.resolve("areas.template.json").toFile(), root);
    }

    private static Map<String,String> toEmptyMap(Set<String> keys){
        Map<String,String> m = new LinkedHashMap<>();
        for (String k : keys) m.put(k, ""); // leave empty for you to fill
        return m;
    }
}
