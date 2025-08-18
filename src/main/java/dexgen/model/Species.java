package dexgen.model;

import java.util.List;
import java.util.Map;

public record Species(
        int dex,
        String speciesId,
        String name,
        List<String> types,
        List<String> abilities,
        Map<String,Integer> evYield,
        Double malePct,
        Double femalePct,
        int catchRate,
        int baseExp,
        List<String> eggGroups,
        int hatchSteps,
        double heightM,
        double weightKg,
        String growthRate,
        String color,
        String category,
        Integer friendship,
        String description,
        String preEvolutionId,
        List<Evo> evolution,
        Map<String,Integer> baseStats,
        Map<String,String> heldItems,
        List<LearnMove> levelUpMoves,
        List<String> eggMoves,
        List<String> teachableMoves,
        List<Encounter> encounters
) {}
