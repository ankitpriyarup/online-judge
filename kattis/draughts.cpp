#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int ans = 0;
string grid[10];
bool vis[10][10];
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

void dfs(int x, int y, int depth) {
    /*
    for (int i = 0; i < depth; ++i) {
        cout << "\t";
    }
    cout << "(" << x << ", " << y << ")\n";
    */

    ans = max(ans, depth);
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nnx = nx + dx[d];
        int nny = ny + dy[d];
        if (0 <= nnx and nnx < 10 and 0 <= nny and nny < 10) {
            if (!vis[nx][ny] and grid[nx][ny] == 'B' and grid[nnx][nny] == '#') {
                vis[nx][ny] = true;
                dfs(nnx, nny, depth + 1);
                vis[nx][ny] = false;
            }
        }
    }
}

void solve() {
    for (int i = 0; i < 10; ++i) {
        cin >> grid[i];
    }

    ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == 'W') {
                grid[i][j] = '#';
                dfs(i, j, 0);
                grid[i][j] = 'W';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
        cout << ans << '\n';
    }
    
    return 0;
}
