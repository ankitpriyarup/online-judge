#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int N, M;
bool railway[404][404];

int bfs(bool rail) {
    bool visited[404];
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == N - 1) {
            return cur.second;
        }

        for (int i = 1; i < N; ++i) {
            if (!visited[i] && ((rail && railway[cur.first][i]) || (!rail && !railway[cur.first][i]))) {
                visited[i] = true;
                q.push(make_pair(i, cur.second + 1));
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;

    int x, y;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        x--; y--;
        railway[x][y] = railway[y][x] = 1;
    }

    int ans;
    if (railway[0][N - 1]) {
        ans = bfs(0);
    } else {
        ans = bfs(1);
    }

    if (ans == -1) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}
