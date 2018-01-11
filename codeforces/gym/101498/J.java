import java.io.*;
import java.util.*;

public class J {
    public static boolean works(List<Integer> ls, int len) {
        int cur = 0;
        for (int x : ls) {
            if (cur == 0) {
                cur += x;
            } else {
                cur += 1 + x;
            }

            if (cur == len) {
                cur = 0;
            } else if (cur > len) {
                return false;
            }
        }

        return cur == 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int qq = Integer.parseInt(br.readLine());
        while (qq-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<Integer> ls = new ArrayList<>();
            int sum = 0;

            while (st.hasMoreTokens()) {
                int x = st.nextToken().length();
                ls.add(x);
                sum += x;
            }

            boolean flag = false;
            for (int lines = 2; lines <= sum; ++lines) {
                int line_length = ls.size() - lines + sum;
                if (line_length % lines != 0) {
                    continue;
                }

                line_length /= lines;

                if (works(ls, line_length)) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
