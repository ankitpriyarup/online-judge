import java.io.*;
import java.util.*;

public class Checkers {
    static int k;
    static int n;

    public static int bestScore(State root, int depth) {
        if (depth == 0) {
            return root.score;
        }

        List<State> next = root.getNeighbors('x');
        if (next.isEmpty()) {
            return root.score;
        }

        int ans = Integer.MIN_VALUE;
        for (State state : next) {
            int ret = Integer.MAX_VALUE;
            List<State> neighbors = state.getNeighbors('o');
            if (neighbors.isEmpty()) {
                ans = Math.max(ans, state.score);
                continue;
            }

            for (State grandchild : neighbors) {
                ret = Math.min(ret, bestScore(grandchild, depth - 1));
            }

            ans = Math.max(ans, ret == Integer.MAX_VALUE ? state.score : ret);
        }

        /*
        System.out.println(root);
        System.out.printf("Depth: %d, Ans: %d\n", depth, ans);
        System.out.println();
        */

        return ans == Integer.MIN_VALUE ? root.score : ans;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Integer.parseInt(br.readLine());
        n = Integer.parseInt(br.readLine());
        char[][] grid = new char[n][n];

        for (int i = 0; i < n; ++i) {
            grid[i] = br.readLine().toCharArray();
        }

        State start = new State(grid);

        int ans = bestScore(start, k);
        System.out.println(ans);
    }

    public static class State {
        int[] dx = {1, 1, -1, -1};
        int[] dy = {1, -1, 1, -1};
        char[][] grid;
        int score;

        public State(char[][] grid) {
            this.grid = new char[n][n];
            this.score = 0;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    this.grid[i][j] = grid[i][j];

                    if (this.grid[i][j] == 'o') {
                        this.score--;
                    } else if (this.grid[i][j] == 'x') {
                        this.score++;
                    }
                }
            }
        }

        public static boolean inBounds(int x, int y) {
            return 0 <= x && x < n && 0 <= y && y < n;
        }

        public static char[][] deepCopy(char[][] arr) {
            char[][] ret = new char[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ret[i][j] = arr[i][j];
                }
            }

            return ret;
        }

        public List<State> getNeighbors(char player) {
            List<State> ret = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] != player) {
                        continue;
                    }

                    for (int d = 0; d < 4; ++d) {
                        int x = i + dx[d];
                        int y = j + dy[d];
                        if (inBounds(x, y)) {
                            if (grid[x][y] == '*') {
                                char[][] copy = deepCopy(grid);
                                copy[i][j] = '*';
                                copy[x][y] = player;

                                ret.add(new State(copy));
                            } else if (grid[x][y] != player) {
                                int nx = i + 2 * dx[d];
                                int ny = j + 2 * dy[d];
                                if (inBounds(nx, ny) && grid[nx][ny] == '*') {
                                    char[][] copy = deepCopy(grid);
                                    copy[i][j] = '*';
                                    copy[x][y] = '*';
                                    copy[nx][ny] = player;

                                    ret.add(new State(copy));
                                }
                            }
                        }
                    }
                }
            }

            return ret;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    sb.append(grid[i][j]);
                }
                sb.append('\n');
            }

            return sb.toString();
        }

        public boolean equals(Object other) {
            return this.toString().equals(other.toString());
        }

        public int hashCode() {
            return this.toString().hashCode();
        }
    }
}
