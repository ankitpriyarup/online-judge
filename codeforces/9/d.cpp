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

constexpr int MAXN = 36;
ll dp[MAXN][MAXN];

// exact n and h
ll solve(int n, int h) {
    if (n <= 1 and h == 0)
        return 1LL;

    else if (n <= 1 or h == 0)
        return 0LL;

    ll& ans = dp[n][h];
    if (ans != -1)
        return ans;

    ans = 0LL;
    for (int left = 0; left < n; ++left) {
        int right = n - left - 1;
        for (int lh = 0; lh < h - 1; ++lh) {
            // printf("Break %d %d into %d %d and %d %d\n", n, h, left, lh, right, h - 1);
            ans += solve(left, lh) * solve(right, h - 1);
        }

        for (int rh = 0; rh < h - 1; ++rh) {
            // printf("Break %d %d into %d %d and %d %d\n", n, h, left, h -1 , right, rh);
            ans += solve(left, h - 1) * solve(right, rh);
        }

        // printf("Break %d %d into %d %d and %d %d\n", n, h, left, h -1 , right, h - 1);
        ans += solve(left, h - 1) * solve(right, h - 1);
    }

    // printf("dp[%d][%d] = %lld\n", n, h, ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    int n, h;
    scanf("%d %d", &n, &h);

    ll ans = 0LL;
    for (int hh = h - 1; hh <= n; ++hh)
        ans += solve(n, hh);

    printf("%lld\n", ans);
    return 0;
}
