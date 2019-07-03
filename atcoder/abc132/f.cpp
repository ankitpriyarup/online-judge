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

    int n, k;
    cin >> n >> k;

    // dp[i][j] = number of sequences ending with value i of length j
    // dp[i][1] = 1
    // dp[i][j] = sum dp[k][j - 1] where i * k <= n
    
    vi ranges;
    // if (n >= 30000) {
        for (int i = 1; i * i <= n; ++i) {
            ranges.push_back(i);
            ranges.push_back(n / i);
        }

        sort(all(ranges));
        ranges.erase(unique(all(ranges)), end(ranges));
    // } else {
    //     ranges.resize(n);
    //     iota(all(ranges), 1);
    // }

    int m = ranges.size();
    vi dp(all(ranges));

    for (int j = 1; j < k; ++j) {
        vi ndp(m);

        int p = m - 1;
        for (int i = 0; i < m; ++i) {
            // cout << "dp[" << i << "] = " << dp[i] << '\n';

            int v = ranges[i];
            while (1LL * v * ranges[p] > n) {
                --p;
            }

            // cout << "p = " << p << '\n';
            ndp[i] = 1LL * (ranges[i] - (i ? ranges[i - 1] : 0)) * dp[p] % MOD;
        }

        for (int i = 1; i < m; ++i) {
            ndp[i] += ndp[i - 1];
            ndp[i] %= MOD;
        }

        swap(dp, ndp);
    }

    /*
    for (int i = 0; i < m; ++i) {
        cout << ranges[i] << ' ' << dp[i] << '\n';
    }
    */

    cout << dp[m - 1] << '\n';

    return 0;
}
