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
constexpr int MAXV = 1003;

int n, p;
int a[MAXN];
int dp[MAXN][MAXV];

int solve(int idx, int ppl) {
    if (idx == 0)
        return ppl >= p ? 0 : 1;

    int& ans = dp[idx][ppl];
    if (ans != -1)
        return ans;

    ans = MAXN;
    // send people backwards
    for (int sent = 0; sent <= min(a[idx], ppl); ++sent) {
        ans = min(ans, solve(idx - 1, a[idx - 1] + sent) + (ppl - sent < p));
    }

    // ask for people from before
    for (int sent = 0; sent <= a[idx - 1]; ++sent) {
        ans = min(ans, solve(idx - 1, a[idx - 1] - sent) + (ppl + sent < p));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(n - 1, a[n - 1]));

    return 0;
}
