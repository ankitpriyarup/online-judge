#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#define MOD 1000000007

using namespace std;

int n, m, s;
int dp[1003][1003];
int a[1003];

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n >> m >> s;
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        --s;
        memset(dp, 0, sizeof(dp));
        dp[0][s] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                //cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << (j + a[i]) << ' ' << (j - a[i]) << '\n';

                if (j + a[i] < n) {
                    //cout << (i + 1) << ' ' << (j + a[i]) << '\n';
                    dp[i + 1][j + a[i]] += dp[i][j];
                    dp[i + 1][j + a[i]] %= MOD;
                }
                if (j - a[i] >= 0) {
                    //cout << (i + 1) << ' ' << (j - a[i]) << '\n';
                    dp[i + 1][j - a[i]] += dp[i][j];
                    dp[i + 1][j - a[i]] %= MOD;
                }
            }
        }

        cout << dp[m][0];
        for (int i = 1; i < n; ++i) {
            cout << ' ' << dp[m][i];
        }
        cout << '\n';
    }

    return 0;
}
