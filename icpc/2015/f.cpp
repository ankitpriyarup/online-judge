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

constexpr int MAXN = 55;
constexpr int INF = 1e9 + 8;
constexpr int MAXV = 22222;
int n, m;
char grid[MAXN][MAXN];
char text[MAXV];
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, -1, 0, 1};

bool in_bounds(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m;
}

int dist[MAXV][MAXN][MAXN];
int translate[4][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }
    scanf("%s", text);

    for (int i = 0; i < n; ++i) {
        translate[1][i][0] = -1;
        for (int j = 1; j < m; ++j) {
            if (grid[i][j] != grid[i][j - 1]) {
                translate[1][i][j] = j - 1;
            } else {
                translate[1][i][j] = translate[1][i][j - 1];
            }
        }

        translate[3][i][m - 1] = m;
        for (int j = m - 2; j >= 0; --j) {
            if (grid[i][j] != grid[i][j + 1]) {
                translate[3][i][j] = j + 1;
            } else {
                translate[3][i][j] = translate[3][i][j + 1];
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        translate[0][n - 1][j] = n;
        for (int i = n - 2; i >= 0; --i) {
            if (grid[i][j] != grid[i + 1][j]) {
                translate[0][i][j] = i + 1;
            } else {
                translate[0][i][j] = translate[0][i + 1][j];
            }
        }

        translate[2][0][j] = -1;
        for (int i = 1; i < n; ++i) {
            if (grid[i][j] != grid[i - 1][j]) {
                translate[2][i][j] = i - 1;
            } else {
                translate[2][i][j] = translate[2][i - 1][j];
            }
        }
    }

    int len = strlen(text);
    text[len] = '*';
    ++len;

    for (int p = 0; p <= len; ++p)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dist[p][i][j] = INF;

    queue<tuple<int, int, int> > q;
    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 0;

    int p, x, y;
    int ans = INF;
    while (!q.empty()) {
        tie(p, x, y) = q.front();
        q.pop();

        if (p == len) {
            ans = dist[p][x][y];
            break;
        }

        if (grid[x][y] == text[p]) {
            if (dist[p][x][y] + 1 < dist[p + 1][x][y]) {
                // printf("Edge from (%d %d %d) -> (%d %d %d)\n", p, x, y, p + 1, x, y);
                dist[p + 1][x][y] = dist[p][x][y] + 1;
                q.push(make_tuple(p + 1, x, y));
            }
        }

        for (int d = 0; d < 4; ++d) {
            int nx, ny;
            if (d & 1) {
                nx = x;
                ny = translate[d][x][y];
            } else {
                nx = translate[d][x][y];
                ny = y;
            }

            if (!in_bounds(nx, ny))
                continue;

            int nd = dist[p][x][y] + 1;
            if (nd < dist[p][nx][ny]) {
                // printf("Edge from (%d %d %d) -> (%d %d %d)\n", p, x, y, p, nx, ny);
                dist[p][nx][ny] = nd;
                q.push(make_tuple(p, nx, ny));
            }
        }
    }

    // ans += len;

    printf("%d\n", ans);
    return 0;
}
