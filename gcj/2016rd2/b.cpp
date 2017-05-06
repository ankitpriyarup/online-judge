#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 202;
int n, k;
double a[MAXN];
double b[MAXN];
double dp[MAXN][MAXN];

double run_dp() {
    for (int i = 0; i <= k; ++i) {
        for (int v = 0; v <= k; ++v) {
            dp[i][v] = 0;
        }
    }

    dp[0][0] = 1.0;
    for (int i = 1; i <= k; ++i) {
        double p = b[i];
        for (int v = 0; v <= k; ++v) {
            if (v) dp[i][v] += p * dp[i - 1][v - 1];
            dp[i][v] += (1 - p) * dp[i - 1][v];
        }
    }

    return dp[k][k / 2];
}

double solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", a + i);
    }

    sort(a + 1, a + n + 1);

    double ans = 0.0;

    for (int i = 1; i <= k; ++i) {
        b[i] = a[i];
    }

    ans = max(ans, run_dp());

    int target = n;
    int swap = k;
    while (swap >= 0) {
        b[swap] = a[target];
        --swap;
        --target;
        ans = max(ans, run_dp());
    }

    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int case_num = 1; case_num <= T; ++case_num) {
        printf("Case #%d: %.9f\n", case_num, solve());
    }
    return 0;
}
