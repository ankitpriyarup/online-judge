import java.io.*;
import java.util.*;

public class HelpMe {
    public static char make_row(int x) {
        return (char)('8' - x);
    }

    public static char make_col(int x) {
        return "abcdefghij".charAt(x);
    }

    static String[] colors = {"White", "Black"};
    static String order = "KQRBNP";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[][] grid = new char[17][33];

        for (int i = 0; i < grid.length; ++i) {
            grid[i] = br.readLine().toCharArray();
        }

        List<String>[][][] pieces = new ArrayList[2][6][8];
        for (int color = 0; color < 2; ++color) {
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 8; ++j)
                    pieces[color][i][j] = new ArrayList<>();
            }
        }

        for (int color = 0; color < 2; ++color) {
            for (int row = 0; row < 8; ++row) {
                for (int col = 0; 0 <= col && col < 8; ++col) {
                    int x = 1 + 2 * row;
                    int y = 2 + 4 * col;
                    if (grid[x][y] == '.' || grid[x][y] == ':') {
                        continue;
                    }

                    char piece = grid[x][y];
                    boolean black = false;
                    if (piece >= 'a') {
                        black = true;
                        piece -= 'a';
                        piece += 'A';
                    }

                    int b = black ? 1 : 0;
                    if (b != color) continue;

                    char cout = make_col(col);
                    char rout = make_row(row);
                    String out;
                    if (piece == 'P') {
                        out = "" + cout + rout;
                    } else {
                        out = "" + piece + cout + rout;
                    }

                    pieces[b][order.indexOf(piece)][row].add(out);
                }
            }
        }

        for (int color = 0; color < 2; ++color) {
            System.out.print(colors[color] + ": ");
            boolean first = true;
            for (int i = 0; i < 6; ++i) {
                if (color == 1) {
                    for (int row = 0; row < 8; ++row) {
                        for (String piece : pieces[color][i][row]) {
                            if (!first) {
                                System.out.print(",");
                            }
                            System.out.print(piece);
                            first = false;
                        }
                    }
                } else {
                    for (int row = 7; row > -1; --row) {
                        for (String piece : pieces[color][i][row]) {
                            if (!first) {
                                System.out.print(",");
                            }
                            System.out.print(piece);
                            first = false;
                        }
                    }
                }
            }

            System.out.println();
        }
    }
}
