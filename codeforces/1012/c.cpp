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

constexpr int MAXN = 5003;
constexpr ll INF = 1e16;
int n;
ll a[MAXN];

// min cost to build at least k houses on first i hills, where you have to have a house on the last hill
ll dp[MAXN][MAXN];
ll dpmin[MAXN][MAXN];
ll res[MAXN];

ll solve(int i, int k) {
    ll& res = dp[i][k];
    if (res != -1)
        return res;

    if (k == 0) {
        return res = 0LL;
    }

    if (k == 1) {
        return res = max(0LL, (i ? a[i - 1] : 0LL) - a[i] + 1);
    }

    if (i <= 1) {
        return res = INF;
    }

    res = solve(i - 2, k - 1) + max(0LL, a[i - 1] - min(a[i - 2], a[i]) + 1);
    if (i >= 3) {
        res = min(res, solve(i - 3, k - 1) + max(0LL, a[i - 1] - a[i] + 1));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf(" %lld", &a[i]);
    }
    a[n + 1] = 0;
    
    fill(res, res + n, INF);

    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 0LL;
        dpmin[0][i] = 0LL;
    }

    dp[1][0] = INF;
    dpmin[1][0] = INF;
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = max(0LL, a[i - 1] - a[i] + 1);
        dpmin[1][i] = min(dpmin[1][i - 1], dp[1][i] + max(0LL, a[i + 1] - a[i] + 1));
        res[1] = min(res[1], dp[1][i] + max(0LL, a[i + 1] - a[i] + 1));
    }

    for (int k = 2; k <= (n + 1) / 2; ++k) {
        fill(dp[k], dp[k] + n + 1, INF);
        for (int i = 3; i <= n; ++i) {
            dp[k][i] = dp[k - 1][i - 2] + max(0LL, a[i - 1] - min(a[i - 2], a[i]) + 1);
            if (i != 3) {
                dp[k][i] = min(dp[k][i], dpmin[k - 1][i - 3] + max(0LL, a[i - 1] - a[i] + 1));
            }

            res[k] = min(res[k], dp[k][i] + max(0LL, a[i + 1] - a[i] + 1));
        }

        dpmin[k][0] = INF;
        for (int i = 1; i <= n; ++i) {
            dpmin[k][i] = min(dpmin[k][i - 1], dp[k][i] + max(0LL, a[i + 1] - a[i] + 1));
        }
    }

    /*
    for (int k = 0; k <= (n + 1) / 2; ++k) {
        printf("dp[%d] =", k);
        for (int i = 1; i <= n; ++i) {
            printf(" %lld", dp[k][i]);
        }
        printf("\n");
    }
    */

    for (int k = 1; k <= (n + 1) / 2; ++k) {
        printf("%lld ", res[k]);
    }

    return 0;
}
