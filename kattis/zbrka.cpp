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

constexpr int MAXN = 1003;
constexpr int MAXC = 10004;
constexpr int MOD = 1000000007;
int dp[MAXN][MAXC];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, c;
    scanf(" %d %d", &n, &c);
    dp[1][0] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int conf = 0; conf <= c; ++conf) {
            dp[len][conf] = dp[len - 1][conf];
            int sz = min(len, conf + 1);
            if (conf - sz >= 0)
                dp[len][conf] -= dp[len - 1][conf - sz];
            if (dp[len][conf] < 0)
                dp[len][conf] += MOD;
            dp[len][conf] += dp[len][conf - 1];
            if (dp[len][conf] >= MOD)
                dp[len][conf] -= MOD;
        }
    }

    printf("%d\n", dp[n][c]);

    return 0;
}
