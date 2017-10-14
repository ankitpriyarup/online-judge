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

constexpr int MAXN = 22;
int n;
char grid[MAXN][MAXN];
bool used[MAXN][MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int moves;
int ans[15];

bool done() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != grid[0][0]) {
                return false;
            }
        }
    }

    return true;
}

vector<pii> bfs1() {
    // get everything connected to the origin
    vector<pii> res;
    queue<pii> q;

    memset(used, 0, sizeof(used));

    q.push({0, 0});
    res.push_back({0, 0});
    used[0][0] = true;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (0 <= nx and nx < n and 0 <= ny and ny < n and !used[nx][ny] and grid[nx][ny] == grid[0][0]) {
                used[nx][ny] = true;
                q.push({nx, ny});
                res.push_back({nx, ny});
            }
        }
    }

    return res;
}

int bfs2(vector<pii>& src, char c, bool overwrite) {
    // change the origin and anything matching the origin to 'c'
    queue<pii> q;
    memset(used, 0, sizeof(used));

    for (pii pt : src) {
        if (overwrite) {
            grid[pt.first][pt.second] = c;
        }

        q.push(pt);
        used[pt.first][pt.second] = true;
    }

    int seen = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        ++seen;
        int x = cur.first;
        int y = cur.second;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (0 <= nx and nx < n and 0 <= ny and ny < n) {
                if (!used[nx][ny] and grid[nx][ny] == c) {
                    q.push({nx, ny});
                    used[nx][ny] = true;
                    grid[nx][ny] = c;
                }
            }
        }
    }

    return seen;
}

void solve() {
    while (!done()) {
        ++moves;
        int best = '0';
        int comp = -1;

        vector<pii> src = bfs1();
        for (char c = '1'; c <= '6'; ++c) {
            if (c == grid[0][0]) continue;

            int moves = bfs2(src, c, false);
            if (moves > comp) {
                comp = moves;
                best = c;
            }
        }

        bfs2(src, best, true);
        ++ans[best - '0'];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", grid[i]);
        }

        moves = 0;
        memset(ans, 0, sizeof(ans));
        solve();

        printf("%d\n", moves);
        for (int i = 1; i <= 6; ++i) {
            printf("%d%c", ans[i], i != 6 ? ' ' : '\n');
        }
    }

    return 0;
}

