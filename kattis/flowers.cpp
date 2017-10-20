#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr ld STEP = 0.0000005L;

ld a, b, h;

ld f(ld x) {
    ld r = a * exp(-x * x) + b * sqrt(x);
    return r * r;
}

ld quad(ld lo, ld hi) {
    const int iters = 300000;
    ld gap = (hi - lo) / 2 / iters;
    ld vv = f(lo) + f(hi);
    for (int i = 1; i < 2 * iters; ++i) {
        vv += f(lo + i * gap) * (i & 1 ? 4 : 2);
    }

    return vv * gap / 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ld v;
    int n;
    scanf("%Lf %d", &v, &n);

    ld best_vol = 1e18;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%Lf %Lf %Lf", &a, &b, &h);
        ld vol = M_PI * quad(0, h);
        // printf("Found volume %.7Lf\n", vol);
        if (abs(vol - v) < abs(best_vol - v)) {
            best_vol = vol;
            ans = i;
        }
    }

    printf("%d\n", ans);

    return 0;
}
