import java.util.*;
import java.io.*;

public class qdoba {

    public static int toCents(String s) {
        int dotIndex = s.indexOf('.');
        return 100 * Integer.parseInt(s.substring(0, dotIndex)) + Integer.parseInt(s.substring(dotIndex + 1));
    }

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        while (T-- > 0) {
            int N = s.nextInt();
            int M = toCents(s.next());

            int[] items = new int[N];
            for (int i = 0; i < N; i++) {
                items[i] = toCents(s.next());
            }

            boolean[][] dp = new boolean[N][M + 1];
            for (int i = 0; i < N; i++) {
                dp[i][0] = true;
            }

            for(int i = 0; i < N; i++) {
                for(int j = 0; j <= M; j++) {
                    if(i > 0) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                    if (j >= items[i]) {
                        dp[i][j] |= dp[i][j - items[i]];
                    }
                }
            }

            System.out.println((dp[N - 1][M] ? "YES" : "NO"));
        }
    }
}
