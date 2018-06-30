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

constexpr int MAXN = 16;
constexpr int MAXS = 32;
int n;
ll dp[MAXS][MAXN][2];
int a[MAXN];

ll solve_dp[MAXS][MAXN];

ll solve(int sum, int critics) {
    if (!sum)
        return 1;
    if (critics <= 0) {
        return 0;
    }

    ll& res = solve_dp[sum][critics];
    if (res != -1)
        return res;

    res = 0LL;
    for (int i = 0; i <= sum; ++i) {
        res += solve(sum - i, critics - 1);
    }

    return res;
}

ll exact_ways(int sum, int critic, bool can_exceed) {
    if (sum == 0) {
        return 1;
    }
    if (critic >= n) {
        return 0;
    }

    ll& ans = dp[sum][critic][can_exceed];
    if (ans != -1)
        return ans;

    ans = 0LL;
    int cap = can_exceed ? sum : min(sum, a[critic]);
    for (int i = 0; i <= cap; ++i) {
        ans += exact_ways(sum - i, critic + 1, can_exceed or i < cap);
    }

    return dp[sum][critic][can_exceed] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(solve_dp, -1, sizeof(solve_dp));
    while (scanf(" %d", &n) == 1) {
        if (!n) break;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf(" %d", &a[i]);
            sum += a[i];
        }

        ll res = 0;
        for (int cur = 0; cur < sum; ++cur) {
            res += solve(cur, n);
        }

        memset(dp, -1, sizeof(dp));
        printf("%lld\n", res + exact_ways(sum, 0, false));
    }

    return 0;
}
