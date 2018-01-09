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

constexpr int MAXN = 1003;
constexpr int INF = 1e9;
int n, m;
char grid[MAXN][MAXN];
int dist[2][MAXN][MAXN];

constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);

    memset(dist, -1, sizeof(dist));
    queue<pii> q[2];
    int sx, sy;
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'J') {
                q[0].push({i, j});
                dist[0][i][j] = 0;
                grid[i][j] = '.';
            } else if (grid[i][j] == 'F') {
                q[1].push({i, j});
                dist[1][i][j] = 0;
            }
        }
    }

    for (int k = 0; k < 2; ++k) {
        int x, y;
        while (!q[k].empty()) {
            tie(x, y) = q[k].front();
            q[k].pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] == '.' and dist[k][nx][ny] == -1) {
                    dist[k][nx][ny] = 1 + dist[k][x][y];
                    q[k].push({nx, ny});
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j += m - 1) {
            if (dist[0][i][j] != -1 and (dist[1][i][j] == -1 or dist[0][i][j] < dist[1][i][j]))
                ans = min(ans, dist[0][i][j] + 1);
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; i += n - 1) {
            if (dist[0][i][j] != -1 and (dist[1][i][j] == -1 or dist[0][i][j] < dist[1][i][j]))
                ans = min(ans, dist[0][i][j] + 1);
        }
    }

    if (ans == INF)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", ans);

    return 0;
}
