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
    
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;
        vi age(n);
        for (int i = 0; i < n; ++i) {
            cin >> age[i];
        }

        vi opts(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            if (age[u] > age[v]) ++opts[v];
            else if (age[u] < age[v]) ++opts[u];
        }

        /*
        for (int i = 0; i < n; ++i) {
            cout << "opts[" << i << "] = " << opts[i] << '\n';
        }
        */

        // number of ways to get i roots from the first j
        vector<vi> dp(2, vi(n + 1, 0));
        dp[0][0] = 1;

        // sum of chiefs when getting i roots from first j
        vector<vi> dp2(2, vi(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[0][j] == 0) continue;
                // make i a root
                dp[1][j + 1] += dp[0][j];
                if (dp[1][j + 1] >= MOD) {
                    dp[1][j + 1] -= MOD;
                }
                dp2[1][j + 1] += (dp2[0][j] + 1LL * dp[0][j] * age[i]) % MOD;
                if (dp2[1][j + 1] >= MOD) {
                    dp2[1][j + 1] -= MOD;
                }

                // choose a parent for i
                dp[1][j] += 1LL * dp[0][j] * opts[i] % MOD;
                if (dp[1][j] >= MOD) {
                    dp[1][j] -= MOD;
                }
                dp2[1][j] += (1LL * dp2[0][j] * opts[i]) % MOD;
                if (dp2[1][j] >= MOD) {
                    dp2[1][j] -= MOD;
                }
            }

            swap(dp[0], dp[1]);
            swap(dp2[0], dp2[1]);
            fill(all(dp[1]), 0);
            fill(all(dp2[1]), 0);
        }

        /*
        for (int j = 1; j <= n; ++j) {
            cout << dp[n][j] << ' ';
        }
        cout << '\n';
        */
        for (int j = 1; j <= n; ++j) {
            cout << dp2[0][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
