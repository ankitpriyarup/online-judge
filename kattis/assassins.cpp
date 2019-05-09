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
    double full = (1 << n) - 1;
    vector<double> dp(1 << n, 0.0);
    dp[full] = 1.0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        double p;
        cin >> u >> v >> p;
        --u; --v;

        vector<double> ndp(1 << n, 0.0);
        for (int mask = 0; mask < (1 << n); ++mask) {
            if ((mask & (1 << u)) > 0 and (mask & (1 << v)) > 0) {
                ndp[mask] += (1.0 - p) * dp[mask];
                ndp[mask ^ (1 << v)] += p * dp[mask];
            } else {
                ndp[mask] += dp[mask];
            }
        }

        swap(dp, ndp);
    }

    vector<double> ans(n, 0.0);
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                ans[i] += dp[mask];
            }
        }
    }
    cout << fixed << setprecision(10);
    for (int i = 0; i < n; ++i)
        cout << ans[i] << '\n';

    return 0;
}
