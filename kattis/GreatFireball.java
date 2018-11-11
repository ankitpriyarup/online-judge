import java.io.*;
import java.util.*;

public class GreatFireball {

    static final double EPS = 1e-9;

    public static class Vec {
        double x, y;
        Vec(double x, double y) {
            this.x = x;
            this.y = y;
        }

        double dist2() {
            return x * x + y * y;
        }

        double dist() {
            return Math.sqrt(dist2());
        }

        Vec add(Vec o) {
            return new Vec(x + o.x, y + o.y);
        }

        Vec sub(Vec o) {
            return new Vec(x - o.x, y - o.y);
        }

        Vec rescale(double newLen) {
            double oldLen = dist();
            return new Vec(x * newLen / oldLen, y * newLen / oldLen);
        }

        Vec perp() {
            double t = y;
            y = -x;
            x = t;

            return this;
        }

        double arg() {
            return Math.atan2(y, x);
        }
    }

    public static class Event implements Comparable<Event> {
        double alpha;
        int delta;

        Event(double alpha, int delta) {
            this.alpha = alpha;
            this.delta = delta;
        }

        @Override
        public int compareTo(Event o) {
            return Double.compare(alpha, o.alpha);
        }
    }

    public static int score(Vec[] positions, double rad) {
        List<Event> events = new ArrayList<>();
        for (int i = 0; i < positions.length; i++) {
            double mag2 = positions[i].dist2();
            if (mag2 >= 4.0 * rad * rad - EPS) {
                continue;
            }

            double mag = Math.sqrt(mag2);
            double d = mag / 2.0;
            double h = Math.sqrt(rad * rad - d * d);
            Vec center = positions[i].rescale(d);
            Vec perp = positions[i].rescale(h).perp();

            double a0 = center.add(perp).arg();
            double a1 = center.sub(perp).arg();
            if (a0 < a1) {
                events.add(new Event(a0, 1));
                events.add(new Event(a1, -1));

                events.add(new Event(a0 + 2 * Math.PI, 1));
                events.add(new Event(a1 + 2 * Math.PI, -1));
            } else {
                events.add(new Event(a0, 1));
                events.add(new Event(a1 + 2 * Math.PI, -1));
            }
        }

        Collections.sort(events);
        int ans = 0;
        int score = 0;
        for (Event e : events) {
            score += e.delta;
            ans = Math.max(ans, score);
        }

        return ans;
    }

    public static double solve(Vec[] positions, int k) {
        double lo = 0.0;
        double hi = 1e9;
        if (score(positions, hi) < k) {
            return -1;
        }

        for (int i = 0; i < 100; ++i) {
            double mid = (lo + hi) / 2.0;
            if (score(positions, mid) >= k) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Vec[] positions = new Vec[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            positions[i] = new Vec(x, y);
        }

        double ans = solve(positions, k);
        if (ans < 0) {
            System.out.println(-1);
        } else {
            System.out.printf("%.10f%n", ans);
        }
    }
}
