#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> dp(n, vector<int>(m, int(0)));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }

            if (i + 1 < n) {
                dp[i + 1][j] += dp[i][j];
                if (dp[i + 1][j] >= MOD)
                    dp[i + 1][j] -= MOD;
            }

            if (j + 1 < m) {
                dp[i][j + 1] += dp[i][j];
                if (dp[i][j + 1] >= MOD)
                    dp[i][j + 1] -= MOD;
            }

        }
    }
    
    cout << dp[n - 1][m - 1] << '\n';
    return 0;
}
