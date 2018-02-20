#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define x udshkjhvcjkhczx
#define y vhaahsdgjkadhsgk
#define x1 asdhgahsdkgjhads
#define x2 bajsdhfkjahsdjkf
#define y1 cajsdjgkhajksdgh
#define y2 dajsfdbjknkzjcxz

constexpr int MAXN = 33;
int n, m;
int g, h;
// -1 gravestone, 1 haunted hole
int grid[MAXN][MAXN];
// x, y, t
tuple<int, int, int> dest[MAXN][MAXN];

int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

bool relax_edge(int x, int y, int nx, int ny, int t) {
    assert(vis[x][y]);
    assert(grid[x][y] != -1);
    assert(grid[nx][ny] != -1);

    if (!vis[nx][ny] or (dist[x][y] + t < dist[nx][ny])) {
        vis[nx][ny] = true;
        dist[nx][ny] = dist[x][y] + t;
        // printf("Used edge from (%d, %d) - %d -> (%d, %d) for dist %d\n", x, y, t, nx, ny, dist[nx][ny]);

        return true;
    }

    return false;
}

bool relax() {
    bool changed = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Don't process unvisited nodes, gravestones, or the end
            if (grid[i][j] == -1 or !vis[i][j] or (i == n - 1 and j == m - 1)) {
                continue;
            }

            if (grid[i][j] == 0) {
                for (int d = 0; d < 4; ++d) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] != -1) {
                        changed |= relax_edge(i, j, nx, ny, 1);
                    }
                }
            } else {
                assert(grid[i][j] == 1);
                int nx, ny, t;
                tie(nx, ny, t) = dest[i][j];

                changed |= relax_edge(i, j, nx, ny, t);
            }
        }
    }

    return changed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 or m == 0) break;
        memset(grid, 0, sizeof(grid));

        scanf("%d", &g);
        int x, y;
        for (int i = 0; i < g; ++i) {
            scanf("%d %d", &x, &y);
            grid[x][y] = -1;

            assert(0 <= x and x < n);
            assert(0 <= y and y < m);
            // printf("Grave at (%d, %d)\n", x, y);
        }

        scanf("%d", &h);
        int x1, y1, x2, y2, t;
        for (int i = 0; i < h; ++i) {
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
            assert(0 <= x1 and x1 < n);
            assert(0 <= y1 and y1 < m);
            assert(0 <= x2 and x2 < n);
            assert(0 <= y2 and y2 < m);

            grid[x1][y1] = 1;
            dest[x1][y1] = make_tuple(x2, y2, t);
            // printf("Hole from (%d, %d) to (%d, %d) with time %d\n", x1, y1, x2, y2, t);
        }

        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        */

        memset(vis, 0, sizeof(vis));
        vis[0][0] = 1;

        memset(dist, -1, sizeof(dist));
        dist[0][0] = 0;

        for (int iter = 0; iter < n * m; ++iter) {
            relax();
        }

        if (relax()) {
            printf("Never\n");
        } else if (!vis[n - 1][m - 1]) {
            printf("Impossible\n");
        } else {
            printf("%d\n", dist[n - 1][m - 1]);
        }
    }

    return 0;
}
