import java.awt.Point;
import java.io.*;
import java.util.*;

public class brkstring {
    public static void main(String[] args) throws Exception {
        StringBuilder sb = new StringBuilder();
        InputReader in = new InputReader(System.in);
        try {
            while (true) {
                int n = in.nextInt();
                int m = in.nextInt();
                ++m;
                int[] a = new int[m + 1];
                long[][] dp = new long[m][m + 1];
                int[][] opt = new int[m][m + 1];
                a[0] = 0;
                for (int i = 1; i < m; ++i) {
                    a[i] = in.nextInt();
                    dp[i][i + 1] = 0;
                    opt[i][i + 1] = i;
                }
                a[m] = n;

                for (int len = 2; len <= m; ++len) {
                    for (int i = 0; i + len <= m; ++i) {
                        dp[i][i + len] = 987654321;
                        int lo = opt[i][i + len - 1];
                        int hi = opt[i + 1][i + len];
                        int cost = a[i + len] - a[i];
                        for (int k = lo; k <= hi; ++k) {
                            long new_cost = dp[i][k] + dp[k][i + len] + cost;
                            if (new_cost < dp[i][i + len]) {
                                dp[i][i + len] = new_cost;
                                opt[i][i + len] = k;
                            }
                        }
                    }
                }

                sb.append(dp[0][m]);
                sb.append('\n');
            }
        } catch (InputMismatchException e) {
        }
        System.out.print(sb.toString());
    }

    static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int snext() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public String readString() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = snext();
            while (isSpaceChar(c))
                c = snext();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

}
