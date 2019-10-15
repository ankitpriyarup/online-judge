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

    constexpr int MOD = 1e9 + 7;
    int n;
    cin >> n;
    vi dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i, 6); ++j) {
            dp[i] += dp[i - j];
            if (dp[i] >= MOD)
                dp[i] -= MOD;
        }
    }

    cout << dp[n] << '\n';
    
    return 0;
}
