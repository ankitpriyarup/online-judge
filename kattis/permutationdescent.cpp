#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 103;
constexpr int MOD = 1001113;

int dp[MAXN][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /**
     * dp(i, j, k) i is len, j is num desc, k is start.
     * dp(i, j, k) = sum over all l from 1 to i of dp(i - 1, j, l) (if l < k) + dp(i - 1, j - 1, l - 1) (if l >= k)
     *
     * optimize to n^3 using prefix sums?
     */

    memset(dp, 0, sizeof(dp));
    dp[1][0][1] = 1;

    for (int i = 2; i < MAXN; ++i) {
        dp[i][0][1] = 1;
        for (int j = 1; j < i; ++j) {
            for (int k = 1; k <= i; ++k) {
                dp[i][j][k] += (dp[i - 1][j - 1][k - 1] + dp[i - 1][j][i - 1] - dp[i - 1][j][k - 1]) % MOD;
                while (dp[i][j][k] < 0) {
                    dp[i][j][k] += MOD;
                }
            }
        }

        for (int j = 0; j < i; ++j) {
            for (int k = 2; k <= i; ++k) {
                dp[i][j][k] += dp[i][j][k - 1];
                dp[i][j][k] %= MOD;
            }
        }
    }

    int T, a, b, k;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d %d", &k, &a, &b);
        printf("%d %d\n", k, dp[a][b][a]);
    }

    return 0;
}
