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

constexpr int MAXN = 30;
constexpr int MAXK = 200;
int n, m, k;
int have[MAXN][MAXN];
char grid[MAXN][MAXN];
int sols = 0;
bool printed = false;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char markers[][5] = {"nu", "[]", "un", "]["};

void print() {
    for (int i = 0; i < n; ++i)
        printf("%s\n", grid[i]);
}

void dfs(int x, int y) {
    if (x == n) {
        if (!printed)
            print();
        printed = true;
        ++sols;
        return;
    }

    if (y == m) {
        dfs(x + 1, 0);
        return;
    }
    if (grid[x][y] > 9) {
        dfs(x, y + 1);
        return;
    }

    // printf("At %d, %d\n", x, y);
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        // printf("next: %d, %d\n", nx, ny);
        if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] <= 9) {
            // printf("valid\n");
            int a = grid[x][y];
            int b = grid[nx][ny];

            // printf("Looking for %d, %d at pos %d %d\n", a, b, x, y);
            if (have[a][b]) {
                // printf("Found!\n");
                char oldx = grid[x][y];
                char oldnx = grid[nx][ny];
                grid[x][y] = markers[d][0];
                grid[nx][ny] = markers[d][1];
                have[a][b] = false;
                have[b][a] = false;

                dfs(x, y + 1);

                have[a][b] = true;
                have[b][a] = true;
                grid[x][y] = oldx;
                grid[nx][ny] = oldnx;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf(" %d %d %d", &n, &m, &k) == 3) {
        if (!n) break;

        int x, y;
        memset(have, false, sizeof(have));
        for (int i = 0; i < k; ++i) {
            scanf(" %d %d", &x, &y);
            have[x][y] = true;
            have[y][x] = true;
        }

        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf(" %c", &grid[i][j]);
                if ('0' <= grid[i][j] and grid[i][j] <= '9') {
                    grid[i][j] -= '0';
                }
            }
        }

        sols = 0;
        printed = false;
        dfs(0, 0);

        if (!sols) {
            printf("impossible\n");
        } else { 
            printf("%d\n", sols - 1);
        }
        printf("\n");
    }

    return 0;
}
