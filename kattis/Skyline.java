import java.awt.Point;
import java.awt.geom.*;
import java.io.*;
import java.util.*;

public class Skyline {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Area[] areas = new Area[n];
        double[] origSize = new double[n];
        double[] finalSize = new double[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double[] pts = new double[8];
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            pts[0] = x1;
            pts[1] = 0.0;
            pts[2] = x1;
            pts[3] = y1;
            pts[4] = x2;
            pts[5] = y2;
            pts[6] = x2;
            pts[7] = 0.0;

            areas[i] = makeArea(pts);
            origSize[i] = computeArea(areas[i]);
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                areas[i].subtract(areas[j]);
            }

            finalSize[i] = computeArea(areas[i]);
        }

        for (int i = 0; i < n; ++i) {
            double ratio = finalSize[i] / origSize[i];
            System.out.printf("%.9f%n", ratio);
        }
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

    public static double computeArea(double[] x, double[] y) {
        double area2 = 0;
        for (int i = 0; i < x.length; i++) {
            int j = i + 1;
            if (j >= x.length) {
                j -= x.length;
            }

            area2 += (x[i] * y[j] - x[j] * y[i]);
        }

        return area2 / 2.0;
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
