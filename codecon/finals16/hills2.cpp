#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits> 

using namespace std;

int R, C;
int Sx, Sy;
int grid[30][30];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
bool visited[30][30][4];

int dfs(int x, int y, int diff, int cur, int speed, int lastdir) {
    int ans = cur;
    speed = min(speed, 50);

    //printf("%d %d %d %d %d %d\n", x, y, diff, cur, speed, lastdir);
    //printf("%d\n", (lastdir + 2) % 4);

    for (int d = 0; d < 4; ++d) {

        if ((lastdir + 2) % 4 == d) {
            continue;
        }
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 and ny >= 0 and nx < R and ny < C and !visited[nx][ny][d]) {
            int old = grid[x][y];
            int nh = grid[nx][ny];
            if (nh > old) {
                int up = nh - old;
                if (up * 5 <= speed) {
                    ans = max(ans, dfs(nx, ny, -1, cur + 1, speed - 5 * up, d));
                    visited[nx][ny][d] = true;
                }
            } else if (diff == -1) {
                ans = max(ans, dfs(nx, ny, old - nh, cur + 1, speed + old - nh, d));
                visited[nx][ny][d] = true;
            } else if (old - nh == diff) {
                ans = max(ans, dfs(nx, ny, diff, cur + 1, speed + old - nh, d));
                visited[nx][ny][d] = true;
            }
        }
    }

    return ans;
}

int main() {
    cin >> R >> C;
    cin >> Sx >> Sy;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));
    cout << dfs(Sx, Sy, -1, 0, 0, -1) << '\n';
    return 0;
}
