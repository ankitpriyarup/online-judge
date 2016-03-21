import java.io.*;
import java.util.*;

public class TTTT {
    static char[][] board;

    static boolean winner(char player) {
        int tx = -1, ty = -1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (board[i][j] == 'T') {
                    board[i][j] = player;
                    tx = i;
                    ty = j;
                }
            }
        }

        boolean won = false;
        // row, col
        for (int i = 0; i < 4; ++i) {
            int row_count = 0;
            int col_count = 0;
            for (int j = 0; j < 4; ++j) {
                if (board[i][j] == player) {
                    row_count++;
                }

                if (board[j][i] == player) {
                    col_count++;
                }
            }

            won |= (row_count == 4) || (col_count == 4);
        }

        //diag
        int ldiag = 0;
        int rdiag = 0;
        for (int i = 0; i < 4; ++i) {
            if (board[i][i] == player) {
                ldiag++;
            }

            if (board[3 - i][i] == player) {
                rdiag++;
            }
        }

        won |= (ldiag == 4) || (rdiag == 4);

        if (tx >= 0)
            board[tx][ty] = 'T';
        return won;
    }

    static String solve(boolean gap) {
        if (winner('X')) {
            return "X won";
        } else if (winner('O')) {
            return "O won";
        } else if (gap) {
            return "Game has not completed";
        } else {
            return "Draw";
        }
    }

    public static void main(String[] args) {
        final Scanner scan = new Scanner(System.in);
        final int T = Integer.parseInt(scan.nextLine());

        for (int case_num = 1; case_num <= T; case_num++) {
            board = new char[4][4];
            boolean gap = false;
            for (int i = 0; i < 4; i++) {
                board[i] = scan.nextLine().toCharArray();
                for (int j = 0; j < 4; j++) {
                    if (board[i][j] == '.') gap = true;
                }
            }

            System.out.printf("Case #%d: %s\n", case_num, solve(gap));

            if (case_num <= T - 1)
                scan.nextLine();
        }
    }
}
