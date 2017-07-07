/*
USER: rednano1
PROG: snail
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <complex>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 122;

int n, b;
int grid[MAXN][MAXN];

char command[10];

int ans = 0;
int cur = 0;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void print_grid() {
    char tile[] = ".o#";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", tile[grid[i][j]]);
        }
        printf("\n");
    }
    printf("\n");
}

inline bool in_bounds(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < n;
}

bool can_go(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (!in_bounds(nx, ny) or grid[nx][ny] != 0) {
        return false;
    }

    while (in_bounds(nx, ny) and grid[nx][ny] != 2) {
        if (grid[nx][ny] == 1) return false;

        nx += dx[dir];
        ny += dy[dir];
    }

    return true;
}

void dfs(int x, int y, int dir) {
    ans = max(ans, cur);
    if (can_go(x, y, dir)) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        while (in_bounds(nx, ny) and grid[nx][ny] != 2) {
            grid[nx][ny] = 1;
            ++cur;

            nx += dx[dir];
            ny += dy[dir];
        }

        ans = max(ans, cur);
        nx -= dx[dir];
        ny -= dy[dir];

        dfs(nx, ny, dir ^ 1);
        dfs(nx, ny, dir ^ 3);

        while (nx != x or ny != y) {
            grid[nx][ny] = 0;
            --cur;

            nx -= dx[dir];
            ny -= dy[dir];
        }
    } else {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        int tmp = 0;

        while (in_bounds(nx, ny) and grid[nx][ny] == 0) {
            ++tmp;
            nx += dx[dir];
            ny += dy[dir];
        }

        ans = max(ans, cur + tmp);
    }
}

int main() {
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);

    scanf("%d %d", &n, &b);

    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < b; ++i) {
        scanf("%s", command);
        int row = atoi(&command[1]) - 1;
        int col = command[0] - 'A';
        grid[row][col] = 2;
    }

    ans = 0;
    cur = 0;

    dfs(0, 0, 0);
    dfs(0, 0, 1);

    printf("%d\n", ans + 1);

    return 0;
}
