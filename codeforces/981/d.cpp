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
using pii = pair<ll, ll>;

constexpr int MAXN = 55;
int n, k;
ll a[MAXN];

bool dp[MAXN][MAXN];

bool can(ll v) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (!dp[i][j]) continue;

            ll cur = 0LL;
            for (int x = i + 1; x <= n; ++x) {
                cur += a[x];
                if ((cur & v) == v) {
                    dp[x][j + 1] = 1;
                }
            }
        }
    }

    return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf(" %lld", &a[i]);
    }

    ll res = 0LL;
    for (ll p = (1LL << 60LL); p; p >>= 1) {
        if (can(res | p))
            res |= p;
    }

    printf("%lld\n", res);

    return 0;
}
