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

constexpr int MAXN = 512;
constexpr ll INF = 1e18;
int n, m;
int k, r;
int lane[MAXN], curve[MAXN];
ll dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    scanf(" %d %d", &k, &r);
    for (int i = 0; i < 2 * n - 1; i += 2) {
        scanf(" %d", &lane[i]);
    }
    for (int i = 1; i < 2 * n - 1; i += 2) {
        scanf(" %d %d", &lane[i], &curve[i]);
    }

    dp[2 * n - 1][1] = 0;
    for (int i = 2; i <= m; ++i) {
        dp[2 * n - 1][i] = INF;
    }

    for (int i = 2 * n - 2; i >= 0; --i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = INF;
            if (i & 1) {
                // curve
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + lane[i] + 1LL * curve[i] * j);
            } else {
                // lane
                int delta = lane[i] / k;
                for (int j2 = max(1, j - delta); j2 <= min(m, j + delta); ++j2) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j2] + lane[i] + abs(j - j2) * r);
                }
            }
        }
    }

    printf("%lld\n", dp[0][1]);

    return 0;
}
