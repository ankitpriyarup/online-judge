#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 502;
constexpr int MAXK = 12;

int n, m, k;
int grid[MAXN][MAXN];
bool pass[MAXN][MAXN];

int dist[MAXN][MAXN][MAXK];
bool vis[MAXN][MAXN][MAXK];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < m; ++j) {
            bool is_pass = true;
            for (int d = 0; d < 4; ++d) {
                if (grid[i + dx[d]][j + dy[d]] == -1)
                    is_pass = false;
            }

            is_pass &= grid[i][j] > grid[i][j - 1];
            is_pass &= grid[i][j] > grid[i][j + 1];
            is_pass &= grid[i][j] < grid[i - 1][j];
            is_pass &= grid[i][j] < grid[i + 1][j];

            pass[i][j] = is_pass;
        }
    }

    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; ++i) {
        vis[i][0][0] = true;
        dist[i][0][0] = grid[i][0];
    }

    constexpr int INF = 1e9;
    for (int j = 0; j + 1 < m; ++j) {
        for (int i = 0; i < n; ++i) {
            for (int v = 0; v <= k; ++v) {
                if (grid[i][j] == -1 or dist[i][j][v] > INF) continue;

                if (pass[i][j]) {
                    if (v + 1 <= k) {
                        for (int ni = max(0, i - 1); ni < min(n, i + 2); ++ni) {
                            dist[ni][j + 1][v + 1] = min(dist[ni][j + 1][v + 1], dist[i][j][v] + grid[ni][j + 1]);
                        }
                    }
                } else {
                    for (int ni = max(0, i - 1); ni < min(n, i + 2); ++ni) {
                        dist[ni][j + 1][v] = min(dist[ni][j + 1][v], dist[i][j][v] + grid[ni][j + 1]);
                    }
                }
            }
        }
    }

    /*
    for (int v = 0; v <= k; ++v) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dist[i][j][v] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    */

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dist[i][m - 1][k]);
    }

    if (ans == INF) {
        cout << "impossible\n";
    } else {
        cout << ans << '\n';
    }

    return 0;
}
