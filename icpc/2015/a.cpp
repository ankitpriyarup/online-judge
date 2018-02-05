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

    int p, a, b, c, d, n;
    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    vector<ld> res(n);

    for (int i = 1; i <= n; ++i) {
        res[i - 1] = 1.0L * p * (sin(1.0L * a * i + b) + cos(1.0L * c * i + d) + 2.0L);
    }

    ld mx = res[0];
    ld ans = 0.0L;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, res[i]);
        ans = max(ans, mx - res[i]);
    }

    printf("%.17Lf\n", ans);

    return 0;
}
