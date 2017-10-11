#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 2003;
int n;
int a[MAXN];

// dp[0][i] = best increasing sequence starting with i
// dp[1][i] = best decreasing sequence starting with i
int dp[2][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);

        dp[0][i] = dp[1][i] = 1;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] < a[j]) {
                dp[0][i] = max(dp[0][i], 1 + dp[0][j]);
            } else if (a[i] > a[j]) {
                dp[1][i] = max(dp[1][i], 1 + dp[1][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int best_inc = 0;
        int best_dec = 0;
        for (int j = i + 1; j < n; ++j) {
            if (a[i] < a[j])
                best_inc = max(best_inc, dp[0][j]);
            else if (a[i] > a[j])
                best_dec = max(best_dec, dp[1][j]);
        }

        ans = max(ans, 1 + best_inc + best_dec);
    }

    printf("%d\n", ans);

    return 0;
}
