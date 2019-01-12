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

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    constexpr ll INF = 1e17;
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i)
        dp[i][i] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            ll tot = 0LL;
            for (int k = i; k < j; ++k) {
                tot += a[k];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }

            tot += a[j];
            // cout << "tot(" << i << ", " << j << ") = " << tot << '\n';
            dp[i][j] += tot;
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    cout << dp[0][n - 1] << '\n';
    
    return 0;
}
