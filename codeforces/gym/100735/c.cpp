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
using state = tuple<int, int, int, int>;

constexpr int MAXN = 30;
int n, m;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN][MAXN];
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, -1, 0, 1};

inline bool safe(int nx, int ny) {
    return 0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] != 'X';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    int ax, ay, gx, gy;
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                grid[i][j] = '.';
                ax = i;
                ay = j;
            } else if (grid[i][j] == 'G') {
                grid[i][j] = '.';
                gx = i;
                gy = j;
            }
        }
    }

    int lvl = 0;
    queue<state> q;
    q.push(make_tuple(ax, ay, gx, gy));
    vis[ax][ay][gx][gy] = true;

    while (!q.empty()) {
        int sz = q.size();
        while (sz-- > 0) {
            tie(ax, ay, gx, gy) = q.front();
            q.pop();
            // printf("State (%d, %d), (%d, %d)\n", ax, ay, gx, gy);

            if (grid[ax][ay] == 'P') {
                printf("%d\n", lvl);
                return 0;
            }

            for (int d = 0; d < 4; ++d) {
                int nx = ax + dx[d];
                int ny = ay + dy[d];

                // printf("Considering a = (%d, %d)\n", nx, ny);
                if (safe(nx, ny)) {
                    if (nx == gx and ny == gy) continue;

                    int ngx = gx;
                    int ngy = gy;
                    if (ngx == gx and ngy == gy and ny < gy and safe(gx, gy - 1)) {
                        ngx = gx;
                        ngy = gy - 1;
                    }

                    if (ngx == gx and ngy == gy and ny > gy and safe(gx, gy + 1)) {
                        ngx = gx;
                        ngy = gy + 1;
                    }

                    if (ngx == gx and ngy == gy and nx < gx and safe(gx - 1, gy)) {
                        ngx = gx - 1;
                        ngy = gy;
                    }

                    if (ngx == gx and ngy == gy and nx > gx and safe(gx + 1, gy)) {
                        ngx = gx + 1;
                        ngy = gy;
                    }

                    if ((nx == ngx and ny == ngy) or vis[nx][ny][ngx][ngy]) continue;

                    vis[nx][ny][ngx][ngy] = true;
                    q.push(make_tuple(nx, ny, ngx, ngy));
                }
            }
        }

        ++lvl;
    }

    printf("%d\n", -1);

    return 0;
}
