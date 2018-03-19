import java.awt.Point;
import java.io.*;
import java.util.*;
import java.math.*;

public class GenRecFunc {
    static final BigInteger MINUS_ONE = new BigInteger("-1");
    public static BigInteger solve(BigInteger[][] memo, List<Integer> a, List<Integer> b, BigInteger c, BigInteger d, int x, int y) {
        if (x <= 0 || y <= 0)
            return d;

        if (!memo[x][y].equals(MINUS_ONE)) {
            return memo[x][y];
        }

        memo[x][y] = c;
        for (int i = 0; i < a.size(); i++) {
            memo[x][y] = memo[x][y].add(solve(memo, a, b, c, d, x - a.get(i), y - b.get(i)));
        }

        return memo[x][y];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<Integer> a = new ArrayList<>();
            List<Integer> b = new ArrayList<>();
            while (st.hasMoreTokens()) {
                a.add(Integer.parseInt(st.nextToken()));
                b.add(Integer.parseInt(st.nextToken()));
            }

            BigInteger c = new BigInteger(Integer.toString(a.remove(a.size() - 1)));
            BigInteger d = new BigInteger(Integer.toString(b.remove(b.size() - 1)));

            BigInteger[][] memo = new BigInteger[102][102];
            for (int i = 0; i < 102; i++) {
                Arrays.fill(memo[i], MINUS_ONE);
            }

            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                System.out.println(solve(memo, a, b, c, d, x, y));
            }

            System.out.println();
        }
    }
}
