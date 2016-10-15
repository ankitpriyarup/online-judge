#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n, m;
char grid[10004][10004];
bool visit[10004][10004];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                sx = i;
                sy = j;
            }
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    memset(visit, false, sizeof(visit));

    int ans = -1;
    int dist = 0;
    while (ans < 0 and !q.empty()) {
        int num = q.size();
        while (ans < 0 and num-- > 0) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            //cout << x << ' ' << y << ' ' << dist << '\n';

            if (visit[x][y]) {
                continue;
            }

            visit[x][y] = true;

            if (grid[x][y] == 'S') {
                ans = dist;
                break;
            }

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] != 'X') {
                    q.push(make_pair(nx, ny));
                }
            }
        }

        ++dist;
    }

    cout << ans << '\n';

    return 0;
}
