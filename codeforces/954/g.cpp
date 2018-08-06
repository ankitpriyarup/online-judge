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

constexpr int MAXN = 500050;
int n, r;
ll k;
ll a[MAXN];
ll bonus[MAXN];

bool works(ll mid) {
    memset(bonus, 0, sizeof(bonus));
    ll cur = 0LL;
    for (int i = 0; i < r; ++i) {
        cur += a[i];
    }

    ll bought = 0LL;
    for (int i = 0; i < n; ++i) {
        if (i - r - 1 >= 0) {
            cur -= a[i - r - 1];
            cur -= bonus[i - r - 1];
        }
        if (i + r < n) {
            cur += a[i + r];
            cur += bonus[i + r];
        }

        ll extra = max(0LL, mid - cur); 
        bought += extra;
        bonus[min(n - 1, i + r)] += extra;
        cur += extra;

        if (bought > k)
            return false;
    }

    return bought <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d %lld", &n, &r, &k);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", a + i);
    }

    ll lo = 0LL;
    ll hi = 1.5e18;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2LL;
        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%lld\n", lo);

    return 0;
}
