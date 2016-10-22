import java.io.*;
import java.util.*;

public class UCV2013A {
    private static final long MOD = 1000000007;

    /**
     * Computes base^exp modulo MOD
     */
    public static long fastExp(long base, long exp) {
        if (exp == 0) {
            return 1;
        } else {
            long ans = 1;
            long basePower = base; // base^k
            for (long k = 1; k <= exp; k <<= 1) {
                if ((exp & k) > 0) {
                    ans *= basePower;
                    ans %= MOD;
                }

                basePower *= basePower;
                basePower %= MOD;
            }

            return ans;
        }
    }

    /**
     * Compute the inverse of a number modulo m
     *
     * Input cannot be zero, and must be coprime to m.
     */
    public static long inverse(long a, long m) {
        // The current and previous values in our GCD chain
        long x0 = 0;
        long x1 = 1;

        long t;

        // Iterative Euclidean Algorithm
        while (a > 1) {
            // quotient
            long q = a / m;

            t = m;
            m = a % m;
            a = t;

            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        return ((x1 + MOD) % MOD);
    }

    public static long solve(long N, long L) {
        // Answer is N^1 + N^2 + N^3 + ... + N^L

        // Sum               = N^1 + N^2 + N^3 + ... + N^L
        // Sum * N           = N^2 + N^3 + N^4 + ... + N^(L + 1)
        // Sum * N + N       = N + N^2 + N^3 + N^4 + ... + N^(L + 1)
        // Sum * N + N       = Sum + N^(L + 1)
        // Sum * (N - 1) + N = N^(L + 1)
        // Sum               = (N^(L + 1) - N) / (N - 1)

        long numerator = fastExp(N, L + 1) - N;
        // Any time a value can be negative in a mod problem, fix it ASAP
        // For example 3^4 (mod 10) = 1. Subtract 3 to get -2.
        numerator += MOD;
        numerator %= MOD;

        long denominatorInv = inverse(N - 1, MOD);

        return (numerator * denominatorInv) % MOD;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(bufferedReader.readLine());
            int N = Integer.parseInt(st.nextToken());
            int L = Integer.parseInt(st.nextToken());
            if (N == 0 && L == 0) {
                break;
            }

            System.out.println(solve(N, L));
        }
    }
}
