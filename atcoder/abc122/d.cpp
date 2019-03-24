#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool bad(int i, int j, int k) {
    return (i == 0 and j == 2 and k == 1)
        or (i == 0 and j == 1 and k == 2)
        or (i == 2 and j == 0 and k == 1);
}

bool bad(int i, int j, int k, int l) {
    return bad(i, j, k) or bad(j, k, l)
        or (i == 0 and k == 2 and l == 1)
        or (i == 0 and j == 2 and l == 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // cannot contain
    // AGC
    // ACG
    // GAC
    // A.GC
    // AG.C
    //
    constexpr int MOD = 1e9 + 7;
    vector<vector<vi>> dp(4, vector<vi>(4, vi(4, 1)));
    dp[0][2][1] = 0;
    dp[0][1][2] = 0;
    dp[2][0][1] = 0;

    int n;
    cin >> n;
    for (int t = 4; t <= n; ++t) {
        vector<vector<vi>> ndp(4, vector<vi>(4, vi(4, 0)));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (bad(i, j, k)) continue;

                    for (int l = 0; l < 4; ++l) {
                        if (bad(i, j, k, l)) continue;

                        ndp[j][k][l] += dp[i][j][k];
                        ndp[j][k][l] %= MOD;
                    }
                }
            }
        }

        swap(dp, ndp);
    }

    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                ans += dp[i][j][k];
                ans %= MOD;
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
