#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXR = 22;
int vals[3 * MAXR][3 * MAXR];
bool bad[MAXR * MAXR * MAXR];

int dx[] = {0, 1, 1, -1, -1, 0};
int dy[] = {1, 0, 1, -1, 0, -1};

int r, n, a, b, x;
int diag;
int sx, sy, gx, gy;

void read() {
    scanf("%d %d %d %d %d", &r, &n, &a, &b, &x);
    diag = 2 * r - 1;
    int v = 1;
    int on_row = r;
    int step = 1;
    int shift = 0;
    bool is_shift = false;
    memset(vals, -1, sizeof(vals));
    for (int i = 0; i < diag; ++i) {
        for (int j = shift; j < on_row + shift; ++j) {
            vals[i][j] = v++;
        }

        if (on_row == diag) {
            step = -1;
            is_shift = true;
        }

        on_row += step;
        shift += is_shift;
    }

    int y;
    memset(bad, false, sizeof(bad));
    for (int i = 0; i < x; ++i) {
        scanf("%d", &y);
        bad[y] = true;
    }

    for (int i = 0; i < diag; ++i) {
        for (int j = 0; j < diag; ++j) {
            if (vals[i][j] == a) {
                sx = i;
                sy = j;
            } else if (vals[i][j] == b) {
                gx = i;
                gy = j;
            } else if (bad[vals[i][j]]) {
                vals[i][j] = -1;
            }
        }
    }
}

int dist[3 * MAXR][3 * MAXR];

void solve() {
    queue<pii> q;
    q.push({sx, sy});
    memset(dist, -1, sizeof(dist));
    dist[sx][sy] = 0;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int d = 0; d < 6; ++d) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if (nx >= 0 and nx < diag and ny >= 0 and ny < diag and vals[nx][ny] != -1 and dist[nx][ny] == -1) {
                dist[nx][ny] = 1 + dist[cur.first][cur.second];
                q.push({nx, ny});
            }
        }
    }

    int ans = dist[gx][gy];
    if (ans == -1 or ans > n) {
        printf("No\n");
    } else {
        printf("%d\n", ans);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    read();
    solve();

    return 0;
}
