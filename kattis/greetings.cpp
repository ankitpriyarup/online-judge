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

constexpr int MAXN = 16;
constexpr ll INF = 1e18;
int n, k;
int w[MAXN], h[MAXN], q[MAXN];
ll dp[MAXN][1 << MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", w + i, h + i, q + i);
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        int maxw = 0;
        int maxh = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                maxw = max(maxw, w[i]);
                maxh = max(maxh, h[i]);
            }
        }

        dp[1][mask] = 0LL;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                dp[1][mask] += 1LL * q[i] * (1LL * maxw * maxh - 1LL * w[i] * h[i]);
            }
        }
    }

    for (int j = 2; j <= k; ++j) {
        for (int mask = 1; mask < (1 << n); ++mask) {
            dp[j][mask] = INF;
            for (int ss = mask; ss; ss = (ss - 1) & mask) {
                dp[j][mask] = min(dp[j][mask], dp[1][ss] + dp[j - 1][mask ^ ss]);
            }
        }
    }

    printf("%lld\n", dp[k][(1 << n) - 1]);

    return 0;
}
