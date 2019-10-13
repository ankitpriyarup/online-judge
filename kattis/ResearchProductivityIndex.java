import java.io.*;
import java.util.*;

public class ResearchProductivityIndex {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        double[] p = new double[n];
        for (int i = 0; i < n; i++) {
            p[i] = scan.nextInt() / 100.0;
        }
        Arrays.sort(p);

        double ans = 0.0;
        // dp[i] = probability of getting exactly i papers accepted
        double[] dp = new double[n + 1];
        dp[0] = 1.0;
        for (int s = 1; s <= n; ++s) {
            for (int i = n - 1; i >= 0; --i) {
                dp[i + 1] += p[n - s] * dp[i];
                dp[i] *= (1.0 - p[n - s]);
            }

            double cur = 0.0;
            for (int a = 1; a <= s; ++a) {
                double value = Math.pow(a, ((double) a) / s);
                cur += value * dp[a];
            }

            ans = Math.max(ans, cur);
        }

        System.out.printf("%.9f%n", ans);
    }
}
