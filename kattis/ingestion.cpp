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

constexpr int MAXN = 102;
constexpr int MAXM = 20005;
int n, m;
ll a[MAXN];
ll eat[MAXN];
// best you can do after considering the first i foods and at eat[j]
ll dp[MAXN][MAXM];

ll solve(int x, int y) {
    if (x >= n)
        return 0LL;

    if (dp[x][y] != -1)
        return dp[x][y];

    ll food = min((ll) y, a[x]);
    ll ret = food + solve(x + 1, 2 * y / 3);
    // don't eat next
    ret = max(ret, food + solve(x + 2, y));
    // don't eat more
    ret = max(ret, food + solve(x + 3, m));
    // don't eat
    ret = max(ret, solve(x + 1, y));

    return dp[x][y] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(0, m));

    return 0;
}
