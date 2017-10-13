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

constexpr int MAXN = 55;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};

int n, m, k;
char grid[MAXN][MAXN];

pii dist[MAXN][MAXN];
int f[300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    f['.'] = 1;
    f['F'] = 2;
    f['M'] = 3;

    scanf("%d %d %d", &n, &m, &k);
    int sx, sy;
    int gx, gy;
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
                grid[i][j] = '.';
            } else if (grid[i][j] == 'G') {
                gx = i;
                gy = j;
                grid[i][j] = '.';
            }

            dist[i][j] = {-1, -1};
        }
    }

    priority_queue<pair<pii, pii>, vector<pair<pii, pii> >, greater<pair<pii, pii> > > pq;
    pq.push({{1, -k}, {sx, sy}});
    dist[sx][sy] = {1, -k};

    while (!pq.empty()) {
        pair<pii, pii> state = pq.top();
        pq.pop();

        pii cur_dist = state.first;
        int x = state.second.first;
        int y = state.second.second;

        if (dist[x][y] < cur_dist) {
            continue;
        }

        if (x == gx and y == gy)
            break;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] != '#') {
                int cost = f[grid[nx][ny]];
                if (k - cost < 0) {
                    continue;
                }

                pii new_dist;
                if (cur_dist.second + cost > 0) {
                    new_dist = {cur_dist.first + 1, -k + cost};
                } else {
                    new_dist = {cur_dist.first, cur_dist.second + cost};
                }

                if (dist[nx][ny].first == -1 or new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    pq.push({new_dist, {nx, ny}});
                }
            }
        }
    }

    printf("%d\n", dist[gx][gy].first);

    return 0;
}
