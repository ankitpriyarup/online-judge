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

constexpr int MAXN = 102;
int n, m, k;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, -1, 0, 1};
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    vis[0][0] = true;
    queue<pii> q;
    q.push({0, 0});
    int x, y;
    int ans = grid[0][0];
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < n and 0 <= ny and ny < m and abs(grid[nx][ny] - grid[x][y]) <= k and !vis[nx][ny]) {
                vis[nx][ny] = true;
                ans = max(ans, grid[nx][ny]);
                q.push({nx, ny});
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
