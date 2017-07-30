import java.util.*;
import java.io.*;

public class e {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numbers = Integer.parseInt(br.readLine());
        long largest = Long.MIN_VALUE;
        long sum = 0;
        long[] counts = new long[numbers];
        int pos = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int a = 0; a < numbers; a++) {
            long thisTime = Long.parseLong(st.nextToken());
            counts[a] = thisTime;
            if (thisTime > largest) {
                largest = thisTime;
                pos = a;
            }
            sum += thisTime;
        }
        sum -= largest;
        if (largest > sum)
            System.out.println("impossible");
        else {
            System.out.print((pos + 1) + " ");
            for (int a = 0; a < counts.length; a++) {
                if (a != pos) 
                    System.out.print((a + 1) + " ");
            }
        }
    }
}
