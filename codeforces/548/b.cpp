#include <iostream>
#include <algorithm>

using namespace std;

int N, M, Q;
bool grid[505][505];
int row[505];

int calc_max(int r) {
    int ret = 0;
    int cur = 0;
    for (int c = 0; c < M; c++) {
        if (grid[r][c] == 0) {
            cur = 0;
        } else {
            cur++;
        }
        ret = max(ret, cur);
    }
    return ret;
}

int best() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        ret = max(ret, row[i]);
    }
    return ret;
}

int main() {
    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
        row[i] = calc_max(i);
    }

    int x, y;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        x--;
        y--;
        grid[x][y] = !grid[x][y];
        row[x] = calc_max(x);
        cout << best() << '\n';
    }
    return 0;
}
