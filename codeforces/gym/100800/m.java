import java.util.*;
import java.io.*;

public class m {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int numCon = Integer.parseInt(st.nextToken());
        int numTotal = Integer.parseInt(st.nextToken());
        long[] con = new long[numCon];
        long[] all = new long[numTotal];
        st = new StringTokenizer(br.readLine());
        for (int a = 0; a < con.length; a++)
            con[a] = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int a = 0; a < all.length; a++)
            all[a] = Long.parseLong(st.nextToken());
        TreeSet<Long> dists = new TreeSet<Long>();
        for (int a = 0; a <= all.length - con.length; a++) {
            long result = tryFit(con, all, a);
            if (result != -1)
                dists.add(result);
        }
        System.out.println(dists.size());
        for (Long i : dists)
            System.out.print(i + " ");
    }

    private static long tryFit(long[] con, long[] all, int a) {
        double expected = (all[a + 1] - all[a]) * 1.0 / (con[1] - con[0]);
        for (int pos = 0; pos < con.length - 1; pos++) {
            double thisTime = (all[a + pos + 1] - all[a + pos]) * 1.0 / (con[pos + 1] - con[pos]);
            if (thisTime != expected) 
                return -1;
        }
        return all[a + 1] - all[a];
    }
}
