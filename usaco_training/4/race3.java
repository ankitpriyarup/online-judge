/*
ID: rednano1
PROG: race3
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class race3 {
    private static int p(boolean b) {
        return b ? 1 : 0;
    }

    private static void bfs(int start, int exclude, int end, boolean[] reachable, List<Integer>[] graph) {
        final Queue<Integer> q = new LinkedList<Integer>();
        q.add(start);
        Arrays.fill(reachable, false);
        reachable[start] = true;

        while (!q.isEmpty()) {
            final int cur = q.poll();
            if (cur == end)
                continue;

            for (int next : graph[cur]) {
                if (next == exclude || reachable[next])
                    continue;

                reachable[next] = true;
                q.add(next);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        final boolean[][] reachable = new boolean[55][55];
        final List<Integer>[] graph = new List[55];

        final BufferedReader bf = new BufferedReader(new FileReader(new File("race3.in")));
        final PrintWriter pw = new PrintWriter(new File("race3.out"));

        for (int i = 0; i < 55; ++i) {
            graph[i] = new ArrayList<Integer>();
        }

        // read input
        int n = 0;
        while (true) {
            final StringTokenizer st = new StringTokenizer(bf.readLine());
            int dest = -2;
            while (st.hasMoreTokens()) {
                dest = Integer.parseInt(st.nextToken(), 10);
                if (dest < 0)
                    break;
                graph[n].add(dest);
            }
            if (dest == -1)
                break;
            n += 1;
        }
        --n;

        for (int i = 1; i < n; i++) {
            bfs(0, i, n, reachable[i], graph);
        }

        //System.out.println(graph[2]);
        final List<Integer> unavoidable = new ArrayList<Integer>();
        final List<Integer> splitable = new ArrayList<Integer>();
        for (int i = 1; i < n; i++) {
            if (!reachable[i][n]) {
                unavoidable.add(i);
                final boolean[] part1 = new boolean[55];
                final boolean[] part2 = new boolean[55];
                bfs(0, n + 1, i, part1, graph);
                bfs(i, n + 1, n, part2, graph);

                //System.out.println("Trying " + i);
                boolean split = true;
                for (int j = 0; j <= n; ++j) {
                    if (j != i && part1[j] && part2[j]) {
                        split = false;
                    }
                    //System.out.print(p(part1[j]) + " ");
                }
                /*
                System.out.println();
                for (int j = 0; j <= n; ++j) {
                    System.out.print(p(part2[j]) + " ");
                }
                System.out.println();
                */

                if (split) {
                    splitable.add(i);
                }
            }
        }

        pw.print(unavoidable.size());
        for (int x : unavoidable) {
            pw.print(" " + x);
        }
        pw.println();

        pw.print(splitable.size());
        for (int x : splitable) {
            pw.print(" " + x);
        }
        pw.println();

        pw.close();
    }
}
