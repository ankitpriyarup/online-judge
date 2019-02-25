#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool valid(const vector<string>& grid, int k, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    if (!(0 <= i and i < n and 0 <= j and j < m))
        return false;

    if (k == 0) {
        return grid[i][j] == '1';
    } else if (k == 1) {
        if (!(0 <= j + 1 and j + 1 < m))
            return false;
        return grid[i][j] - '0' + grid[i][j + 1] - '0' == 2;
    } else {
        if (!(0 <= i + 1 and i + 1 < n)) {
            return false;
        }
        return grid[i][j] - '0' + grid[i + 1][j] - '0' == 2;
    }
}

int nk[3][4] = {{1, 2, 1, 2}, {0, 1, 0, 1}, {2, 0, 2, 0}};
int dx[3][4] = {{0, 1, 0, -2}, {0, 1, 0, -1}, {0, 2, 0, -1}};
int dy[3][4] = {{1, 0, -2, 0}, {2, 0, -1, 0}, {1, 0, -1, 0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        --x; --y;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        // k = 0 standing, 1 lying right, 2 lying down
        vector<vector<vi>> dist(3, vector<vi>(n, vi(m, -1)));
        dist[0][x][y] = 0;
        queue<tuple<int, int, int>> q;
        q.emplace(0, x, y);
        while (!q.empty()) {
            int k, i, j;
            tie(k, i, j) = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int kk = nk[k][d];
                int nx = i + dx[k][d];
                int ny = j + dy[k][d];
                if (valid(grid, kk, nx, ny) and dist[kk][nx][ny] == -1) {
                    dist[kk][nx][ny] = dist[k][i][j] + 1;
                    q.emplace(kk, nx, ny);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dist[0][i][j] << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}
