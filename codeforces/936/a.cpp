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

ll k, d, t;

ld f(ld x) {
    if (x < k) {
        return x / static_cast<ld>(t);
    } else {
        return k / static_cast<ld>(t) + (x - k) / static_cast<ld>(2LL * t);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%lld %lld %lld", &k, &d, &t);
    // find smallest n such that n d >= k
    // n >= k / d
    ll n = (k + d - 1) / d;
    ld per_set = static_cast<ld>(2 * k + n * d - k) / 2 / t;

    // m * ps < 1
    // m < 1 / ps
    ld m = floor(1.0L / per_set);
    // printf("m: %.2Lf\n", m);

    ld lo = 0.0;
    ld hi = 1e18;
    for (int iter = 0; iter < 100; ++iter) {
        ld mid = (lo + hi) / 2.0;
        if (m * per_set + f(mid) >= 1.0) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    // printf("%.17Lf\n", hi);
    printf("%.11Lf\n", m * n * d + hi);

    return 0;
}
