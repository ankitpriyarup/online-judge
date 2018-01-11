#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 1003;
int n, m;
char grid[MAXN][MAXN];

struct state {
    int x, y, dir, turns;
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool visit[MAXN][MAXN][5][5];

inline int in_bounds(const int& x, const int& y) {
    return 0 <= x and x < n
        and 0 <= y and y < m
        and grid[x][y] != '*';
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &m);

    int sx, sy, tx, ty;
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                grid[i][j] = '.';
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'T') {
                grid[i][j] = '.';
                tx = i;
                ty = j;
            }
        }
    }

    queue<state> q;

    for (int d = 0; d < 4; ++d) {
        q.push({sx, sy, d, 0});
        visit[sx][sy][d][0] = true;
    }

    bool found = false;
    while (!q.empty()) {
        state s = q.front();
        q.pop();

        if (s.turns > 2) continue;

        // printf("%d %d %d %d\n", s.x, s.y, s.dir, s.turns);

        if (s.x == tx and s.y == ty) {
            found = true;
            break;
        }

        int nx = s.x + dx[s.dir];
        int ny = s.y + dy[s.dir];

        if (in_bounds(nx, ny) and !visit[nx][ny][s.dir][s.turns]) {
            visit[nx][ny][s.dir][s.turns] = true;
            q.push({nx, ny, s.dir, s.turns});
        }

        for (int d = 0; d < 4; ++d) {
            if (d == s.dir) continue;

            nx = s.x + dx[d];
            ny = s.y + dy[d];

            if (in_bounds(nx, ny) and !visit[nx][ny][d][s.turns + 1]) {
                visit[nx][ny][d][s.turns + 1] = true;
                q.push({nx, ny, d, s.turns + 1});
            }
        }
    }

    printf("%s\n", found ? "YES" : "NO");

    return 0;
}
