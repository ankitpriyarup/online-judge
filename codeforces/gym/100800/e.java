import java.util.*;
import java.io.*;

public class e {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        double c = Double.parseDouble(st.nextToken());
        double d = Double.parseDouble(st.nextToken());
        int[] r = new int[t];
        int[] rCum = new int[t];
        for (int a = 0; a < r.length; a++) {
            r[a] = Integer.parseInt(br.readLine());
            if (a == 0)
                rCum[a] = r[a];
            else
                rCum[a] = rCum[a - 1] + r[a];
        }


        double res = Long.MAX_VALUE;

        double x = 3600 * c * (d * d);
        for (int a = 0; a < r.length; a++) {
            for (int b = a; b < r.length; b++) {
                int m = Integer.max(r[a], r[b]);
                double num = Math.sqrt(x / m);
                if (num < (b - a) || num > (b - a + 1)) 
                    num = b - a + 1;

                double curr = x / num + rCum[b];
                if (a != 0)
                    curr -= rCum[a - 1];

                curr -= m * (b - a + 1 - num);
                if (curr < res)
                    res = curr;
            }
        }

        System.out.println(res);
    }
}
