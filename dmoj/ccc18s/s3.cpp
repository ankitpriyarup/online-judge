#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    int sx = -1, sy = -1;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;

                grid[sx][sy] = '.';
            }
        }
    }

    auto in_bounds = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m;
    };

    vector<vector<char>> on_camera(n, vector<char>(m, 0));
    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};
    string moves = "DRUL";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'C') {
                on_camera[i][j] = true;

                for (int d = 0; d < 4; ++d) {
                    int x = i;
                    int y = j;
                    while (in_bounds(x, y) and grid[x][y] != 'W') {
                        on_camera[x][y] = true;
                        x += dx[d];
                        y += dy[d];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.' and grid[i][j] != 'C')
                on_camera[i][j] = false;
        }
    }

    vector<vi> dist(n, vi(m, -1));
    deque<pii> dq;
    if (!on_camera[sx][sy]) {
        dist[sx][sy] = 0;
        dq.emplace_back(sx, sy);
    }

    while (!dq.empty()) {
        int x, y;
        tie(x, y) = dq.front();
        dq.pop_front();

        assert(in_bounds(x, y));
        assert(grid[x][y] != 'C');
        assert(!on_camera[x][y]);

        if (grid[x][y] != '.') {
            int d = 0;
            while (grid[x][y] != moves[d])
                ++d;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (in_bounds(nx, ny) and grid[nx][ny] != 'W' and !on_camera[nx][ny] and (dist[nx][ny] == -1 or dist[x][y] < dist[nx][ny])) {
                dist[nx][ny] = dist[x][y];
                dq.emplace_front(nx, ny);
            }
        } else {
            // freedom
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (in_bounds(nx, ny) and grid[nx][ny] != 'W' and !on_camera[nx][ny] and dist[nx][ny] == -1) {
                    dist[nx][ny] = 1 + dist[x][y];
                    dq.emplace_back(nx, ny);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.' or (i == sx and j == sy)) {
                continue;
            }

            cout << dist[i][j] << '\n';
        }
    }

    return 0;
}
