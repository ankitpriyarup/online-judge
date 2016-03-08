#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

using namespace std;

int R, C;
int Sx, Sy;
int grid[30][30];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int dfs(int x, int y, int diff, int cur) {
    //printf("%d %d %d %d\n", x, y, diff, cur);
    int ans = cur;
    for (int d = 0; d < 4; ++ d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 and ny >= 0 and nx < R and ny < C and grid[x][y] - grid[nx][ny] == diff) {
            ans = max(ans, dfs(nx, ny, diff, cur + 1));
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

    int ans = 0;
    for (int d = 0; d < 4; ++d) {
        int nx = Sx + dx[d];
        int ny = Sy + dy[d];
        if (nx >= 0 and ny >= 0 and nx < R and ny < C and grid[nx][ny] < grid[Sx][Sy]) {
            ans = max(ans, dfs(nx, ny, grid[Sx][Sy] - grid[nx][ny], 1));
        }
    }

    cout << ans << '\n';
    return 0;
}
