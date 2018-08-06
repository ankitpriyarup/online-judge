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

int orig[4];
int need[4];
int found[4];

char grid[55][55];
bool vis[55][55];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y, char c) {
    if (x < 0 or y < 0 or x >= 50 or y >= 50 or vis[x][y] or grid[x][y] != c)
        return;
    vis[x][y] = true;
    for (int d = 0; d < 4; ++d)
        dfs(x + dx[d], y + dy[d], c);
}

void check() {
    memset(vis, 0, sizeof(vis));
    memset(found, 0, sizeof(found));
    int n = 50;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                ++found[grid[i][j] - 'A'];
                dfs(i, j, grid[i][j]);
            }
        }
    }
}

int min_val(int skip = -1) {
    int res = 1e9 + 7;
    for (int k = 0; k < 4; ++k) {
        if (k == skip) continue;
        res = min(res, need[k]);
    }

    return res;
}

int max_val(int skip = -1) {
    int res = -1;
    for (int k = 0; k < 4; ++k) {
        if (k == skip) continue;
        res = max(res, need[k]);
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int lo = 0;
    for (int k = 0; k < 4; ++k) {
        scanf(" %d", &orig[k]);
        need[k] = orig[k];
        if (need[k] < need[lo])
            lo = k;
    }

    int n = 50;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = ('A' + lo);
        }
        grid[i][n] = '\0';
    }
    --need[lo];

    int color = 0;
    int last_color = -1;
    for (int i = n - 3; max_val(lo) > 0 and i >= 0; i -= 4) {
        for (int j = 0; max_val(lo) > 0 and j + 3 < n; j += 3) {
            color = (color + 1) % 4;
            while (color == lo or need[color] == 0) {
                color = (color + 1) % 4;
            }

            if (color == last_color) {
                last_color = -1;
                color = (color + 3) % 4;
                continue;
            }

            for (int dx = 0; dx < 3; ++dx) {
                for (int dy = 0; dy < 3; ++dy) {
                    grid[i + dx][j + dy] = 'A' + color;
                }
            }

            last_color = color;
            --need[color];
            if (need[lo]) {
                --need[lo];
                grid[i + 1][j + 1] = 'A' + lo;
            } else {
                for (int k = 0; k < 4; ++k) {
                    if (k == color) continue;
                    if (need[k] > 0) {
                        --need[k];
                        grid[i + 1][j + 1] = 'A' + k;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; max_val() > 0 and i < n; i += 2) {
        for (int k = 0; k < 4; ++k) {
            if (need[k] == 0 or k == lo)
                continue;
            --need[k];
            grid[i][n - 1] = 'A' + k;
            break;
        }
    }

    printf("%d %d\n", n, n);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", grid[i]);
    }

    /*
    check();

    for (int k = 0; k < 4; ++k)
        printf("%d ", need[k]);
    printf("\n");

    for (int k = 0; k < 4; ++k)
        printf("%d ", found[k]);
    printf("\n");
    */
    return 0;
}
