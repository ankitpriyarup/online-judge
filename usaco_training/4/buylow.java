/*
ID: rednano1
PROG: buylow
LANG: JAVA
*/
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class buylow {
    public static void main(String[] args) throws IOException {
        final Scanner scan = new Scanner(new File("buylow.in"));
        final PrintWriter pw = new PrintWriter(new File("buylow.out"));

        final int n = scan.nextInt();
        final int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
        }
        scan.close();

        int bestLength = 1;
        final int[] dp1 = new int[n];
        final BigInteger[] dp2 = new BigInteger[n];

        for (int i = 0; i < n; i++) {
            int length = 1;
            dp2[i] = BigInteger.ONE;
            BigInteger count = BigInteger.ONE;
            final Set<Integer> previous = new HashSet<Integer>();

            for (int j = i - 1; j >= 0; --j) {
                if (a[i] < a[j] && length < dp1[j] + 1) {
                    length = dp1[j] + 1;
                    count = dp2[j];
                    previous.clear();
                    previous.add(a[j]);
                } else if (a[i] < a[j] && length == dp1[j] + 1 && !previous.contains(a[j])) {
                    count = count.add(dp2[j]);
                    previous.add(a[j]);
                }
            }

            dp1[i] = length;
            dp2[i] = count;
            bestLength = Math.max(bestLength, length);
        }

        BigInteger totalCount = BigInteger.ZERO;
        final Set<Integer> last = new HashSet<Integer>();
        for (int i = n - 1; i >= 0; i--) {
            if (dp1[i] == bestLength && !last.contains(a[i])) {
                totalCount = totalCount.add(dp2[i]);
                last.add(a[i]);
            }
        }

        pw.println(bestLength + " " + totalCount);
        pw.close();

        /*
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < n; i++) {
            System.out.print(dp1[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < n; i++) {
            System.out.print(dp2[i] + " ");
        }
        System.out.println();
        */
    }
}
