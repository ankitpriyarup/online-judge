import java.io.*;
import java.util.*;

public class EmplEh {
    static int[] plusx = {-1, -1, +1, +1};
    static int[] plusy = {-2, +2, -2, +2};

    static int[] dashx = {-1, -1, -1, +1, +1, +1};
    static int[] dashy = {-1, +0, +1, -1, +0, +1};

    static char[] dots = {'.', ':'};

    public static int from_digit(char c) {
        return 7 - (c - '1');
    }

    public static int from_alph(char c) {
        return c - 'a';
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[][] grid = new char[17][33];

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                int x = 1 + 2 * row;
                int y = 2 + 4 * col;

                for (int d = 0; d < 4; ++d) {
                    grid[x + plusx[d]][y + plusy[d]] = '+';
                }

                for (int d = 0; d < 6; ++d) {
                    grid[x + dashx[d]][y + dashy[d]] = '-';
                }

                grid[x][y - 2] = '|';
                grid[x][y + 2] = '|';

                for (int d = -1; d <= 1; ++d) {
                    grid[x][y + d] = dots[(row ^ col) & 1];
                }
            }
        }

        for (int white = 0; white < 2; ++white) {
            String line = br.readLine();
            String[] parts = line.substring(7).split(",");
            for (String part : parts) {
                if (part.length() < 2) continue;

                int row;
                int col;
                char piece;
                if (part.length() == 2) {
                    row = from_digit(part.charAt(1));
                    col = from_alph(part.charAt(0));
                    piece = 'P';
                } else {
                    row = from_digit(part.charAt(2));
                    col = from_alph(part.charAt(1));
                    piece = part.charAt(0);
                }

                int x = 1 + 2 * row;
                int y = 2 + 4 * col;
                grid[x][y] = (char)(piece + (white == 1 ? ('a' - 'A') : 0));
            }
        }

        for (int i = 0; i < grid.length; ++i) {
            System.out.println(new String(grid[i]));
        }
    }
}
