#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& r : grid)
        cin >> r;

    vector<vi> left(n, vi(m, -1)), right(n, vi(m, -1)), up(n, vi(m, -1)), down(n, vi(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') continue;
            if (j == 0) left[i][j] = 0;
            else left[i][j] = 1 + left[i][j - 1];
        }
        for (int j = m - 1; j >= 0; --j) {
            if (grid[i][j] == '#') continue;
            if (j == m - 1) right[i][j] = 0;
            else right[i][j] = 1 + right[i][j + 1];
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == '#') continue;
            if (i == 0) up[i][j] = 0;
            else up[i][j] = up[i - 1][j] + 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (grid[i][j] == '#') continue;
            if (i == n - 1) down[i][j] = 0;
            else down[i][j] = down[i + 1][j] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = up[i][j] + right[i][j] + down[i][j] + left[i][j] + 1;
            ans = max(ans, x);
        }
    }

    cout << ans << '\n';

    return 0;
}
