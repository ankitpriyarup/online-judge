#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

char grid[505][505];

typedef pair<int, int> pt;
typedef pair<int, pt> state;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool visit[505][505];

int n, m;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            grid[i][j] -= '0';
        }
    }

    priority_queue<state, vector<state>, greater<state> > pq;

    pq.push(make_pair(0, make_pair(0, 0)));

    memset(visit, 0, sizeof(visit));
    int ans = -1;
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        int moves = cur.first;
        pt loc = cur.second;
        int x = loc.first;
        int y = loc.second;
        if (visit[x][y]) {
            continue;
        }

        if (x == n - 1 and y == m - 1) {
            ans = moves;
            break;
        }

        visit[x][y] = true;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d] * grid[x][y];
            int ny = y + dy[d] * grid[x][y];
            if (nx >= 0 and ny >= 0 and nx < n and ny < m and !visit[nx][ny]) {
                pq.push(make_pair(moves + 1, make_pair(nx, ny)));
            }
        }
    }

    if (ans < 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << '\n';
    }

    return 0;
}
