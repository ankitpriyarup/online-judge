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

constexpr int MAXN = 105;
int n, m;
using state = pair<int, pair<int, int> >;

int car_speed, man_speed, max_dist;
int grid[MAXN][MAXN];
int dist[2][MAXN][MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dijkstra(int layer, int sx, int sy, int speed) {
    dist[layer][sx][sy] = 0;
    priority_queue<state, vector<state>, greater<state> > pq;
    pq.push({0, {sx, sy}});
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        int cur_dist = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;
        if (dist[layer][x][y] < cur_dist) {
            continue;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                int new_dist = cur_dist + (grid[nx][ny] / speed);
                if (dist[layer][nx][ny] == -1 or new_dist < dist[layer][nx][ny]) {
                    dist[layer][nx][ny] = new_dist;
                    pq.push({new_dist, {nx, ny}});
                }
            }
        }
    }
}

int main() {
    scanf("%d", &car_speed);
    scanf("%d", &man_speed);
    scanf("%d", &max_dist);

    int carx, cary, manx, many;
    scanf("%d %d", &carx, &cary);
    scanf("%d %d", &manx, &many);
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    memset(dist, -1, sizeof(dist));
    dijkstra(0, carx, cary, car_speed);
    dijkstra(1, manx, many, man_speed);

    /*
    for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", dist[k][i][j]);
        }
        printf("\n");
    }

    printf("\n");
    }
    */

    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (man_speed * dist[1][i][j] > max_dist) {
                continue;
            }

            if (dist[0][i][j] >= dist[1][i][j]) {
                ans = min(ans, dist[0][i][j]);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
