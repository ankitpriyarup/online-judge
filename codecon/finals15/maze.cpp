#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int R, C;
char grid[102][102];
int prevX[102][102];
int prevY[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int px, int py) {
    if (prevX[x][y] != -1 and prevY[x][y] != -1) {
        return;
    }

    prevX[x][y] = px;
    prevY[x][y] = py;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C || grid[nx][ny] == 'X')
            continue;

        dfs(nx, ny, x, y);
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
    }

    memset(prevX, -1, sizeof(prevX));
    memset(prevY, -1, sizeof(prevY));

    dfs(1, 0, -1, -1);
    prevX[1][0] = -1;
    prevY[1][0] = -1;

    vector<pair<int, int> > ans;
    int x = R - 2;
    int y = C - 1;

    while (x != -1 && y != -1) {
        ans.push_back(make_pair(x, y));
        int nx = prevX[x][y];
        int ny = prevY[x][y];

        x = nx;
        y = ny;
    }

    int N = ans.size() - 1;
    cout << "1,0\n";
    for (int i = N - 1; i >= 0; --i) {
        cout << ans[i].first << ',' << ans[i].second << '\n';
    }
    
    return 0;
}
