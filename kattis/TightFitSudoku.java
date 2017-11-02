import java.awt.Point;
import java.io.*;
import java.util.*;

public class TightFitSudoku {
    public static class Cell {
        boolean isSingle;
        int first;
        int second;

        public static int parse(char c) {
            if (c == '-') 
                return 0;
            else
                return c - '0';
        }

        public Cell(String token) {
            if (token.length() > 1 && token.charAt(1) == '/') {
                isSingle = false;
                first = parse(token.charAt(0));
                second = parse(token.charAt(2));
            } else {
                isSingle = true;
                first = parse(token.charAt(0));
            }
        }

        public String toString() {
            if (isSingle) {
                return Integer.toString(first);
            } else {
                return Integer.toString(first) + "/" + Integer.toString(second);
            }
        }
    }

    final static int SIZE = 6;
    static Cell[][] board;
    static boolean solved;
    static int[] rowMask;
    static int[] colMask;
    static int[] cellMask;

    public static void dfs(int r, int c) {
        if (solved) {
            return;
        }

        if (c == SIZE) {
            dfs(r + 1, 0);
            return;
        }

        if (r == SIZE) {
            solved = true;
            print();
            return;
        }

        int cell = getCell(r, c);
        int mask = rowMask[r] | colMask[c] | cellMask[cell];

        if (!board[r][c].isSingle && board[r][c].first == 0 && board[r][c].second == 0) {
            for (int i = 1; i <= 9; i++) {
                int bit = (1 << i);
                if ((mask & bit) != 0) {
                    continue;
                }

                rowMask[r] ^= bit;
                colMask[c] ^= bit;
                cellMask[cell] ^= bit;

                board[r][c].first = i;
                
                for (int j = i + 1; j <= 9; ++j) {
                    int bit2 = (1 << j);
                    if ((mask & bit2) != 0) {
                        continue;
                    }

                    rowMask[r] ^= bit2;
                    colMask[c] ^= bit2;
                    cellMask[cell] ^= bit2;

                    board[r][c].second = j;

                    dfs(r, c + 1);

                    rowMask[r] ^= bit2;
                    colMask[c] ^= bit2;
                    cellMask[cell] ^= bit2;

                    board[r][c].second = 0;
                }

                board[r][c].first = 0;

                rowMask[r] ^= bit;
                colMask[c] ^= bit;
                cellMask[cell] ^= bit;
            }
        } else if (board[r][c].first == 0) {
            for (int i = 1; i <= 9; i++) {
                int bit = (1 << i);
                if ((mask & bit) != 0) {
                    continue;
                }

                if (!board[r][c].isSingle && i > board[r][c].second) {
                    continue;
                }

                rowMask[r] ^= bit;
                colMask[c] ^= bit;
                cellMask[cell] ^= bit;

                board[r][c].first = i;
                
                dfs(r, c + 1);

                board[r][c].first = 0;

                rowMask[r] ^= bit;
                colMask[c] ^= bit;
                cellMask[cell] ^= bit;
            }
        } else if (!board[r][c].isSingle && board[r][c].second == 0) {
            for (int i = board[r][c].first + 1; i <= 9; i++) {
                int bit = (1 << i);
                if ((mask & bit) != 0) {
                    continue;
                }

                rowMask[r] ^= bit;
                colMask[c] ^= bit;
                cellMask[cell] ^= bit;

                board[r][c].second = i;
                
                dfs(r, c + 1);

                board[r][c].second = 0;

                rowMask[r] ^= bit;
                colMask[c] ^= bit;
                cellMask[cell] ^= bit;
            }
        } else {
            dfs(r, c + 1);
        }
    }

    public static void print() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                System.out.print(board[i][j]);
                if (j < 6)
                    System.out.print(' ');
            }
            System.out.println();
        }
    }

    public static int getCell(int i, int j) {
        return 2 * (i / 2) + (j / 3);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        board = new Cell[SIZE][SIZE];

        rowMask = new int[SIZE];
        colMask = new int[SIZE];
        cellMask = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = new Cell(st.nextToken());
                int val = board[i][j].first;

                if (val != 0) {
                    rowMask[i] |= (1 << val);
                    colMask[j] |= (1 << val);
                    cellMask[getCell(i, j)] = (1 << val);
                }

                if (!board[i][j].isSingle && board[i][j].second != 0) {
                    val = board[i][j].second;
                    rowMask[i] |= (1 << val);
                    colMask[j] |= (1 << val);
                    cellMask[getCell(i, j)] = (1 << val);
                }
            }
        }

        solved = false;
        dfs(0, 0);
    }
}
