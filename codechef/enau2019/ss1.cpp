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
        int n, k;
        cin >> n >> k;
        vi dp(n + 1, 0);
        dp[0] = 1;
        vector<bool> bad(n + 1, 0);
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            bad[x] = true;
        }

        for (int i = 0; i <= n; ++i) {
            if (!dp[i]) continue;
            for (int j = i + 1; j <= min(n, i + 3); ++j) {
                if (!bad[j]) {
                    dp[j] += dp[i];
                    if (dp[j] >= MOD)
                        dp[j] -= MOD;
                }
            }
        }

        cout << dp[n] << '\n';
    }
    
    return 0;
}
