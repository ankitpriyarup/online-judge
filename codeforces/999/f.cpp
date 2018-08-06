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

constexpr int MAXN = 505;
constexpr int MAXK = 11;
constexpr int MAXV = 100005;
int n, k;
int card_freq[MAXV];
int man_freq[MAXV];
int joy[MAXK];

ll dp[MAXN][MAXN * MAXK];

ll solve(int men, int cards) {
    if (men == 0 or cards == 0)
        return 0;
    if (dp[men][cards] != -1)
        return dp[men][cards];

    ll ans = 0LL;
    for (int h = 1; h <= min(cards, k); ++h) {
        ans = max(ans, joy[h] + solve(men - 1, cards - h));
    }

    return dp[men][cards] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    int x;
    for (int i = 0; i < n * k; ++i) {
        scanf(" %d", &x);
        ++card_freq[x];
    }

    for (int i = 0; i < n; ++i) {
        scanf(" %d", &x);
        ++man_freq[x];
    }

    for (int i = 1; i <= k; ++i) {
        scanf(" %d", &joy[i]);
    }

    memset(dp, -1, sizeof(dp));
    ll ans = 0LL;
    for (int i = 0; i < MAXV; ++i) {
        if (man_freq[i]) {
            ans += solve(man_freq[i], card_freq[i]);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
