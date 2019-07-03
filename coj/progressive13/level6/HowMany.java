import java.io.*;
import java.util.*;
import java.math.*;

public class HowMany {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());

        BigInteger TWO = new BigInteger("2");
        BigInteger FIVE = new BigInteger("5");

        int[][][] dp = new int[2][5001][10];
        dp[0][0][1] = 1;
        dp[1][0][1] = 1;

        BigInteger cur = new BigInteger("2");
        for (int i = 1; i <= 5000; ++i) {
            for (char c : cur.toString().toCharArray()) {
                ++dp[0][i][c - '0'];
            }
            cur = cur.multiply(TWO);
        }

        cur = new BigInteger("5");
        for (int i = 1; i <= 5000; ++i) {
            for (char c : cur.toString().toCharArray()) {
                ++dp[1][i][c - '0'];
            }
            cur = cur.multiply(FIVE);
        }

        while (T-- > 0) {
            int[] res = new int[10];
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Math.min(a, b);
            res[0] += c;
            a -= c;
            b -= c;

            if (a > 0) {
                for (int j = 0; j < 10; ++j) {
                    res[j] += dp[0][a][j];
                }
            } else {
                for (int j = 0; j < 10; ++j) {
                    res[j] += dp[1][b][j];
                }
            }

            int tot = 0;
            for (int i = 0; i < 10; ++i) {
                pw.println(res[i]);
                tot += res[i];
            }
            pw.println(tot);
        }

        pw.close();
    }
}
