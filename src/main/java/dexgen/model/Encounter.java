// dexgen/model/Encounter.java
package dexgen.model;
public record Encounter(
        String areaKey,
        String bucketKey,
        String area,
        String bucket,
        Integer rateBase, int min, int max, int slot) {}
