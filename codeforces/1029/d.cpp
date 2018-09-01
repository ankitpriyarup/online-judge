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

int len(ll x) {
    int ans = 0;
    while (x) {
        ++ans;
        x /= 10LL;
    }

    return ans;
}

constexpr int MAXN = 200005;
int n, k;
ll a[MAXN];
map<int, int> shifts[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &a[i]);
        int m = len(a[i]);

        a[i] %= k;
        shifts[m][a[i]]++;

        ll self_shift = a[i];
        for (int i = 0; i < m; ++i) {
            self_shift *= 10LL;
            self_shift %= k;
        }

        self_shift += a[i];
        if (self_shift >= k) {
            self_shift -= k;
        }
        if (self_shift == 0) {
            --ans;
        }
    }

    for (int i = 0; i < n; ++i) {
        ll v = a[i];
        for (int x = 1; x < 11; ++x) {
            v = v * 10LL % k;
            ll goal = k - v;
            goal = goal == k ? 0 : goal;
            if (shifts[x].find(goal) != end(shifts[x]))
                ans += shifts[x][goal];
        }
    }

    printf("%lld\n", ans);
    return 0;
}
