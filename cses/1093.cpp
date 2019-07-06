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

    int n;
    cin >> n;

    int tot = n * (n + 1) / 2;
    if (tot % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int goal = tot / 2;
    vi dp(goal + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = goal - i; j >= 0; --j) {
            dp[i + j] += dp[j];
            if (dp[i + j] >= MOD) {
                dp[i + j] -= MOD;
            }
        }
    }

    int ans = 1LL * dp[goal] * ((MOD + 1) / 2) % MOD;

    cout << ans << '\n';

    return 0;
}
