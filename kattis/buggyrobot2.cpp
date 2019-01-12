#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 56;
constexpr int oo = 987654321;
int n, m, c;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];
char orders[MAXN];
int to_dir[300];

struct edge {
    int x, y, pos, cost;
};

vector<edge> graph[MAXN][MAXN][MAXN];

int sx, sy;
int gx, gy;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool in_bounds(const int& x, const int& y) {
    return 0 <= x and x < n
        and 0 <= y and y < m
        and grid[x][y] != '#';
}

void read() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'R') {
                sx = i;
                sy = j;

                grid[i][j] = '.';
            } else if (grid[i][j] == 'E') {
                gx = i;
                gy = j;

                grid[i][j] = '.';
            }
        }
    }

    scanf("%s", orders);
    c = strlen(orders);

    to_dir['U'] = 2;
    to_dir['D'] = 0;
    to_dir['L'] = 3;
    to_dir['R'] = 1;
}

void make_graph() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // delete
            for (int k = 0; k < c; ++k) {
                graph[i][j][k].push_back({i, j, k + 1, 1});
            }

            // use
            for (int k = 0; k < c; ++k) {
                int nx = i + dx[to_dir[orders[k]]];
                int ny = j + dy[to_dir[orders[k]]];

                if (in_bounds(nx, ny)) {
                    graph[i][j][k].push_back({nx, ny, k + 1, 0});
                } else {
                    graph[i][j][k].push_back({i, j, k + 1, 0});
                }
            }

            // move
            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (in_bounds(nx, ny)) {
                    for (int k = 0; k <= c; ++k) {
                        graph[i][j][k].push_back({nx, ny, k, 1});
                    }
                }
            }
        }
    }
}

int bfs() {
    deque<edge> dq;

    // x, y, layer, cost
    dq.push_back({sx, sy, 0, 0});

    int ans = 987654321;
    while (!dq.empty()) {
        edge e = dq.front();
        dq.pop_front();

        if (dist[e.x][e.y][e.pos] != -1) continue;

        dist[e.x][e.y][e.pos] = e.cost;

        if (e.x == gx and e.y == gy) {
            ans = min(ans, e.cost);
        }

        for (edge child : graph[e.x][e.y][e.pos]) {
            if (dist[child.x][child.y][child.pos] == -1) {
                if (child.cost == 0) {
                    dq.push_front({child.x, child.y, child.pos, e.cost});
                } else {
                    dq.push_back({child.x, child.y, child.pos, e.cost + 1});
                }
            }
        }
    }

    return ans;
}

int main() {
    read();
    make_graph();

    memset(dist, -1, sizeof(dist));
    int ans = bfs();

    printf("%d\n", ans);
    return 0;
}
