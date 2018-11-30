import java.io.*;
import java.util.*;

public class HeirsDilemma {
    public static int[] ans = {123648, 123864, 123984, 124368, 126384, 129384, 132648, 132864, 132984, 134928, 136248, 136824, 138264, 138624, 139248, 139824, 142368, 143928, 146328, 146832, 148392, 148632, 149328, 149832, 162384, 163248, 163824, 164328, 164832, 167328, 167832, 168432, 172368, 183264, 183624, 184392, 184632, 186432, 189432, 192384, 193248, 193824, 194328, 194832, 198432, 213648, 213864, 213984, 214368, 216384, 218736, 219384, 231648, 231864, 231984, 234168, 234816, 236184, 238416, 239184, 241368, 243168, 243768, 243816, 247968, 248136, 248976, 261384, 263184, 273168, 281736, 283416, 284136, 291384, 293184, 297864, 312648, 312864, 312984, 314928, 316248, 316824, 318264, 318624, 319248, 319824, 321648, 321864, 321984, 324168, 324816, 326184, 328416, 329184, 341928, 342168, 342816, 346128, 348192, 348216, 348912, 349128, 361248, 361824, 361872, 362184, 364128, 364728, 367248, 376824, 381264, 381624, 382416, 384192, 384216, 384912, 391248, 391824, 392184, 394128, 412368, 413928, 416328, 416832, 418392, 418632, 419328, 419832, 421368, 423168, 423816, 427896, 428136, 428736, 431928, 432168, 432768, 432816, 436128, 438192, 438216, 438912, 439128, 461328, 461832, 463128, 468312, 469728, 478296, 478632, 481392, 481632, 482136, 483192, 483216, 483672, 483912, 486312, 489312, 491328, 491832, 493128, 498312, 612384, 613248, 613824, 613872, 614328, 614832, 618432, 621384, 623184, 623784, 627984, 631248, 631824, 632184, 634128, 634872, 641328, 641832, 643128, 648312, 671328, 671832, 681432, 684312, 689472, 732648, 732816, 742896, 746928, 762384, 768432, 783216, 789264, 796824, 813264, 813624, 814392, 814632, 816432, 819432, 823416, 824136, 824376, 831264, 831624, 832416, 834192, 834216, 834912, 836472, 841392, 841632, 842136, 843192, 843216, 843912, 846312, 849312, 861432, 864312, 873264, 891432, 894312, 897624, 912384, 913248, 913824, 914328, 914832, 918432, 921384, 923184, 927864, 931248, 931824, 932184, 934128, 941328, 941832, 943128, 948312, 976248, 978264, 981432, 984312};
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        int l = in.nextInt();
        int r = in.nextInt();
        int p = 0;
        int out = 0;
        int len = ans.length;

        for (int x = l; p < ans.length && x <= r; x++) {
            while (p < len && ans[p] < x)
                ++p;
            if (p < len && ans[p] == x)
                ++out;
        }
        System.out.println(out);
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
