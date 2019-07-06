#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1003;
int n, m;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int x, int y) {
    if (x < 0 or y < 0 or x >= n or y >= m or vis[x][y] or grid[x][y] == '#') {
        return;
    }

    vis[x][y] = true;
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x, y + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' and !vis[i][j]) {
                ++ans;
                dfs(i, j);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
