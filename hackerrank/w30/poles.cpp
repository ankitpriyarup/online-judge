#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5003;
const long long INF = 1e18;

int n, k;
long long x[MAXN];
long long w[MAXN];

long long dp[MAXN][MAXN];
int opt[MAXN][MAXN];
long long wixi[MAXN];
long long sumw[MAXN];

inline long long score(int l, int i, int j) {
    return (wixi[i] - wixi[l - 1]) - (sumw[i] - sumw[l - 1]) * x[l] + dp[l - 1][j - 1];
}

void compute(int j, int i_left, int i_right, int k_left, int k_right) {
    int i_mid = (i_left + i_right) / 2;
    dp[i_mid][j] = INF;

    for (int l = k_left; l <= k_right; ++l) {
        long long s = score(l, i_mid, j);
        if (s < dp[i_mid][j]) {
            dp[i_mid][j] = s;
            opt[i_mid][j] = l;
        }
    }

    if (i_left <= i_mid - 1)
        compute(j, i_left, i_mid - 1, k_left, opt[i_mid][j]);

    if (i_mid + 1 <= i_right)
        compute(j, i_mid + 1, i_right, opt[i_mid][j], k_right);
}

int main() {
    scanf("%d %d", &n, &k);
    wixi[0] = sumw[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld", x + i, w + i);
        wixi[i] = wixi[i - 1] + w[i] * x[i];
        sumw[i] = sumw[i - 1] + w[i];
    }

    for (int i = 1; i <= n; ++i) {
        printf("%lld %lld\n", sumw[i], wixi[i]);
    }
    puts("");

    memset(dp, 0, sizeof(dp));
    // a, a + 1, a + 2 ... b
    // cost for some region: wi * xi - sum(w) * x_a
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = wixi[i] - sumw[i] * x[1];
    }

    for (int j = 2; j <= k; ++j) {
        compute(j, j, n, j, n);
    }

    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            printf("%d ", opt[i][j]);
        }
        puts("");
    }
    puts("");


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            printf("%lld ", dp[i][j]);
        }
        puts("");
    }
    puts("");
    */

    printf("%lld\n", dp[n][k]);

    return 0;
}
