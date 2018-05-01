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

constexpr int MAXN = 555;
int n, m;
// lefts, then ups
ll a[2][MAXN][MAXN];
ll p[2][MAXN][MAXN];
ll dp[MAXN][MAXN];

ll score(int row, int split) {
    return p[0][row][split - 1] + p[1][row][m] - p[1][row][split - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf(" %d %d", &n, &m) == 2) {
        if (!n or !m) break;
        memset(p, 0, sizeof(p));
        for (int k = 0; k < 2; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    scanf(" %lld", &a[k][i][j]);
                    p[k][i][j] = a[k][i][j] + p[k][i][j - 1];
                }
            }
        }

        for (int j = 1; j <= m + 1; ++j) {
            // [0, j) are left, [j, m] are up
            dp[1][j] = p[0][1][j - 1] + (p[1][1][m] - p[1][1][j - 1]);
        }

        ll ans = -1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m + 1; ++j) {
                dp[i][j] = -1;
                for (int j2 = 1; j2 <= j; ++j2) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i - 1][j2] + p[0][i][j - 1] + (p[1][i][m] - p[1][i][j - 1]));
                }

                ans = max(ans, dp[i][j]);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
