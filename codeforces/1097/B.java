import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(br.readLine());
        }

        // f[i][j] = can we make sum j using the first i elements?
        boolean[][] f = new boolean[n + 1][360];
        // we can only make sum 0 using no elements.
        f[0][0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 360; ++j) {
                if (f[i][j]) {
                    // sign = -1, 1
                    for (int sign = -1; sign <= 1; sign += 2) {
                        int new_sum = (j + 360 + sign * a[i]) % 360;
                        f[i + 1][new_sum] = true;
                    }
                }
            }
        }

        System.out.println(f[n][0] ? "YES" : "NO");
    }
}
