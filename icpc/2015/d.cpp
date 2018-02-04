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

ld PI = acos(-1);
constexpr int MAXN = 10004;
int n, s;
int r[MAXN], x[MAXN], y[MAXN], z[MAXN];

inline ld clamp(ld x, int r) {
    return max(-1.0L * r, min(1.0L * r, x));
}

ld overlap(ld a, ld b, int i) {
    ld b0 = a - z[i];
    ld b1 = b - z[i];
    b0 = clamp(b0, r[i]);
    b1 = clamp(b1, r[i]);

    return PI * r[i] * r[i] * b1 - PI * b1 * b1 * b1 / 3.0L - PI * r[i] * r[i] * b0 + PI * b0 * b0 * b0 / 3.0L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &s);

    ld side = 100000.0;
    ld vol = side * side * side;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &r[i], &x[i], &y[i], &z[i]);
        vol -= 4.0L * PI * r[i] * r[i] * r[i] / 3.0L;
    }

    ld wanted_vol = vol / s;

    ld last = 0.0L;
    for (int i = 0; i < s; ++i) {
        ld lo = last;
        ld hi = side;

        for (int iter = 0; iter < 100; ++iter) {
            ld mid = (lo + hi) / 2.0L;
            ld slice = side * side * (mid - last);
            for (int i = 0; i < n; ++i) {
                slice -= overlap(last, mid, i);
            }

            if (slice > wanted_vol) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        printf("%.17Lf\n", (hi - last) / 1000.0L);
        last = hi;
    }

    return 0;
}
