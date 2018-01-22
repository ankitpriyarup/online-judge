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

double solve(int cur, int total, double prob, ll money) {
    if (cur == total)
        return money;

    // probability ranges from t to 1
    // there is some probability b where
    // money = b * solve(x + 1)
    double s = solve(cur + 1, total, prob, 2LL * money);
    double b = money / s;
    b = max(prob, min(1.0, b));

    // then if prob is [t, b], just take what we have
    // otherwise, if we're in [b, 1], we make integral from b to 1 of x s dx
    // which is integral of s [x^2/2 | b to 1]
    // which is s * (1/2 - b^2 / 2)

    return ((b - prob) * money + ((1 - b * b) / 2.0) * s) / (1 - prob);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    double t;
    while (scanf("%d %lf", &n, &t) == 2) {
        if (n == 0) break;

        printf("%.3lf\n", solve(0, n, t, 1LL));
    }

    return 0;
}
