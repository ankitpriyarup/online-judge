import java.io.*;
import java.util.*;

public class SummerTrip {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int n = s.length();

        // The beginning and end must differ, and none of the middle
        // characters can match either of the ends
        // That means the end must be the first occurence of each character
        // that appears after the x-th occurence of the start but before the x+1-th
        List<Integer> occ[] = new List[26];
        for (int k = 0; k < 26; k++) {
            occ[k] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            occ[s.charAt(i) - 'a'].add(i);
        }

        // add a dummy end to simplify things
        for (int k = 0; k < 26; k++) {
            occ[k].add(n);
        }

        int[] ptrs = new int[26];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            int end = occ[idx].get(ptrs[idx] + 1);

            for (int k = 0; k < 26; k++) {
                int pos = occ[k].get(ptrs[k]);
                if (k != idx && pos < end) {
                    ans++;
                }
            }

            ptrs[idx]++;
        }

        System.out.println(ans);
    }
}
