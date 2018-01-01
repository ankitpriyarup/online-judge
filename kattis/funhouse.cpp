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

int n, m;
constexpr int MAXN = 30;
char grid[MAXN][MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void find_start(int& sx, int& sy, int& dir) {
    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == '*') {
            sx = i;
            sy = 0;
            dir = 1;
            return;
        } else if (grid[i][m - 1] == '*') {
            sx = i;
            sy = m - 1;
            dir = 3;
            return;
        }
    }

    for (int j = 0; j < m; ++j) {
        if (grid[0][j] == '*') {
            sx = 0;
            sy = j;
            dir = 0;
            return;
        } else if (grid[n - 1][j] == '*') {
            sx = n - 1;
            sy = j;
            dir = 2;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    while (true) {
        scanf("%d %d", &m, &n);
        if (m == 0 or n == 0) break;

        for (int i = 0; i < n; ++i)
            scanf("%s", grid[i]);

        // try each starting spot
        int sx = 0;
        int sy = 0;
        int dir = 0;
        find_start(sx, sy, dir);

        sx += dx[dir];
        sy += dy[dir];

        while ((sx != 0 and sx != n - 1) and (sy != 0 and sy != m - 1)) {
            if (grid[sx][sy] == '/') {
                // 0 -> 3, 1 -> 2, 2 -> 1, 3 -> 0
                dir = dir ^ 3;
            } else if (grid[sx][sy] == '\\') {
                // 0 -> 1, 1 -> 0, 2-> 3, 3 -> 2
                dir = dir ^ 1;
            }

            sx += dx[dir];
            sy += dy[dir];
        }

        grid[sx][sy] = '&';

        printf("HOUSE %d\n", tc++);
        for (int i = 0; i < n; ++i) {
            printf("%s\n", grid[i]);
        }
    }

    return 0;
}
