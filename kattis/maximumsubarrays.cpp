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
constexpr ll INF = 1e14;
int n, k;
int a[MAXN];
ll p[MAXN];

// dp j i - max sum that can be made using exactly j non empty subarrays of the
// first i values.
//
// dp[j][i] = max dp[j - 1][k] + p[i] - p[k]
ll dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);

    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &a[i]);
        p[i] = p[i - 1] + a[i];
        dp[0][i] = max(-p[i], dp[0][i - 1]);
    }

    ll ans = -INF;
    for (int j = 1; j <= k; ++j) {
        dp[j][0] = -INF;
        for (int i = 1; i <= n; ++i) {
            dp[j][i] = p[i] + dp[j - 1][i - 1];
        }

        ans = -INF;
        for (int i = 1; i <= n; ++i) {
            dp[j][i] = max(dp[j][i], dp[j][i - 1]);
            ans = max(ans, dp[j][i]);
        }

        for (int i = 1; i <= n; ++i) {
            dp[j][i] -= p[i];
        }

        for (int i = 1; i <= n; ++i) {
            dp[j][i] = max(dp[j][i], dp[j][i - 1]);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
