import java.io.*;
import java.util.*;

public class Six {
    public static final long MAX = 21474837000L;

    public static void main(String[] args) throws IOException {
        final BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        final int T = Integer.parseInt(bf.readLine());

        for (int case_num = 1; case_num <= T; case_num++) {
            final StringTokenizer st = new StringTokenizer(bf.readLine());

            final int d = Integer.parseInt(st.nextToken());
            final int N = Integer.parseInt(st.nextToken());

            final Map<Integer, Set<Long>> tools = new HashMap<>();

            long val = d;
            boolean solved = false;
            int ans = -1;
            for (int level = 1; level <= 11; level++) {
                tools.put(level, new HashSet<Long>());
                tools.get(level).add(val);

                if (val == N) {
                    solved = true;
                    ans = level;
                    break;
                }

                val *= 10;
                val += d;
            }

            if (solved) {
                System.out.println("Case " + case_num + ": " + ans);
                continue;
            }

            for (int level = 2; !solved && level <= 11; level++) {
                for (int i = 1; !solved && i < level; i++) {
                    final Set<Long> first = tools.get(i);
                    final Set<Long> second = tools.get(level - i);

                    for (long x : first) {
                        for (long y : second) {
                            final List<Long> vals = new ArrayList<>(Arrays.asList(x + y, x - y, y - x, x * y));
                            if (y != 0 && x % y == 0) {
                                vals.add(x / y);
                            }

                            if (x != 0 && y % x == 0) {
                                vals.add(y / x);
                            }

                            for (long v : vals) {
                                if (v == N) {
                                    solved = true;
                                    ans = level;
                                    break;
                                }

                                tools.get(level).add(v);
                            }

                            if (solved) {
                                break;
                            }
                        }

                        if (solved) {
                            break;
                        }
                    }
                }
            }

            /*
            for (int i = 1; i < 10; i++) {
                System.out.println("LEVEL " + i + "\n\n");
                System.out.println(tools.get(i));
            }
            */
            System.out.println("Case " + case_num + ": " + ans);
        }
    }
}
