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

    string k;
    int d;
    cin >> k >> d;
    int n = k.size();

    // dp[i][j] = number of ways to choose i digits such that sum = j (mod d)
    vector<vi> dp(n + 1, vi(d, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            if (!dp[i][j]) continue;

            for (int v = 0; v < 10; ++v) {
                int jj = (j + v) % d;

                dp[i + 1][jj] += dp[i][j];
                if (dp[i + 1][jj] >= MOD)
                    dp[i + 1][jj] -= MOD;
            }
        }
    }

    int ans = 0;
    int cur_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int v = 0; v < k[i] - '0'; ++v) {
            int have = (cur_sum + v) % d;
            int want = d - have;
            if (want == d)
                want = 0;
            ans += dp[n - i - 1][want];
            if (ans >= MOD)
                ans -= MOD;
        }

        cur_sum += k[i] - '0';
        cur_sum %= d;
    }
    if (cur_sum == 0) {
        ++ans;
        if (ans >= MOD)
            ans -= MOD;
    }

    --ans;
    if (ans < 0)
        ans += MOD;

    cout << ans << '\n';
    
    return 0;
}
