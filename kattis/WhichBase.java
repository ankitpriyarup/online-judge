import java.awt.Point;
import java.io.*;
import java.util.*;

public class WhichBase {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int case_num = Integer.parseInt(st.nextToken());
            String word = st.nextToken();
            int octal = 0;
            int decimal = Integer.parseInt(word, 10);
            int hex = Integer.parseInt(word, 16);
            if (!word.contains("8") && !word.contains("9")) {
                octal = Integer.parseInt(word, 8);
            }

            System.out.printf("%d %d %d %d\n", case_num, octal, decimal, hex);
        }
    }
}
