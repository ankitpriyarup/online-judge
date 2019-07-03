#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1010;
int n, m;
char grid[MAXN][MAXN];
int uf[MAXN * MAXN];
int sz[MAXN * MAXN];

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) {
        return 0;
    }

    uf[xr] = yr;
    sz[yr] += sz[xr];
    sz[xr] = 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(grid, '.', sizeof(grid));
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                grid[i][j] = s[j];
            }
        }

        // reset
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int id = m * i + j;
                uf[id] = id;
                sz[id] = (grid[i][j] == '#');
            }
        }

        int dummy = m * n;
        uf[dummy] = dummy;
        sz[dummy] = 0;

        // merge
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int id = m * i + j;
                if (grid[i][j] != '*') {
                    for (int dx = -1; dx <= 1; ++dx) {
                        for (int dy = -1; dy <= 1; ++dy) {
                            if (dx == 0 and dy == 0) continue;

                            int nx = i + dx;
                            int ny = j + dy;
                            if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] != '*') {
                                merge(id, m * nx + ny);
                            }
                        }
                    }

                    if (i == 0 or i == n - 1 or j == 0 or j == m - 1) {
                        merge(id, dummy);
                    }
                }
            }
        }

        // solve
        int ans = sz[find(dummy)];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '*') {
                    continue;
                }

                set<int> neighbors;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 and dy == 0) continue;

                        int nx = i + dx;
                        int ny = j + dy;
                        if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] != '*')
                            neighbors.insert(find(m * nx + ny));
                    }
                }

                if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    neighbors.insert(find(dummy));
                }

                if (neighbors.count(find(dummy)) == 0)
                    continue;

                int cur = 0;
                for (int x : neighbors) {
                    cur += sz[x];
                }

                // cout << i << ' ' << j << ' ' << cur << '\n';
                ans = max(ans, cur);
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}
