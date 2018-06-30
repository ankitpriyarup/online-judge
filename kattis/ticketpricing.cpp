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

constexpr int MAXN = 333;
int n, w;

int opts[MAXN];
int p[MAXN][MAXN];
int s[MAXN][MAXN];

ll dp[MAXN][MAXN];
ll solve(int week, int people) {
    assert(people >= 0);
    if (week < 0 or people == 0) {
        return 0LL;
    }

    if (dp[week][people] != -1)
        return dp[week][people];

    ll res = 0LL;
    for (int i = 0; i < opts[week]; ++i) {
        int bought = min(people, s[week][i]);
        ll cur_rev = 1LL * p[week][i] * bought;
        cur_rev += solve(week - 1, people - bought);

        res = max(res, cur_rev);
    }

    return dp[week][people] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &w);
    for (int rem = w; rem >= 0; --rem) {
        scanf(" %d", &opts[rem]);
        for (int i = 0; i < opts[rem]; ++i) {
            scanf(" %d", &p[rem][i]);
        }
        for (int i = 0; i < opts[rem]; ++i) {
            scanf(" %d", &s[rem][i]);
        }
    }

    memset(dp, -1, sizeof(dp));
    ll rev = -1;
    int ans = 0;
    for (int i = 0; i < opts[w]; ++i) {
        int bought = min(n, s[w][i]);
        ll cur_rev = 1LL * p[w][i] * bought;
        cur_rev += solve(w - 1, n - bought);

        if (cur_rev > rev) {
            rev = cur_rev;
            ans = p[w][i];
        } else if (cur_rev == rev) {
            ans = min(ans, p[w][i]);
        }
    }

    printf("%lld\n%d\n", rev, ans);

    return 0;
}
