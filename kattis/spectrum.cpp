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

constexpr int MAXN = 222;
constexpr ld EPS = 1e-9;
constexpr ld INF = 1e18;
int n, m;
int a[MAXN];
ld dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = INF;
        }
    }


    ll k = 0LL;
    ll ki = 0LL;
    ll kii = 0LL;
    // sum_i k_i (i - x)^2
    // sum_i k_i (i^2 - 2 x i + x^2)
    // sum_i k_i i^2 - 2 x sum_i k_i i + x^2 sum_i k_i
    for (int i = 1; i <= n; ++i) {
        k += a[i];
        ki += 1LL * i * a[i];
        kii += 1LL * i * i * a[i];

        if (k == 0) {
            dp[i][1] = 0;
        } else {
            ld avg = static_cast<ld>(ki) / k;
            ld cost = kii - 2.0 * avg * ki + avg * avg * k;
            dp[i][1] = cost;
        }
    }

    for (int j = 2; j <= m; ++j) {
        for (int i = j; i <= n; ++i) {
            k = 0LL;
            ki = 0LL;
            kii = 0LL;
            for (int l = i; l <= n; ++l) {
                k += a[l];
                ki += 1LL * l * a[l];
                kii += 1LL * l * l * a[l];

                ld cost;
                if (k == 0) {
                    cost = 0.0;
                } else {
                    ld avg = static_cast<ld>(ki) / k;
                    cost = kii - 2.0 * avg * ki + avg * avg * k;
                }

                dp[l][j] = min(dp[l][j], dp[i - 1][j - 1] + cost);
            }
        }
    }

    /*
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            printf("%.2Lf ", dp[i][j]);
        }
        printf("\n");
    }
    */

    printf("%.9Lf\n", dp[n][m]);

    return 0;
}
