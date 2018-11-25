import java.io.*;
import java.util.*;

public class UniqueDice {
    private static final int MAX_ID = 6 * 6 * 6 * 6 * 6 * 6;

    public static int getId(int[] faces) {
        int id = 0;
        for (int i = 0; i < 6; ++i) {
            id = faces[i] + 6 * id;
        }

        return id;
    }

    public static int find(int[] dsu, int x) {
        if (dsu[x] == x) {
            return x;
        } else {
            int res = find(dsu, dsu[x]);
            dsu[x] = res;
            return res;
        }
    }

    public static void merge(int[] dsu, int x, int y) {
        int xr = find(dsu, x);
        int yr = find(dsu, y);
        if (xr == yr) {
            return;
        }
        dsu[xr] = yr;
    }

    private static int[] generateDice() {
        int[] dsu = new int[MAX_ID];
        for (int i = 0; i < MAX_ID; ++i) {
            dsu[i] = i;
        }

        for (int a = 0; a < 6; ++a) {
            for (int b = 0; b < 6; ++b) {
                for (int c = 0; c < 6; ++c) {
                    for (int d = 0; d < 6; ++d) {
                        for (int e = 0; e < 6; ++e) {
                            for (int f = 0; f < 6; ++f) {
                                int[] faces = new int[]{a, b, c, d, e, f};
                                int[] rotA = new int[]{d, c, a, b, e, f};
                                int[] rotB = new int[]{a, b, e, f, d, c};
                                int faceId = getId(faces);
                                merge(dsu, faceId, getId(rotA));
                                merge(dsu, faceId, getId(rotB));
                            }
                        }
                    }
                }
            }
        }

        return dsu;
    }

    public static void main(String[] args) throws IOException {
        // Horrible idea: generate all dice, use disjoint set
        InputReader in = new InputReader(System.in);
        int[] dsu = generateDice();

        int n = in.nextInt();
        int[] freq = new int[MAX_ID];
        for (int i = 0; i < n; i++) {
            int[] faces = in.nextIntArray(6);
            for (int j = 0; j < 6; ++j) {
                --faces[j];
            }

            int x = find(dsu, getId(faces));
            ++freq[x];
        }

        int ans = 0;
        for (int i = 0; i < MAX_ID; i++) {
            ans = Math.max(ans, freq[i]);
        }
        System.out.println(ans);
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
