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

constexpr ld EPS = 1e-6;
ll x, y;

ld vol(ld h) {
    ld a = (x - 2.0 * h);
    ld b = (y - 2.0 * h);
    return h * a * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%lld %lld", &x, &y);
        // a + 2 * h = X
        // b + 2 * h = Y
        // vol = h * (x - 2h) * (y - 2h)
        // vol = h * (xy - 4h(x + y) + 4h^2)
        // vol = xyh - 2h^2(x + y) + 4h^3
        // dV/dh = xy - 4h(x + y) + 12h^2
        ld a = 12.0L;
        ld b = -4.0L * (x + y);
        ld c = 1.0L * x * y;

        ld h1 = (-b + sqrt(b*b - 4 * a * c)) / (2.0 * a);
        ld h2 = (-b - sqrt(b*b - 4 * a * c)) / (2.0 * a);

        printf("%.17Lf\n", max(vol(h1), vol(h2)));
    }
    
    return 0;
}
