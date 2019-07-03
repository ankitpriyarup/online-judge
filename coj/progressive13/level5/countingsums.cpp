#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 10004;
constexpr int MOD = 1e9 + 7;
int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
     * 1
     * 1 2
     * 1 2 3
     * 1 3 4 5
     *
     */
    for (int i = 0; i < MAXN; ++i)
        dp[0][i] = dp[1][i] = 1;
    for (int i = 2; i < MAXN; ++i) {
        dp[i][0] = 1;
        dp[i][1] = 1;
        for (int j = 2; j <= i; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            if (dp[i][j] >= MOD)
                dp[i][j] -= MOD;
        }
        for (int j = i + 1; j < MAXN; ++j) {
            dp[i][j] = dp[i][j - 1];
        }
    }

    /*
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    int n;
    while (cin >> n) {
        cout << dp[n][n] << '\n';
    }
    
    return 0;
}
