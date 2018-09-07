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

constexpr int MAXN = 500005;
int n;
ll a[MAXN];

ll dp[2][100][100];

ll go(int k, int i, int j) {
    if (i == j) {
        return a[i];
    }

    ll& ans = dp[k][i][j];
    if (ans != -1) {
        return ans;
    }

    if (k == 1) {
        ans = -1e18;
        for (int l = i; l < j; ++l) {
            ans = max(ans, go(1, i, l) - go(0, l + 1, j));
            ans = max(ans, go(1, l + 1, j) - go(0, i, l));
        }
    } else {
        ans = 1e18;
        for (int l = i; l < j; ++l) {
            ans = min(ans, go(0, i, l) - go(1, l + 1, j));
            ans = min(ans, go(0, l + 1, j) - go(1, i, l));
        }
    }

    // cout << k << ", " << i << ", " << j << " = " << ans << '\n';
    return ans;
}

ll brute() {
    memset(dp, -1, sizeof(dp));
    return go(1, 0, n - 1);
}

ll solve() {
    if (n == 1) {
        return a[0];
    }

    ll tot = 0LL;
    bool all_pos = true;
    bool all_neg = true;
    for (int i = 0; i < n; ++i) {
        all_pos &= a[i] > 0;
        all_neg &= a[i] < 0;
        tot += abs(a[i]);
    }

    ll ans = 0;
    sort(a, a + n);
    if (all_pos) {
        ans = tot - 2LL * a[0];
    } else if (all_neg) {
        ans = tot + 2LL * a[n - 1];
    } else {
        ans = tot;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // cout << brute() << '\n';
    cout << solve() << '\n';
    return 0;
}
