import java.awt.Point;
import java.io.*;
import java.util.*;

public class PegSolitaire {
    static final int ROWS = 5;
    static final int COLS = 9;

    static final int[] dx = {1, 0, -1, 0};
    static final int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            char[][] grid = new char[ROWS][COLS];
            for (int i = 0; i < ROWS; i++) {
                grid[i] = br.readLine().toCharArray();
            }

            State start = new State(grid);
            Queue<State> q = new LinkedList<>();
            Set<State> seen = new HashSet<>();
            q.add(start);
            seen.add(start);

            int lvl = 0;
            int minPegs = start.pegs.size();
            int numMoves = 0;

            while (!q.isEmpty()) {
                int sz = q.size();
                while (sz-- > 0) {
                    State cur = q.remove();
                    if (cur.pegs.size() < minPegs) {
                        minPegs = cur.pegs.size();
                        numMoves = lvl;
                    }

                    for (State follow : cur.nextStates()) {
                        if (!seen.contains(follow)) {
                            seen.add(follow);
                            q.add(follow);
                        }
                    }
                }

                lvl++;
            }

            System.out.printf("%d %d\n", minPegs, numMoves);

            if (T > 0) {
                br.readLine();
            }
        }
    }

    public static class State {
        List<Point> pegs;

        public State(char[][] grid) {
            pegs = new ArrayList<>();
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; ++j) {
                    if (grid[i][j] == 'o') {
                        pegs.add(new Point(i, j));
                    }
                }
            }
        }

        public State(List<Point> pegs) {
            this.pegs = new ArrayList<>(pegs);
            Collections.sort(pegs, new Comparator<Point>() {
                public int compare(Point a, Point b) {
                    if (a.x == b.x) {
                        return Integer.compare(a.y, b.y);
                    }

                    return Integer.compare(a.x, b.x);
                }
            });
        }

        public static boolean safe(int x, int y) {
            if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
                return false;
            }

            if (x == 0 || x == ROWS - 1) {
                if (y < 3 || y >= 6) {
                    return false;
                }
            }

            return true;
        }

        public List<State> nextStates() {
            List<State> ret = new ArrayList<>();

            for (int i = 0; i < pegs.size(); i++) {
                for (int j = 0; j < pegs.size(); j++) {
                    if (i == j) {
                        continue;
                    }

                    // try jumping from i over j
                    int deltax = pegs.get(j).x - pegs.get(i).x;
                    int deltay = pegs.get(j).y - pegs.get(i).y;

                    for (int d = 0; d < 4; ++d) {
                        if (dx[d] == deltax && dy[d] == deltay) {
                            int nx = pegs.get(i).x + 2 * dx[d];
                            int ny = pegs.get(i).y + 2 * dy[d];
                            Point dst = new Point(nx, ny);
                            if (safe(nx, ny) && !pegs.contains(dst)) {
                                List<Point> after = new ArrayList<>();
                                for (int k = 0; k < pegs.size(); k++) {
                                    if (k == i || k == j) continue;
                                    after.add(pegs.get(k));
                                }

                                after.add(dst);

                                ret.add(new State(after));
                            }
                        }
                    }
                }
            }

            return ret;
        }

        public String toString() {
            return pegs.toString();
        }

        public boolean equals(Object other) {
            return this.toString().equals(other.toString());
        }

        public int hashCode() {
            return this.toString().hashCode();
        }
    }
}
