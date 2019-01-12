#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 21;
constexpr int MOD = 1e9 + 7;

int n;
int a[MAXN][MAXN];
int dp[1 << MAXN][MAXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %d", &a[i][j]);
        }
    }

    // dp[mask][i] = number of ways to pair up the first i rows with the columns in mask
    // iterate over all j. if you can pair with j and j is in the mask, then add dp[mask ^ (1 << j)][i - 1]
    dp[0][0] = 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int j = 0; j < n; ++j) {
            if (!(mask & (1 << j)))
                continue;
            for (int i = 0; i < n; ++i) {
                if (a[j][i]) {
                    dp[mask][i + 1] += dp[mask ^ (1 << j)][i];
                    if (dp[mask][i + 1] >= MOD)
                        dp[mask][i + 1] -= MOD;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n] << '\n';
    
    return 0;
}
