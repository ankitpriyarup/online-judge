import java.io.*;
import java.util.*;

public class DiagonalCut {
    private static long gcd(long a, long b) {
        return b > 0 ? gcd(b, a % b) : a;
    }

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        long n = scan.nextLong();
        long m = scan.nextLong();

        // number of corner points is gcd(n, m)
        // use inclusion exclusion: 
        // doubled corner points - edge 1 - edge 2 + both edges
        long ans = gcd(2 * n, 2 * m) - gcd(2 * n, m) - gcd(n, 2 * m) + gcd(n, m);

        System.out.println(ans);
    }
}
