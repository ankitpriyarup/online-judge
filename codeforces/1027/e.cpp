#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MOD = 998244353;
constexpr int INV2 = (MOD + 1) / 2;
constexpr int MAXN = 555;

inline int sum(const int& a, const int& b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

inline int prod(const int& a, const int& b) {
    return 1LL * a * b % MOD;
}

int n, k;
int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    // fix a bit pattern for the top row. Then every row is a 0 or a 1.
    // Depending on the longest run in the top row, that fixes how long
    // we can have a run of consecutive 0s or 1s
    // dp[i][j] = number of bitstrings where maximum run is j
    

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 2;
        for (int j = 1; j <= i; ++j) {
            if (!dp[i][j]) continue;

            for (int k = 1; k <= j and i + k <= n; ++k) {
                dp[i + k][j] = sum(dp[i + k][j], dp[i][j]);
            }
            for (int k = j + 1; i + k <= n; ++k) {
                dp[i + k][k] = sum(dp[i + k][k], dp[i][j]);
            }
        }
    }

    /*
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            printf(" %d", dp[i][j]);
        }
        printf("\n");
    }
    */

    // Now, say we have a bitstring which has max length j
    // then we can have at most (k / j) copies of it
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        for (int l = 1; l <= min(n, (k - 1) / j); ++l) {
            // printf("top max run %d, max row run %d\n", j, l);
            ans = sum(ans, prod(dp[n][j], prod(INV2, dp[n][l])));
        }
    }

    printf("%d\n", ans);

    return 0;
}
