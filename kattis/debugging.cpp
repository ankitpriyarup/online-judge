#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using ll = long long;

constexpr int MAXN = 1000006;
constexpr ll INF = 1e18;
ll r, p;
ll dp[MAXN];

ll solve(const ll& n) {
    if (dp[n] != -1LL) {
        return dp[n];
    }

    ll& ref = dp[n];
    ref = INF;

    for (int k = 2; k <= n; ++k) {
        // divide into k blocks
        ll x = r + (k - 1) * p + solve((n + k - 1) / k);
        ref = min(ref, x);
    }

    return ref;
}

int main() {
    ll n;
    scanf("%lld %lld %lld", &n, &r, &p);

    memset(dp, -1, sizeof(dp));
    dp[0] = dp[1] = 0;
    printf("%lld\n", solve(n));
    return 0;
}
