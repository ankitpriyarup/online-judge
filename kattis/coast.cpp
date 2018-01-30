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
int n, m;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y) {
    if (vis[x][y])
        return;

    vis[x][y] = true;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (0 <= nx and nx < n and 0 <= ny and ny < m) {
            if (grid[nx][ny] == '1')
                ++ans;
            else
                dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    ans = 0;
    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == '1') {
            ++ans;
        } else {
            dfs(i, 0);
        }

        if (grid[i][m - 1] == '1') {
            ++ans;
        } else {
            dfs(i, m - 1);
        }
    }

    for (int j = 0; j < m; ++j) {
        if (grid[0][j] == '1') {
            ++ans;
        } else {
            dfs(0, j);
        }

        if (grid[n - 1][j] == '1') {
            ++ans;
        } else {
            dfs(n - 1, j);
        }
    }

    printf("%d\n", ans);

    return 0;
}
