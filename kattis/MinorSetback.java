import java.io.*;
import java.util.*;

public class MinorSetback {
    // 0 1  2 3 4  5 6  7 8 9  a b
    // A A# B C C# D D# E F F# G G#
    private static final int[][] scales = new int[][]{
        {10, 0, 2, 3, 5, 7, 9},
        {3, 5, 7, 8, 10, 0, 2},
        {6, 8, 10, 11, 1, 3, 5},
        {9, 11, 0, 2, 4, 5, 7},
        {10, 0, 1, 3, 5, 6, 8}
    };

    private static final String[][] scaleNotes = new String[][]{
        {"G", "A", "B", "C", "D", "E", "F#"},
        {"C", "D", "E", "F", "G", "A", "B"},
        {"Eb", "F", "G", "Ab", "Bb", "C", "D"},
        {"F#", "G#", "A", "B", "C#", "D", "E"},
        {"G", "A", "Bb", "C", "D", "Eb", "F"},
    };

    private static final String[] scaleNames = new String[]{
        "G major",
        "C major",
        "Eb major",
        "F# minor",
        "G minor"
    };

    private static int[] classify(double[] freqs) {
        // 440 * 2^x/12 = y
        // 2^(x/12) = y / 440
        // x / 12 = log(y) - log(440)
        // x = 12 (log(y) - log(440))
        double[] tones = new double[12];
        for (int i = 0; i < 12; i++) {
            tones[i] = 440.0 * Math.pow(2.0, i / 12.0);
        }

        int[] notes = new int[freqs.length];
        for (int i = 0; i < freqs.length; i++) {
            double freq = freqs[i];
            while (freq < 440.0) {
                freq *= 2.0;
            }
            while (freq >= 880.0) {
                freq /= 2.0;
            }

            int note = 0;
            double noteDist = Math.abs(tones[0] - freq);
            for (int j = 0; j < 12; j++) {
                double curDist = Math.abs(tones[j] - freq);
                if (curDist < noteDist) {
                    note = j;
                    noteDist = curDist;
                }
            }

            notes[i] = note;
        }

        return notes;
    }

    private static int[] aggregate(int[] notes) {
        int[] counts = new int[12];
        for (int note : notes) {
            counts[note]++;
        }

        return counts;
    }

    private static int findScale(int n, int[] noteCounts) {
        List<Integer> options = new ArrayList<>();
        for (int scale = 0; scale < 5; scale++) {
            int noteCount = 0;
            for (int note : scales[scale]) {
                noteCount += noteCounts[note];
            }

            if (noteCount == n) {
                options.add(scale);
            }
        }

        return options.size() == 1 ? options.get(0) : -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double[] frequencies = new double[n];
        for (int i = 0; i < n; i++) {
            frequencies[i] = Double.parseDouble(br.readLine());
        }
        int[] notes = classify(frequencies);
        int[] noteCounts = aggregate(notes);
        int scale = findScale(n, noteCounts);
        if (scale == -1) {
            System.out.println("cannot determine key");
            return;
        }

        System.out.println(scaleNames[scale]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 7; j++) {
                if (notes[i] == scales[scale][j]) {
                    System.out.println(scaleNotes[scale][j]);
                }
            }
        }
    }
}
