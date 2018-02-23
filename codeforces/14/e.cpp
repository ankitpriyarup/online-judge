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

int n, t;
ll dp[22][5][5][5][12][12];

ll solve(int pos, int a, int b, int c, int peaks, int valleys) {
    if (peaks > t or valleys >= t) {
        return 0LL;
    }

    if (pos == n) {
        return peaks == t and valleys == (t - 1);
    }
    ll& res = dp[pos][a][b][c][peaks][valleys];
    if (res != -1)
        return res;

    res = 0;
    for (int d = 1; d <= 4; ++d) {
        if (c == d) continue;

        int peak = b < c and c > d;
        int valley = b > c and c < d;
        res += solve(pos + 1, b, c, d, peaks + peak, valleys + valley);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &t);

    ll ans = 0LL;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (i == j) continue;
            for (int k = 1; k <= 4; ++k) {
                if (j == k) continue;

                int peak = i < j and j > k;
                int valley = i > j and j < k;
                ans += solve(3, i, j, k, peak, valley);
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
