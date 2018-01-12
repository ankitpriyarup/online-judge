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
using pii = pair<int, int>;

constexpr int MAXN = 505;
int n, m;
char grid[MAXN][MAXN];
char new_grid[MAXN][MAXN];
// bit for if there's a wall or not
int walls[MAXN][MAXN];
bool contained[MAXN][MAXN];
bool scanned[MAXN][MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int do_scan(int sx, int sy) {
    // printf("Starting from %d %d\n", sx, sy);
    queue<pii> q;
    q.push({sx, sy});
    scanned[sx][sy] = true;

    int ans = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < n and 0 <= ny and ny < m and !scanned[nx][ny] and (walls[x][y] & (1 << d)) == 0) {
                scanned[nx][ny] = true;
                if (grid[nx][ny] == 'S') {
                    // printf("Would infect %d %d\n", nx, ny);
                    ++ans;
                } else {
                    q.push({nx, ny});
                }
            }
        }
    }

    return ans;
}

void quarantine(int sx, int sy) {
    queue<pii> q;
    q.push({sx, sy});
    contained[sx][sy] = true;

    int ans = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < n and 0 <= ny and ny < m and !contained[nx][ny]) {
                if (grid[nx][ny] == 'S') {
                    walls[x][y] |= (1 << d);
                } else {
                    contained[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void expand() {
    memcpy(new_grid, grid, sizeof(grid));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'C' and !contained[i][j]) {
                for (int d = 0; d < 4; ++d) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                        new_grid[nx][ny] = 'C';
                    }
                }
            }
        }
    }

    memcpy(grid, new_grid, sizeof(grid));
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    while (true) {
        bool found_any = false;

        int worst = -1;
        int sx = 0;
        int sy = 0;

        /*
        for (int i = 0; i < n; ++i) {
            printf("%s\n", grid[i]);
        }
        printf("\n");
        */

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'C' and !contained[i][j]) {
                    memset(scanned, 0, sizeof(scanned));
                    int impact = do_scan(i, j);
                    if (impact > worst) {
                        found_any = true;
                        worst = impact;
                        sx = i;
                        sy = j;
                    }
                }
            }
        }

        if (worst == -1) {
            break;
        }

        // printf("Worst infects %d at pt %d %d\n", worst, sx, sy);

        quarantine(sx, sy);
        expand();
    }

    int total_walls = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            total_walls += __builtin_popcount(walls[i][j]);
        }
    }

    printf("%d\n", total_walls);

    return 0;
}
