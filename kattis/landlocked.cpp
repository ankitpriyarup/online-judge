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
int dist[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // run a 0-1 bfs, starting from all the water.
    // find the distance from the water to each cell
    // dist 0 if you stay in your kind, dist 1 otherwise
    // then run through and get answers for all the rest
    scanf(" %d %d", &n, &m);
    memset(dist, -1, sizeof(dist));

    deque<pii> dq;
    for (int i = 0; i < n; ++i) {
        scanf(" %s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'W') {
                dq.emplace_back(i, j);
                dist[i][j] = 0;
            }
        }
    }

    int x, y;
    while (!dq.empty()) {
        tie(x, y) = dq.front();
        dq.pop_front();

        // printf("-- At (%d, %d) with dist %d\n", x, y, d);
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 and dy == 0) continue;

                int nx = x + dx;
                int ny = y + dy;
                if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                    int w = grid[x][y] != grid[nx][ny];
                    int new_dist = dist[x][y] + w;
                    if (dist[nx][ny] == -1 or new_dist < dist[nx][ny]) {
                        dist[nx][ny] = new_dist;
                        if (w) {
                            dq.emplace_back(nx, ny);
                        } else {
                            dq.emplace_front(nx, ny);
                        }
                    }
                }
            }
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        printf("-- ");
        for (int j = 0; j < m; ++j) {
            printf("%d", dist[i][j]);
        }
        printf("\n");
    }
    */

    int ans[26];
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'W')
                continue;

            int c = grid[i][j] - 'A';
            if (ans[c] == -1 or dist[i][j] < ans[c])
                ans[c] = dist[i][j];
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (ans[i] != -1) {
            printf("%c %d\n", i + 'A', ans[i] - 1);
        }
    }

    return 0;
}
