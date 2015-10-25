import java.util.*;
import java.io.*;
import java.awt.Point;
public class Far {

    public static class Node {
        int dist;
        Point p;

        public Node(int x, int y, int z) {
            this.p = new Point(x, y);
            this.dist = z;
        }

        public Node(Point p, int z) {
            this.p = p;
            this.dist = z;
        }

        public String toString() {
            return "" + p + " " + dist;
        }
    }

    public static void main(String[] args) {
        final Scanner s = new Scanner(System.in);
        final int T = Integer.parseInt(s.nextLine());

        for (int case_num = 1; case_num <= T; case_num++) {
            StringTokenizer st = new StringTokenizer(s.nextLine());
            final int fx = Integer.parseInt(st.nextToken());
            final int fy = Integer.parseInt(st.nextToken());
            final int sx = Integer.parseInt(st.nextToken());
            final int sy = Integer.parseInt(st.nextToken());
            final int N = Integer.parseInt(st.nextToken());

            final List<Point> asteroids = new ArrayList<Point>();
            final Map<Integer, List<Integer>> byX = new HashMap<>();
            final Map<Integer, List<Integer>> byY = new HashMap<>();

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(s.nextLine());
                final int ax = Integer.parseInt(st.nextToken());
                final int ay = Integer.parseInt(st.nextToken());
                asteroids.add(new Point(ax, ay));
                if (!byX.containsKey(ax)) {
                    byX.put(ax, new ArrayList<Integer>());
                }
                byX.get(ax).add(ay);

                if (!byY.containsKey(ay)) {
                    byY.put(ay, new ArrayList<Integer>());
                }
                byY.get(ay).add(ax);
            }

            final Set<Point> seen = new HashSet<>();

            final Queue<Node> q = new LinkedList<>();
            q.add(new Node(fx, fy, 0));

            int ans = -1;
            while (!q.isEmpty()) {
                Node cur = q.remove();
                if (seen.contains(cur.p)) {
                    continue;
                }
                seen.add(cur.p);

                //System.out.println("Currently at " + cur);

                // check if we can get to safety
                if (sx == cur.p.x) {
                    // make sure there's no asteroids between s.y and c.p.y
                    boolean works = true;
                    if(byX.containsKey(sx)) {
                        for (int y : byX.get(sx)) {
                            if ((sy < y && y < cur.p.y) || (cur.p.y < y && y < sy)) {
                                works = false;
                                break;
                            }
                        }
                    }

                    if (works) {
                        ans = cur.dist;
                        break;
                    }
                }

                if (sy == cur.p.y) {
                    // make sure there's no asteroids between s.x and c.p.x
                    boolean works = true;
                    if (byY.containsKey(sy)) {
                        for (int x : byY.get(sy)) {
                            if ((sx < x && x < cur.p.x) || (cur.p.x < x && x < sx)) {
                                works = false;
                                break;
                            }
                        }
                    }

                    if (works) {
                        ans = cur.dist;
                        break;
                    }
                }

                // find the next asteroids to consider
                if (byX.containsKey(cur.p.x)) {
                    final List<Integer> rowAsteroids = byX.get(cur.p.x);
                    int left = Integer.MIN_VALUE;
                    int right = Integer.MAX_VALUE;
                    for (int y : rowAsteroids) {
                        if (y < cur.p.y) {
                            left = Math.max(left, y);
                        } else {
                            right = Math.min(right, y);
                        }
                    }

                    if (left != Integer.MIN_VALUE) {
                        q.add(new Node(cur.p.x, left + 1, cur.dist + 1));
                    }

                    if (right != Integer.MAX_VALUE) {
                        q.add(new Node(cur.p.x, right - 1, cur.dist + 1));
                    }
                }

                if (byY.containsKey(cur.p.y)) {
                    final List<Integer> colAsteroids = byY.get(cur.p.y);
                    int top = Integer.MIN_VALUE;
                    int bot = Integer.MAX_VALUE;

                    for (int x : colAsteroids) {
                        if (x < cur.p.x) {
                            top = Math.max(top, x);
                        } else {
                            bot = Math.min(bot, x);
                        }
                    }

                    if (top != Integer.MIN_VALUE) {
                        q.add(new Node(top + 1, cur.p.y, cur.dist + 1));
                    }

                    if (bot != Integer.MAX_VALUE) {
                        q.add(new Node(bot - 1, cur.p.y, cur.dist + 1));
                    }
                }
            }

            System.out.printf("Case %d: ", case_num);
            if (ans == -1) {
                System.out.println("LOST IN SPACE");
            } else {
                System.out.println(ans + 1);
            }
        }
    }
}
