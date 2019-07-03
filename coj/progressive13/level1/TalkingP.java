import java.io.*;
import java.util.*;

public class TalkingP {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        String vowels = "aeiou";
        while (T-- > 0) {
            String t = br.readLine();
            StringBuilder sb = new StringBuilder();
            for (char c : t.toCharArray()) {
                sb.append(c);
                if (vowels.indexOf(c) != -1) {
                    sb.append('p');
                    sb.append(c);
                }
            }

            System.out.println(sb);
        }
    }
}

