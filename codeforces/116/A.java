import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        final Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        int ans = 0;
        int cur = 0;
        while (scan.hasNextLine()) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            scan.nextLine();
            cur -= a;
            cur += b;
            ans = Math.max(ans, cur);
        }

        System.out.println(ans);
    }
}
