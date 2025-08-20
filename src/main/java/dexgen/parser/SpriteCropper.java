package dexgen.parser;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.Graphics2D;
import java.awt.Transparency;
import java.io.File;
import java.io.IOException;
import java.nio.file.*;
import java.util.stream.Stream;

public final class SpriteCropper {
    public static void main(String[] args) throws Exception {
        // Usage: java SpriteCropper [rootDir=exiled-dex/assets/pokemon] [w=64] [h=64] [dryRun=false] [backup=true]
        final Path root = Paths.get(args.length > 0 ? args[0] : "exiled-dex/assets/pokemon");
        final int targetW = args.length > 1 ? Integer.parseInt(args[1]) : 64;
        final int targetH = args.length > 2 ? Integer.parseInt(args[2]) : 64;
        final boolean dryRun = args.length > 3 && Boolean.parseBoolean(args[3]);
        final boolean backup = args.length > 4 ? Boolean.parseBoolean(args[4]) : true;

        if (!Files.isDirectory(root)) {
            System.err.println("Not a directory: " + root.toAbsolutePath());
            System.exit(1);
        }

        try (Stream<Path> paths = Files.walk(root)) {
            paths.filter(p -> p.getFileName().toString().equals("anim_front.png"))
                    .forEach(p -> {
                        try { processOne(p, targetW, targetH, dryRun, backup); }
                        catch (Exception e) { System.err.println("FAIL " + p + " -> " + e.getMessage()); }
                    });
        }
        System.out.println("Done.");
    }

    private static void processOne(Path animPath, int targetW, int targetH, boolean dryRun, boolean backup) throws IOException {
        BufferedImage src = ImageIO.read(animPath.toFile());
        if (src == null) { System.err.println("Skip (unreadable): " + animPath); return; }

        int w = src.getWidth();
        int h = src.getHeight();

        // If the sprite is the tall 64x128 (or any >= targetH*2), crop top targetH rows.
        int cropW = Math.min(w, Math.max(targetW, 1));
        int cropH = Math.min(h, targetH);
        int sx = 0;
        int sy = 0; // top

        BufferedImage cropped = new BufferedImage(cropW, cropH, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = cropped.createGraphics();
        cropped = g.getDeviceConfiguration().createCompatibleImage(cropW, cropH, Transparency.TRANSLUCENT);
        g.dispose();
        g = cropped.createGraphics();
        g.drawImage(src, 0, 0, cropW, cropH, sx, sy, sx + cropW, sy + cropH, null);
        g.dispose();

        // If the crop width isn’t the target width, scale to targetW×targetH (keeps pixel art sharp)
        BufferedImage out = cropped;
        if (cropW != targetW || cropH != targetH) {
            BufferedImage scaled = new BufferedImage(targetW, targetH, BufferedImage.TYPE_INT_ARGB);
            Graphics2D gs = scaled.createGraphics();
            // nearest-neighbor
            gs.setRenderingHint(java.awt.RenderingHints.KEY_INTERPOLATION,
                    java.awt.RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR);
            gs.drawImage(cropped, 0, 0, targetW, targetH, 0, 0, cropW, cropH, null);
            gs.dispose();
            out = scaled;
        }

        if (dryRun) {
            System.out.println("DRY " + animPath + " [" + w + "x" + h + "] -> [" + out.getWidth() + "x" + out.getHeight() + "]");
            return;
        }

        if (backup) {
            Path bak = animPath.resolveSibling(animPath.getFileName().toString() + ".bak");
            if (!Files.exists(bak)) Files.copy(animPath, bak);
        }

        ImageIO.write(out, "PNG", animPath.toFile());
        System.out.println("OK  " + animPath + " [" + w + "x" + h + "] -> [" + out.getWidth() + "x" + out.getHeight() + "]");
    }
}
