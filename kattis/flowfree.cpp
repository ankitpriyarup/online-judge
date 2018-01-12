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

char orig[10][10];
char grid[10][10];
char colors[] = "RGBY";
pii tips[4][2];
bool solved = false;
int total;
bool vis[10][10];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x1, int y1, int x2, int y2) {
    if (x1 == x2 and y1 == y2)
        return 1;

    vis[x1][y1] = true;

    int res = -1000;
    for (int d = 0; d < 4; ++d) {
        int nx = x1 + dx[d];
        int ny = y1 + dy[d];
        if (0 <= nx and nx < 4 and 0 <= ny and ny < 4 and grid[nx][ny] == grid[x1][y1] and !vis[nx][ny]) {
            res = max(res, 1 + dfs(nx, ny, x2, y2));
        }
    }

    vis[x1][y1] = false;

    // printf("dfs(%d, %d) = %d\n", x1, y1, res);
    return res;
}

bool verify() {
    int tot = 0;
    for (int x = 0; x < total; ++x) {
        memset(vis, 0, sizeof(vis));
        // printf("Path from %d %d to %d %d\n", tips[x][0].first, tips[x][0].second, tips[x][1].first, tips[x][1].second);

        int ans = dfs(tips[x][0].first, tips[x][0].second, tips[x][1].first, tips[x][1].second);
        tot += ans;
        // printf("color %c has path len %d\n", colors[x], ans);
    }

    return solved = tot == 16;
}

void brute(int x, int y) {
    if (solved)
        return;

    if (x == 3 and y == 4) {
        /*
        printf("Attempt: \n");
        for (int i = 0; i < 4; ++i)
            printf("%s\n", grid[i]);
        printf("\n");
        */

        if (verify()) {
            solved = true;
        }

        return;
    }

    if (y == 4) {
        brute(x + 1, 0);
        return;
    }

    if (grid[x][y] == 'W') {
        for (int c = 0; c < total; ++c) {
            grid[x][y] = colors[c];

            brute(x, y + 1);
            if (solved)
                break;

            grid[x][y] = 'W';
        }
    } else {
        brute(x, y + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    colors[0] = 'R';
    colors[1] = 'G';
    colors[2] = 'B';
    total = 3;
    int p[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; ++i) {
        scanf("%s", orig[i]);
        for (int j = 0; j < 4; ++j) {
            grid[i][j] = orig[i][j];
            if (grid[i][j] == 'Y')
                total = 4;

            if (grid[i][j] != 'W') {
                int x = 0;
                while (colors[x] != grid[i][j]) ++x;
                tips[x][p[x]++] = {i, j};
            }
        }
    }

    brute(0, 0);
    printf("%ssolvable\n", solved ? "" : "not ");

    return 0;
}
