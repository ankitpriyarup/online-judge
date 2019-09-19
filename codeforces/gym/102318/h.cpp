#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& x : a)
        cin >> x;

    // dp[i][j] using i elements, whats max number of used values given that curr inc seq has len j?
    // redo this k times?
    for (int k = 1; k <= n; ++k) { 
        // cerr << "K = " << k << '\n';

        vector<vi> dp(n, vi(k + 1, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            dp[i][1] = 1;

            for (int j = 0; j < i; ++j) {
                if (dp[j][k] >= k)
                    dp[i][1] = max(dp[i][1], dp[j][k] + 1);

                if (a[j] < a[i]) {
                    for (int kk = 0; kk <= k; ++kk) {
                        int nk = min(k, kk + 1);
                        if (dp[j][kk] >= kk)
                            dp[i][nk] = max(dp[i][nk], dp[j][kk] + 1);
                    }
                }
            }

            /*
            cerr << "dp[" << i << "] =";
            for (int x : dp[i]) {
                cerr << ' ' << x;
            }
            cerr << '\n';
            */

            ans = max(ans, dp[i][k]);
        }

        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
