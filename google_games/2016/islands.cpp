#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n, m;
char grid[400][200];
bool visit[400][200];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int bfs(int x, int y) {
    char type = grid[x][y];
    int ans = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visit[x][y] = true;

    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;
        cout << "(" << x << ", " << y << ") is visit\n";

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 or ny < 0 or nx >= n or ny >= m) 
                continue;

            if (grid[nx][ny] != type) {
                ++ans;
            }

            if (grid[nx][ny] == type and !visit[nx][ny]) {
                visit[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    memset(visit, 0, sizeof(visit));

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visit[0][0] = true;

    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;

        cout << "(" << x << ", " << y << ") is ocean\n";

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 or ny < 0 or nx >= n or ny >= m or visit[nx][ny] or grid[nx][ny] == '1') continue;

            visit[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }

    int num_islands = 0;
    int shore_islands = 0;
    int num_lakes = 0;
    int shore_lakes = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visit[i][j]) {
                cout << "Starting bfs at (" << i <<", " << j << ")\n";
                if (grid[i][j] == '0') {
                    num_lakes++;
                    int size = bfs(i, j);
                    shore_lakes += size;
                    cout << "Size: " << size << '\n';
                } else {
                    num_islands++;
                    int size = bfs(i, j);
                    shore_islands += size;
                    cout << "Size: " << size << '\n';
                }
            }
        }
    }

    cout << (num_islands + num_lakes + shore_islands) << '\n';
    return 0;
}
