#include <iostream>
#include <cstring>

using namespace std;

int N = 6;
int M = 7;

int T;
char grid[10][10];
char grid2[10][10];

void reset_grid() {
    memcpy(grid2, grid, sizeof(grid));
}

void drop(int row, int col) {
    if (row == N - 1 || grid2[row + 1][col] != '.') {
        return;
    }
    grid2[row + 1][col] = grid2[row][col];
    grid2[row][col] = '.';
    drop(row + 1, col);
}

int score_grid(char chip) {
    // score the rows
    int score = 0;
    for (int i = 0; i < N; i++) {
        int streak = 0;
        for (int j = 0; j < M; j++) {
            if (grid2[i][j] != chip) {
                score += streak * streak * streak;
                streak = 0;
            } else {
                streak++;
            }
        }
        score += streak * streak * streak;
    }

    for (int j = 0; j < M; j++) {
        int streak = 0;
        for (int i = 0; i < N; i++) {
            if (grid2[i][j] != chip) {
                score += streak * streak * streak;
                streak = 0;
            } else {
                streak++;
            }
        }
        score += streak * streak * streak;
    }

    return score;
}

int main() {
    cin >> T;    

    for (int case_num = 0; case_num < T; case_num++) {
        int red_count = 0;
        int black_count = 0;
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'R') {
                    red_count++;
                } else if (grid[i][j] == 'B') {
                    black_count++;
                }
            }
        }

        char chip;
        if (red_count == black_count) {
            chip = 'R';
        } else {
            chip = 'B';
        }

        int best_score = 0;
        int best_col = 0;
        for (int col = 0; col < M; col++) {
            if (grid[0][col] != '.') {
                continue;
            }

            reset_grid();
            grid2[0][col] = chip;
            drop(0, col);

            int score = score_grid(chip);
            if (score > best_score) {
                best_score = score;
                best_col = col;
            }
        }

        reset_grid();
        grid2[0][best_col] = chip;
        drop(0, best_col);
        cout << chip << " " << (best_col + 1) << '\n';
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << grid2[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
