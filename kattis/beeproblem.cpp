#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int dx[2][6] = {{-1, -1, 0, 0, 1, 1}, {-1, -1, 0, 0, 1, 1}};
int dy[2][6] = {{-1, 0, -1, 1, -1, 0}, {0, 1, -1, 1, 0, 1}};

int dfs(vector<vi>& g, int x, int y) {
    if (x < 0 or y < 0 or x >= g.size() or y >= g[x].size() or g[x][y] == 0)
        return 0;

    int ans = 1;
    g[x][y] = 0;
    int k = x % 2;
    for (int d = 0; d < 6; ++d) {
        ans += dfs(g, x + dx[k][d], y + dy[k][d]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h, n, m;
    cin >> h >> n >> m;
    vector<vi> g(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '.')
                g[i][j] = 1;
        }
    }

    vi comps;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 1) {
                comps.push_back(dfs(g, i, j));
            }
        }
    }

    sort(all(comps));
    int ans = 0;
    while (h > 0) {
        ++ans;
        h -= comps.back();
        comps.pop_back();
    }

    cout << ans << '\n';

    return 0;
}
