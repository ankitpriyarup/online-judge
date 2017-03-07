#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 505;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
int a, b;
// true means you can walk there
bool grid[MAXN][MAXN];

char row[MAXN];

struct state {
    int x, y, dist;
    bool is_town;

    bool operator<(const state& other) const {
        return other.dist < dist;
    }
};

inline bool in_bounds(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m;
}

void read() {
    scanf("%d %d", &m, &n);
    scanf("%d %d", &a, &b);
    memset(grid, false, sizeof(grid));

    for (int i = 0; i < n; ++i) {
        scanf("%s", row);
        for (int j = 0; j < m; ++j) {
            grid[i][j] = (row[j] == '.');
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d", grid[i][j]);
        }
        puts("");
    }
    */
}

void solve() {
    if (!grid[0][0] or !grid[n - 1][m - 1]) {
        puts("IMPOSSIBLE");
        return;
    }

    state start = {0, 0, 0, true};
    priority_queue<state> pq;
    pq.push(start);

    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        if (cur.x == n - 1 and cur.y == m - 1) {
            printf("%d\n", cur.dist);
            return;
        }

        if (!grid[cur.x][cur.y]) continue;

        grid[cur.x][cur.y] = false;

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if (in_bounds(nx, ny) and grid[nx][ny]) {
                state next_state = {nx, ny, cur.dist + (cur.is_town ? b : a), !cur.is_town};
                pq.push(next_state);
            }
        }
    }

    puts("IMPOSSIBLE");
}

int main() {
    read();
    solve();
    return 0;
}
