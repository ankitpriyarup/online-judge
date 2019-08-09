import java.io.*;
import java.util.*;

public class BusyBoard {
    public static boolean canMake(char[][] start, char[][] finish) {
        int r = start.length;
        int c = start[0].length;
        // frequency for finish 
        int[] rowFreq = new int[r];
        int[] colFreq = new int[c];
        int same = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                same += (start[i][j] == finish[i][j]) ? 1 : 0;
                if (finish[i][j] == 'X') {
                    ++rowFreq[i];
                    ++colFreq[j];
                }
            }
        }

        if (same == r * c) {
            return true;
        }

        // Consider the kinds of changes:
        // X -> X: tranfers no hit from row / col. This can't propagate because
        // of the two rule. Can't go row -> col -> row because then you'd
        // already have 2
        //
        // X -> O: must be able ta hit row or col
        // O -> X: must be able to hit row AND col
        // O -> O: no info. :(
        boolean[] canHitRow = new boolean[r];
        boolean[] canHitCol = new boolean[c];
        for (int i = 0; i < r; ++i) {
            canHitRow[i] = rowFreq[i] < 2;
        }
        for (int j = 0; j < c; ++j) {
            canHitCol[j] = colFreq[j] < 2;
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (start[i][j] == 'X' && finish[i][j] == 'X') {
                    if (!canHitRow[i]) {
                        canHitCol[j] = false;
                    }
                    if (!canHitCol[j]) {
                        canHitRow[i] = false;
                    }
                }
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!canHitRow[i] && !canHitCol[j] && start[i][j] != finish[i][j]) {
                    return false;
                }
                if (start[i][j] == 'O' && finish[i][j] == 'X' && (!canHitRow[i] || !canHitCol[j])) {
                    return false;
                }
            }
        }

        // If we satisfy all of those, is it always possible?
        // almost
        // we know at this point at least one thing changed, so there has to be
        // some "last x" that we hit
        // we also know that of the X we need to create, there's at most 1 per
        // row and column, so they don't affect each other
        // general strategy: pop everything up, then push down the Xs we need
        // Basically, ensure that there's at least one X in the hittable area, and one
        // o so we can start this procesgs
        int oCount = 0;
        int xCount = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (canHitRow[i] && canHitCol[j] && finish[i][j] == 'X') {
                    xCount += 1;
                }
                if (canHitRow[i] && canHitCol[j] && start[i][j] == 'O') {
                    oCount += 1;
                }
            }
        }

        return xCount > 0 && oCount > 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        char[][] start = new char[r][];
        char[][] finish = new char[r][];

        for (int i = 0; i < r; ++i) {
            start[i] = br.readLine().toCharArray();
        }

        for (int i = 0; i < r; ++i) {
            finish[i] = br.readLine().toCharArray();
        }

        System.out.println(canMake(start, finish) ? 1 : 0);
    }
}
