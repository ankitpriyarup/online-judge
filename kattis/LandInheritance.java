import java.awt.Point;
import java.awt.geom.*;
import java.io.*;
import java.util.*;

public class LandInheritance {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double[] pts = new double[2 * n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            pts[2 * i] = x;
            pts[2 * i + 1] = y;
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int x1 = Integer.parseInt(st.nextToken());
        int y1 = Integer.parseInt(st.nextToken());
        int x2 = Integer.parseInt(st.nextToken());
        int y2 = Integer.parseInt(st.nextToken());

        double dx = x2 - x1;
        double dy = y2 - y1;

        Area orig = makeArea(pts);
        double[] flipped = new double[2 * n];
        for (int i = 0; i < n; ++i) {
            double x = pts[2 * i] - x1;
            double y = pts[2 * i + 1] - y1;

            // System.out.printf("Considering point (%.2f, %.2f)%n", x + x1, y + y1);
            double scale = (x * dx + y * dy) / (dx * dx + dy * dy);
            double projx = x + 2.0 * (scale * dx - x);
            double projy = y + 2.0 * (scale * dy - y);

            // System.out.printf("Projection point (%.2f, %.2f)%n", projx + x1, projy + y1);
            flipped[2 * i] = projx + x1;
            flipped[2 * i + 1] = projy + y1;
        }

        Area flippedArea = makeArea(flipped);
        orig.intersect(flippedArea);
        System.out.printf("%.11f%n", computeArea(orig) / 2.0);
    }

    public static Area makeArea(double[] pts) {
        Path2D.Double p = new Path2D.Double();
        p.moveTo(pts[0], pts[1]);
        for (int i = 2; i < pts.length; i += 2) {
            p.lineTo(pts[i], pts[i + 1]);
        }
        p.closePath();

        return new Area(p);
    }

    public static double computeArea(Area a) {
        double ret = 0.0;
        PathIterator iter = a.getPathIterator(null);
        double[] buffer = new double[6];
        List<Double> ps = new ArrayList<>();

        while (!iter.isDone()) {
            switch (iter.currentSegment(buffer)) {
                case PathIterator.SEG_MOVETO:
                case PathIterator.SEG_LINETO:
                    ps.add(buffer[0]);
                    ps.add(buffer[1]);
                    break;
                case PathIterator.SEG_CLOSE:
                    ps.add(ps.get(0));
                    ps.add(ps.get(1));
                    Double[] qs = ps.toArray(new Double[0]);
                    for (int i = 0; i + 2 < ps.size(); i += 2) {
                        ret -= qs[i] * qs[i + 3] - qs[i + 1] * qs[i + 2];
                    }
                    ps.clear();
                    break;
            }

            iter.next();
        }

        return ret / 2.0;
    }
}
