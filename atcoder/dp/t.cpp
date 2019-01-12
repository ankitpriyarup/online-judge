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

    // dp[i][j] = number of permutations of length i that end with j
    // when you insert j, everything that was >= j goes up by 1
    // if s[i] = <
    // dp[i][j] = sum_{k <= j} dp[i - 1][k]
    // else
    // dp[i][j] = sum_{k > j} dp[i - 1][k]
    // keep dem prefix sums

    int n;
    string s;
    cin >> n >> s;

    vector<vi> dp(n, vi(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == '<') {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        } else {
            for (int j = 0; j < i; ++j) {
                dp[i][j] = dp[i - 1][i - 1] - (j ? dp[i - 1][j - 1] : 0);
                if (dp[i][j] < 0)
                    dp[i][j] += MOD;
            }
        }

        for (int j = 1; j <= i; ++j) {
            dp[i][j] += dp[i][j - 1];
            if (dp[i][j] >= MOD)
                dp[i][j] -= MOD;
        }
    }

    cout << dp[n - 1][n - 1] << '\n';
    
    return 0;
}
