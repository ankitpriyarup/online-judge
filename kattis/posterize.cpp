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

constexpr int MAXN = 333;
constexpr ll INF = 1e18;
int d, p;
int a[MAXN];

// cost of using segment [i, j)
ll cost[MAXN][MAXN];
ll dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &d, &p);
    for (int i = 0; i < d; ++i) {
        int x, y;
        scanf(" %d %d", &x, &y);
        a[x] = y;
    }

    for (int i = 0; i <= 256; ++i) {
        for (int j = 0; j <= 256; ++j) {
            cost[i][j] = INF;
            dp[i][j] = INF;
        }

        cost[i][i] = 0;
    }

    // use i as center for range j, k
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            ll score = 0LL;
            for (int k = j + 1; k <= 256; ++k) {
                ll dist = abs(k - 1 - i);
                score += dist * dist * a[k - 1];

                cost[j][k] = min(cost[j][k], score);
            }
        }
    }

    for (int j = 0; j <= 256; ++j)
        dp[j][1] = cost[0][j];

    for (int k = 1; k <= p; ++k)
        dp[0][k] = 0LL;

    for (int k = 2; k <= p; ++k) {
        for (int j = 0; j <= 256; ++j) {
            for (int i = 0; i < j; ++i) {
                dp[j][k] = min(dp[j][k], dp[i + 1][k - 1] + cost[i + 1][j]);
            }
        }
    }

    /*
    for (int k = 1; k <= p; ++k) {
        for (int j = 0; j <= 256; ++j) {
            printf("%lld ", dp[j][k]);
        }
        printf("\n");
    }
    */

    printf("%lld\n", dp[256][p]);
    return 0;
}
