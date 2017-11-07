import java.awt.Point;
import java.awt.geom.*;
import java.io.*;
import java.util.*;

public class AbstractArt {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double sumArea = 0.0;
        Area unionArea = new Area();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            double[] pts = new double[2 * m];
            for (int j = 0; j < 2 * m; j++) {
                pts[j] = Integer.parseInt(st.nextToken());
            }

            Area curArea = makeArea(pts);
            sumArea += computeArea(curArea);
            unionArea.add(curArea);
        }

        double merged = computeArea(unionArea);
        
        System.out.printf("%.9f %.9f%n", sumArea, merged);
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

    public static double[] computeCentroid(double[] x, double[] y) {
        double xx = 0;
        double yy = 0;
        for (int i = 0; i < x.length; i++) {
            int j = i + 1;
            if (j >= x.length) {
                j -= x.length;
            }

            double cross = x[i] * y[j] - x[j] * y[i];
            xx += (x[i] + x[j]) * cross;
            yy += (y[i] + y[j]) * cross;
        }

        double area = computeArea(x, y);

        return new double[] { xx / (6.0 * area), yy / (6.0 * area) };
    }
}
