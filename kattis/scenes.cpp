#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10004;
const int MAXW = 102;
const int MOD = 1000000007;
int n, w, h;

// dp[i][j] = # of scenes you can make with i cols and exactly j ribbon left
int dp[MAXW][MAXN];

inline int sum(const int& a, const int& b) {
    int c = a + b;
    if (c >= MOD) {
        c -= MOD;
    }

    return c;
}

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

int solve(int cols, int ribbon) {
    if (ribbon < 0 or ribbon > cols * h)
        return 0;

    if (cols == 1 or ribbon == 0)
        return 1;

    int& ret = dp[cols][ribbon];

    if (ret != -1)
        return ret;

    ret = 0;
    for (int height = 0; height <= h; ++height) {
        ret = sum(ret, solve(cols - 1, ribbon - height));
    }

    return ret;
}

int main() {
    scanf("%d %d %d", &n, &w, &h);

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int ribbon = 0; ribbon <= n; ++ribbon) {
        ans = sum(ans, solve(w, ribbon));
    }

    for (int height = 0; height <= h; ++height) {
        if (1LL * height * w <= n)
            ans = sum(ans, MOD - 1);
    }

    printf("%d\n", ans);

    return 0;
}
