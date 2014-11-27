#include <iostream>

using namespace std;

int N, M, starCount;
char board[1001][1001];
int dir[4][1001][1001];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    // Calculate counts in the 4 directions
    // By row
    for (int i = 0; i < N; i++) {
        // Left to right
        starCount = 0;
        for (int j = 0; j < M; j++) {
            dir[0][i][j] = starCount;
            if (board[i][j] == '*') {
                starCount++;
            }
        }
        // Right to left
        starCount = 0;
        for (int j = M - 1; j >= 0; j--) {
            dir[1][i][j] = starCount;
            if (board[i][j] == '*') {
                starCount++;
            }
        }
    }

    // By column
    for (int j = 0; j < M; j++) {
        // Top to bottom
        starCount = 0;
        for (int i = 0; i < N; i++) {
            dir[2][i][j] = starCount;
            if (board[i][j] == '*') {
                starCount++;
            }
        }

        // Bottom to top
        starCount = 0;
        for (int i = N - 1; i >= 0; i--) {
            dir[3][i][j] = starCount;
            if (board[i][j] == '*') {
                starCount++;
            }
        }
    }

    long long ans = 0LL;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '*') {
                for (int lr = 0; lr <= 1; lr++) {
                    for (int ud = 2; ud <= 3; ud++) {
                        ans += 1LL * dir[lr][i][j] * dir[ud][i][j];
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
