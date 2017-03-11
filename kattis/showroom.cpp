#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

const int MAXN = 404;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

struct state {
    int dist;
    int x;
    int y;

    bool operator<(const state& other) const {
        return other.dist < dist;
    }
};

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    int sx, sy;
    scanf("%d %d", &sx, &sy);
    --sx;
    --sy;

    priority_queue<state> pq;
    pq.push({1, sx, sy});

    memset(dist, -1, sizeof(dist));
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            int new_dist = -1;
            if (grid[nx][ny] == 'c') {
                new_dist = cur.dist + 1;
            } else if (grid[nx][ny] == 'D') {
                new_dist = cur.dist;
            }

            if (new_dist != -1 and (dist[nx][ny] == -1 or new_dist < dist[nx][ny])) {
                dist[nx][ny] = new_dist;
                pq.push({new_dist, nx, ny});
            }
        }
    }

    int ans = n * m;

    for (int i = 0; i < n; ++i) {
        if (dist[i][0] != -1) {
            ans = min(ans, dist[i][0]);
        }
        if (dist[i][m - 1] != -1) {
            ans = min(ans, dist[i][m - 1]);
        }
    }

    for (int j = 0; j < m; ++j) {
        if (dist[0][j] != -1) {
            ans = min(ans, dist[0][j]);
        }
        if (dist[n - 1][j] != -1) {
            ans = min(ans, dist[n - 1][j]);
        }
    }

    printf("%d\n", ans);
    return 0;
}
