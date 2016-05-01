#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int N, K;
long long dp[65][1001][65];

void gen_table() {
    memset(dp, 0, sizeof(dp));

    dp[1][0][0] = 1LL;
    dp[1][0][1] = 1LL;
    for (int len = 2; len <= 62; ++len) {
        for (int inv = 0; inv <= 1000; ++inv) {
            for (int k = 0; k <= len; ++k) {
                if (inv - k >= 0) {
                    dp[len][inv][k] += dp[len - 1][inv - k][k];
                }
                if (k > 0) {
                    dp[len][inv][k] += dp[len - 1][inv][k - 1];
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    gen_table();
    while (T-- > 0) {
        cin >> N >> K;
        long long ans = 0LL;
        for (int i = 0; i <= N; ++i) {
            ans += dp[N][K][i];
        }

        cout << ans << '\n';
    }

    return 0;
}
