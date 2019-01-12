#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int INF = 1e9 + 7;

int solve(const vector<vi>& a) {
    int n = a.size();
    int m = a[0].size();
    // cost of going from row i to row j
    vector<vector<vi>> adj(2, vector<vi>(n, vi(n, INF)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }

            for (int p = 0; p < m; ++p) {
                adj[0][i][j] = min(adj[0][i][j], abs(a[i][p] - a[j][p]));
            }

            // if i is the last row and j is the first row
            for (int p = 0; p + 1 < m; ++p) {
                adj[1][i][j] = min(adj[1][i][j], abs(a[i][p] - a[j][p + 1]));
            }
        }
    }

    // now we have hamiltonian dp on these matrices
    vector<vector<vi>> dp(1 << n, vector<vi>(n, vi(n, 0)));

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i][i] = INF;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0)
                continue;
            for (int j = 0; j < n; ++j) {
                if ((mask & (1 << j)) == 0 or dp[mask][i][j] == 0)
                    continue;

                for (int p = 0; p < n; ++p) {
                    if ((mask & (1 << p)) > 0 or adj[0][j][p] == 0)
                        continue;
                    int new_mask = mask | (1 << p);
                    dp[new_mask][i][p] = max(dp[new_mask][i][p], min(dp[mask][i][j], adj[0][j][p]));
                }
            }
        }
    }

    int full = (1 << n) - 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(ans, min(dp[full][i][j], adj[1][j][i]));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    if (n == 1) {
        int ans = INF;
        for (int i = 1; i < m; ++i) {
            ans = min(ans, abs(a[0][i] - a[0][i - 1]));
        }
        cout << ans << '\n';
    } else {
        cout << solve(a) << '\n';
    }

    return 0;
}
