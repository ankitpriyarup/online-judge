import java.util.*;
import java.io.*;

public class Boggle {
    static final int[] SCORES = {0, 0, 0, 1, 1, 2, 3, 5, 11};

    static final int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static final int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    static char[][] grid;
    static boolean[][] visited;

    public static boolean solve(int x, int y, String word, int pos) {
        if (pos == word.length()) {
            return true;
        }

        boolean res = false;
        visited[x][y] = true;

        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && !visited[nx][ny] && grid[nx][ny] == word.charAt(pos)) {
                res = res || solve(nx, ny, word, pos + 1);
            }
        }

        visited[x][y] = false;

        return res;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numWords = Integer.parseInt(br.readLine());

        String[] words = new String[numWords];
        for (int i = 0; i < numWords; i++) {
            words[i] = br.readLine();
        }

        br.readLine();

        int numBoards = Integer.parseInt(br.readLine());
        final StringBuilder sb = new StringBuilder();
        while (numBoards-- > 0) {
            grid = new char[4][4];
            for (int i = 0; i < 4; i++) {
                grid[i] = br.readLine().toCharArray();
            }

            visited = new boolean[4][4];
            Set<String> foundWords = new HashSet<String>();

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (String word : words) {
                        if (foundWords.contains(word)) continue;

                        if (grid[i][j] == word.charAt(0)) {
                            if (solve(i, j, word, 1)) {
                                foundWords.add(word);
                            }
                        }
                    }
                }
            }

            int score = 0;
            String longestWord = "";
            int found = foundWords.size();

            for (String word : foundWords) {
                if (word.length() > longestWord.length() || (word.length() == longestWord.length() && word.compareTo(longestWord) < 0)) {
                    longestWord = word;
                }

                score += SCORES[word.length()];
            }

            sb.append(score);
            sb.append(' ');
            sb.append(longestWord);
            sb.append(' ');
            sb.append(found);
            sb.append('\n');

            if (numBoards > 0) {
                br.readLine();
            }
        }

        System.out.print(sb.toString());
    }
}
