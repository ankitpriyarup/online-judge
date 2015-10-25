import java.io.*;
import java.util.*;
import java.awt.Point;

public class Run {
    public static int[] dx8 = {1, 1, 1, 0, -1, -1, -1, 0};
    public static int[] dy8 = {1, 0, -1, -1, -1, 0, 1, 1};
    public static int N, M;
    public static int[][] grid;
    public static boolean[][] isLava;

    public static Set<Point> moveTwice(Point start) {
        final Set<Point> once = new HashSet<>();
        for (int d = 0; d < 8; ++d) {
            int nx = start.x + dx8[d];
            int ny = start.y + dy8[d];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] - grid[start.x][start.y] <= 1 && !isLava[nx][ny]) {
                once.add(new Point(nx, ny));
            }
        }

        final Set<Point> twice = new HashSet<>();
        for (Point o : once) {
            for (int d = 0; d < 8; ++d) {
                int nx = o.x + dx8[d];
                int ny = o.y + dy8[d];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] - grid[o.x][o.y] <= 1 && !isLava[nx][ny]) {
                    twice.add(new Point(nx, ny));
                }
            }
        }

        twice.addAll(once);
        return twice;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        final int T = Integer.parseInt(bf.readLine());

        for (int case_num = 1; case_num <= T; case_num++) {
            final StringTokenizer st = new StringTokenizer(bf.readLine());

            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            grid = new int[N][M];
            isLava = new boolean[N][M];
            int max = 0;
            int startx = -1;
            int starty = -1;

            for (int i = 0; i < N; i++) {
                final String s = bf.readLine();

                for (int j = 0; j < M; j++) {
                    isLava[i][j] = false;

                    if ('A' <= s.charAt(j) && s.charAt(j) <= 'Z') {
                        grid[i][j] = s.charAt(j) - 'A' + 10;
                        max = Math.max(max, grid[i][j]);
                    } else {
                        grid[i][j] = s.charAt(j) - '0';
                        max = Math.max(max, grid[i][j]);

                        if (grid[i][j] == 0) {
                            startx = i;
                            starty = j;
                        }
                    }
                }
            }

            // bfs, when reach a new level increase the lava
            final Queue<Point> q = new LinkedList<>();
            final Set<Point> seen = new HashSet<>();
            q.add(new Point(startx, starty));
            int lastDist = 0;
            boolean safe = false;

            while (!safe && !q.isEmpty()) {
                int levelSize = q.size();
                //System.out.println("NEW LEVEL OF SIZE " + levelSize);
                /*
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (isLava[i][j]) {
                            System.out.print('X');
                        } else if (q.contains(new Point(i, j))) {
                            System.out.print('F');
                        } else {
                            System.out.print(grid[i][j]);
                        }
                    }
                    System.out.println();
                }
                */

                while (levelSize-- > 0) {
                    Point cur = q.remove();
                    if (isLava[cur.x][cur.y]) {
                        continue;
                    }

                    //System.out.println("Trying point " + cur);
                    seen.add(cur);

                    if (grid[cur.x][cur.y] == max) {
                        safe = true;
                        break;
                    }

                    Set<Point> next = moveTwice(cur);
                    next.removeAll(seen);
                    q.addAll(next);
                }

                if (safe) {
                    break;
                }

                // handle lava here
                isLava[startx][starty] = true;

                // all lava squares rise by one foot
                boolean cont = true;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (isLava[i][j]) {
                            grid[i][j] += 1;
                        }
                    }
                }

                while (cont) {
                    cont = false;
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < M; j++) {
                            if (isLava[i][j]) {
                                for (int d = 0; d < 8; d++) {
                                    int nx = i + dx8[d];
                                    int ny = j + dy8[d];

                                    if (nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] < grid[i][j] && !isLava[nx][ny]) {
                                        //System.out.printf("(%d, %d) set (%d, %d) on fire\n", i, j, nx, ny);
                                        isLava[nx][ny] = true;
                                        grid[nx][ny] = grid[i][j];
                                        cont = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            System.out.printf("Case %d: ", case_num);
            if (safe) {
                System.out.println("SAFE");
            } else {
                System.out.println("MELTED");
            }
        }
    }
}
