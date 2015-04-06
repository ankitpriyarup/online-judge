#include <iostream>

using namespace std;

int T, N, M, Q, R, C;
char L;
char grid1[105][105];
char grid2[105][105];
bool visited[105][105];

void flood_fill(int row, int col, char old_letter, char new_letter) {
    //cout << row << " " << col << " " << old_letter << " " << new_letter << '\n';
    if (row < 0 || col < 0 || row >= N || col >= M || visited[row][col] || grid1[row][col] != old_letter) {
        return;
    }

    visited[row][col] = true;
    grid2[row][col] = new_letter;

    flood_fill(row - 1, col, old_letter, new_letter);
    flood_fill(row + 1, col, old_letter, new_letter);
    flood_fill(row, col + 1, old_letter, new_letter);
    flood_fill(row, col - 1, old_letter, new_letter);
}

void reset_visited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
}

void update_grid() {
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            grid1[i][j] = grid2[i][j];
        }
    }
}

int main() {

    cin >> T;
    for (int case_num = 0; case_num < T; case_num++) {
        cin >> N >> M >> Q;
        for (int i = 0; i < N; i++) {
            cin >> grid1[i];
            for (int j = 0; j < M; j++) {
                grid2[i][j] = grid1[i][j];
            }
        }

        for (int i = 0; i < Q; i++) {
            cin >> R >> C >> L;
            reset_visited();
            flood_fill(R, C, grid1[R][C], L);
            update_grid();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << grid1[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
