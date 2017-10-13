import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        char[][] grid = new char[r][c];
        boolean[] bad_row = new boolean[r];
        boolean[] bad_col = new boolean[c];

        for (int i = 0; i < r; ++i) {
            grid[i] = br.readLine().toCharArray();
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 'X') {
                    bad_row[i] = true;
                    bad_col[j] = true;
                }
            }
        }

        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int cc = Integer.parseInt(st.nextToken()) - 1;
            int rr = Integer.parseInt(st.nextToken()) - 1;

            if (bad_row[rr] || bad_col[cc]) {
                System.out.println("Y");
            } else {
                System.out.println("N");
            }
        }
    }
}
