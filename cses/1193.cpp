#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1003;
int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int previous[MAXN][MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
string labels = "DLUR";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int sx, sy, ex, ey;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];

            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
                grid[i][j] = '.';
            }
            if (grid[i][j] == 'B') {
                ex = i;
                ey = j;
                grid[i][j] = '.';
            }
        }
    }

    queue<pii> q;
    q.emplace(sx, sy);
    memset(dist, -1, sizeof(dist));
    dist[sx][sy] = 0;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (0 <= nx and nx < n and 0 <= ny and ny < m and dist[nx][ny] == -1 and grid[nx][ny] == '.') {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
                previous[nx][ny] = d;
            }
        }
    }

    if (dist[ex][ey] == -1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        cout << dist[ex][ey] << '\n';

        string res;
        int x = ex;
        int y = ey;
        while (x != sx or y != sy) {
            int d = previous[x][y];
            res.push_back(labels[d]);
            x -= dx[d];
            y -= dy[d];
        }

        reverse(all(res));
        cout << res << '\n';
    }

    return 0;
}
