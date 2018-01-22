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
using ld = double;
using pii = pair<int, int>;

ld pt[3][2];

ld ff(ld x, ld y) {
    ld res = 0.0;
    for (int i = 0; i < 3; ++i) {
        ld dx = x - pt[i][0];
        ld dy = y - pt[i][1];

        res += sqrt(dx * dx + dy * dy);
    }

    return res;
}

pair<ld, ld> f(ld x) {
    ld lo = -10;
    ld hi = 1111;

    for (int iter = 0; iter < 100; ++iter) {
        ld mid1 = lo + (hi - lo) / 3.0;
        ld mid2 = lo + 2.0 * (hi - lo) / 3.0;

        if (ff(x, mid1) > ff(x, mid2)) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }

    ld y = (lo + hi) / 2.0;
    return {y, ff(x, y)};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; ++i) {
        cin >> pt[i][0] >> pt[i][1];
    }

    ld lo = -10;
    ld hi = 1111;

    for (int iter = 0; iter < 100; ++iter) {
        ld mid1 = lo + (hi - lo) / 3.0;
        ld mid2 = lo + 2.0 * (hi - lo) / 3.0;
        if (f(mid1).second > f(mid2).second) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }
    ld x = (lo + hi) / 2.0L;
    ld y = f(x).first;

    cout << fixed << setprecision(10) << x << ' ' << y << '\n';

    return 0;
}
