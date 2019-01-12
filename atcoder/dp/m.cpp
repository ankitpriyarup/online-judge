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

    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // dp[i][j] = number of ways to distribute j candies over i kids
    // dp[i][j] = sum dp[i - 1][j - k] over all k from 0 to a[i]

    vector<vi> dp(n + 1, vi(k + 1, 0));
    vector<vi> dp2(n + 1, vi(k + 1, 0));
    dp[0][0] = 1;
    fill(all(dp2[0]), 1);

    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = dp2[i + 1][0] = 1;
        for (int j = 1; j <= k; ++j) {
            int offset = j - a[i] - 1;
            dp[i + 1][j] = dp2[i][j] - (offset >= 0 ? dp2[i][offset] : 0);

            if (dp[i + 1][j] < 0)
                dp[i + 1][j] += MOD;

            dp2[i + 1][j] = dp[i + 1][j] + dp2[i + 1][j - 1];
            if (dp2[i + 1][j] >= MOD)
                dp2[i + 1][j] -= MOD;
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}
