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
ll m;
ll a[MAXN];

ll score(ll perbox) {
    ll boxes = 0LL;
    for (int i = 0; i < n; ++i) {
        boxes += (a[i] + perbox - 1) / perbox;
    }

    return boxes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf(" %d %lld", &n, &m) == 2) {
        if (n < 0) break;
        for (int i = 0; i < n; ++i) {
            scanf(" %lld", &a[i]);
        }

        ll lo = 0;
        ll hi = 1e9 + 7;
        while (lo + 1 < hi) {
            ll mid = (lo + hi) / 2;
            if (score(mid) <= m)
                hi = mid;
            else
                lo = mid;
        }

        printf("%lld\n", hi);
    }
    
    return 0;
}
