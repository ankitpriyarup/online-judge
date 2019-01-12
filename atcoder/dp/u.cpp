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
    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<ll> dp(1 << n, 0);
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j = i + 1; j < n; ++j) {
                if ((mask & (1 << j)) == 0) continue;

                dp[mask] += a[i][j];
            }
        }
    }

    for (int mask = 1; mask < 1 << n; ++mask) {
        for (int ss = mask; ss > 0; ss = (ss - 1) & mask) {
            dp[mask] = max(dp[mask], dp[ss] + dp[mask ^ ss]);
        }
    }

    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}
