import java.io.*;
import java.util.*;
import java.math.*;

public class Absurdistan2 {
    final static int MAXN = 141;
    static BigInteger[] fact;

    public static void genFact() {
        fact = new BigInteger[MAXN];
        fact[0] = fact[1] = BigInteger.ONE;
        for (int i = 2; i < MAXN; ++i) {
            fact[i] = BigInteger.valueOf(i).multiply(fact[i - 1]);
        }
    }

    public static BigInteger choose(int n, int r) {
        if (r < 0 || r > n || n < 0)
            return BigInteger.ZERO;

        BigInteger ret = fact[n];
        ret = ret.divide(fact[r]);
        ret = ret.divide(fact[n - r]);

        return ret;
    }

    public static double solve(int n) {
        BigInteger[] ways = new BigInteger[n + 1];
        ways[0] = ways[1] = BigInteger.ZERO;

        for (int k = 2; k <= n; ++k) {
            // The total number of ways to lay pipe is
            // (k - 1)^k (all k cities have k - 1 options).
            BigInteger base = BigInteger.valueOf(k);
            BigInteger total = base.subtract(BigInteger.ONE).pow(k);

            // Now, let's say node 1 is in a connected subgraph of size
            // less than k. Then if we enumerate all of these sizes
            // and subtract by total, we have our answer!
            BigInteger bad = BigInteger.ZERO;

            for (int subgraph = 2; subgraph < k; ++subgraph) {
                // How many ways are there to create this split?
                // First, there are (k - 1) choose (subgraph - 1) ways to
                // choose friends for node 1. Then multiply by the number
                // of valid ways to connect all of them.
                //
                // Then, every other node can go do whatever it wants, so
                // (k - subgraph - 1)^(k - subgraph) additional options

                BigInteger cur = ways[subgraph];
                cur = cur.multiply(choose(k - 1, subgraph - 1));

                BigInteger rest = base.subtract(BigInteger.valueOf(subgraph));
                cur = cur.multiply(rest.subtract(BigInteger.ONE).pow(k - subgraph));

                bad = bad.add(cur);
            }

            ways[k] = total.subtract(bad);
            // System.out.println(k + " " + ways[k] + " " + total);
        }

        BigDecimal base = BigDecimal.valueOf(n);
        BigDecimal denom = base.subtract(BigDecimal.ONE).pow(n);
        
        BigDecimal ret = new BigDecimal(ways[n]).divide(denom, MathContext.DECIMAL128);

        return ret.doubleValue();
    }

    public static void main(String[] args) throws IOException {
        genFact();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        System.out.println(solve(n));
    }
}
