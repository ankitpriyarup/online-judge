#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

int n, m;
int gx, gy;
int grid[15][15];
bool used[15][15];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ans = 0;

void dfs(int x, int y, int rem, int candy) {
    if (x == gx and y == gy) {
        ans = max(ans, candy);
        return;
    }

    if (rem == 0) {
        return;
    }

    used[x][y] = true;

    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (0 <= nx and nx < n and 0 <= ny and ny < m and !used[nx][ny]) {
            dfs(nx, ny, rem - 1, candy + grid[nx][ny]);
        }
    }

    used[x][y] = false;
}

int main() {
    int max, sy, sx;
    scanf("%d %d %d %d %d %d %d", &n, &m, &max, &sx, &sy, &gx, &gy);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    dfs(sx, sy, max, grid[sx][sy]);

    printf("%d\n", ans);

    return 0;
}
