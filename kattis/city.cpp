#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 10044;
int n;
ll d;
ll h[MAXN], e[MAXN];
ll dp[MAXN][2];

ll solve(int i, bool left_boom) {
    ll hp = h[i] - left_boom * e[i - 1];
    if (i == n - 1) {
        return max(0LL, (hp + d - 1) / d);
    }

    ll& res = dp[i][left_boom];
    if (res != -1)
        return res;

    res = max(0LL, (hp - e[i + 1] + d - 1) / d) + solve(i + 1, 0);
    res = min(res, max(0LL, (hp + d - 1) / d) + solve(i + 1, 1));

    return res;
}

int main() {
    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d %lld", &n, &d);
        for (int i = 0; i < n; ++i) {
            scanf(" %lld", &h[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf(" %lld", &e[i]);
        }

        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(0, 0));
    }

    return 0;
}
