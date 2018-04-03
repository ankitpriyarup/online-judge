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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int d, s;
    scanf("%d %d", &d, &s);

    ld lo = 0.0;
    ld hi = 1e18;
    for (int iter = 0; iter < 120; ++iter) {
        ld mid = (lo + hi) / 2.0L;
        if (mid + s < mid * cosh(d / (2.0L * mid))) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    ld len = 2.0L * hi * sinh(d / (2.0L * hi));
    printf("%.17Lf\n", len);

    return 0;
}
