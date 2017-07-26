import java.util.*;
import java.io.*;

public class i {

    private static char[] replace = {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};
    private static HashSet<Character> hards = new HashSet<Character>(Arrays.asList('b', 'c', 'd', 'g', 'k', 'n', 'p', 't'));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer words = new StringTokenizer(br.readLine());
        while (words.hasMoreTokens()) {
            String word = words.nextToken();
            String[] syls = word.split("-");
            char firstLower = getClosest(syls[0]);
            char firstUpper = (firstLower + "").toUpperCase().charAt(0);
            char lastPrinted = 'a';
            if (syls[0].charAt(0) <= 'Z')
                System.out.print(firstUpper);
            else
                System.out.print(firstLower);
            System.out.print(syls[0].substring(1));
            if (syls[0].length() != 1)
                lastPrinted = syls[0].charAt(syls[0].length() - 1);
            else
                lastPrinted = firstLower;
            for (int pos = 1; pos < syls.length; pos++) {
                String s = syls[pos];
                String lower = s.toLowerCase();
                for (int a = 0; a < s.length(); a++) {
                    if (hards.contains(lower.charAt(a))) {
                        if (s.charAt(a) <= 'Z') 
                            System.out.print(firstUpper);
                        else
                            System.out.print(firstLower);
                        lastPrinted = firstLower;
                    } else {
                        System.out.print(s.charAt(a));
                        lastPrinted = s.charAt(a);
                    }
                }
            }
            printSuffix(lastPrinted);
            System.out.print(' ');
        }
    }

    private static void printSuffix(char s) {
        char lower = (s + "").toLowerCase().charAt(0);
        char[] opts = {'a', 'o', 'u'};
        if (!hards.contains(s)) {
            return;
        }
        int min = Integer.MAX_VALUE;
        char ans = 'a';
        for (int a = 0; a < opts.length; a++) {
            int thisDiff = Math.abs(opts[a] - s);
            if (thisDiff < min) {
                min = thisDiff;
                ans = opts[a];
            }
        }
        System.out.print(ans);
        System.out.print("h");
    }

    private static char getClosest(String s) {
        int min = Integer.MAX_VALUE;
        char ans = 'a';
        char toReplace = s.toLowerCase().charAt(0);
        for (int a = 0; a < replace.length; a++) {
            int thisTime = Math.abs(toReplace - replace[a]);
            if (thisTime < min) {
                min = thisTime;
                ans = replace[a];
            }
        }
        return ans;
    }
}
