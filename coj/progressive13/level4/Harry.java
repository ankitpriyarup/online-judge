import java.io.*;
import java.util.*;

public class Harry {
    public static boolean isUpper(char c) {
        return 'A' <= c && c <= 'Z';
    }

    public static boolean isLower(char c) {
        return 'a' <= c && c <= 'z';
    }

    public static boolean isLetter(char c) {
        return isUpper(c) || isLower(c);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            List<String> lines = new ArrayList<>();
            while (lines.isEmpty() || !lines.get(lines.size() - 1).equals("*")) {
                lines.add(br.readLine());
            }

            lines.remove(lines.size() - 1);
            for (String line : lines) {
                StringBuilder sb = new StringBuilder();
                for (int l = 0; l < line.length(); ++l) {
                    char c = line.charAt(l);
                    if (!isLetter(c)) {
                        sb.append(c);
                        continue;
                    }

                    int r = l;
                    while (r < line.length() && isLetter(line.charAt(r))) {
                        ++r;
                    }

                    if (l + 1 == r) {
                        sb.append(c);
                        continue;
                    }

                    for (int i = r - 1; i >= l; --i) {
                        char d = line.charAt(i);
                        if (isUpper(c) && i == r - 1 && isLower(d)) {
                            d -= 'a';
                            d += 'A';
                        } else if (isUpper(d)) {
                            d -= 'A';
                            d += 'a';
                        }

                        sb.append(d);
                    }

                    l = r - 1;
                }

                System.out.println(sb);
            }
            if (T != 0)
                System.out.println();
        }
    }
}
