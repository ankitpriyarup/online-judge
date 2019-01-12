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

    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i][j][k] = min fuel needed to go from i to j with k refuels
    // dp[i][j][k] = min_l dp[i][l][k - 1] + dp[l][j][0]
    // dp[i][l][k - 1] is increasing as l increases, and the other is decreasing as l increases
    // can you two pointer this somehow?
    // Need to prove that opt[i][j][k] <= opt[i][j + 1][k]
    // that seems trivial
    constexpr int INF = 1e9 + 7;
    vector<vector<vi>> dp(n, vector<vi>(n, vi(n, INF)));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            dp[i][j][0] = a[j] - a[i];
        }
    }

    for (int k = 1; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            dp[i][i][k] = 0;

            int l = i;
            for (int j = i + 1; j < n; ++j) {
                while (l < j and max(dp[i][l + 1][k - 1], dp[l + 1][j][0]) < max(dp[i][l][k - 1], dp[l][j][0]))
                    ++l;
                dp[i][j][k] = max(dp[i][l][k - 1], dp[l][j][0]);
            }
        }
    }

    ll ans = 0;
    while (m-- > 0) {
        int s, f, c, r;
        cin >> s >> f >> c >> r;
        --s; --f;
        r = min(r, n - 1);
        ans = max(ans, 1LL * dp[s][f][r] * c);
    }

    cout << ans << '\n';

    return 0;
}
