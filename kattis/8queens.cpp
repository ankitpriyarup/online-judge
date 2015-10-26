#include <iostream>

using namespace std;

char board[10][10];
int dx[] = {1, 0, -1, -1, -1, 0, 1, 1};
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

bool bounds(int x, int y) {
    return (0 <= x && x < 8) && (0 <= y && y < 8);
}

bool check(int x, int y) {
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        while (bounds(nx, ny)) {
            if (board[nx][ny] == '*') {
                return false;
            }

            nx += dx[d];
            ny += dy[d];
        }
    }

    return true;
}

int main() {
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    bool valid = true;
    int queens = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == '*') {
                valid &= check(i, j);
                queens++;
            }
        }
    }

    valid &= (queens == 8);

    cout << (valid ? "valid" : "invalid") << '\n';
}
