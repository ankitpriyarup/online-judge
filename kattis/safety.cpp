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

constexpr int MAXN = 202;
int n;
int a[MAXN];
int sum;

bool can(int ind, double val) {
    double target = a[ind] + val * sum;
    double bonus = 0.0;
    for (int i = 0; i < n; ++i) {
        if (i == ind) continue;

        bonus += max(0.0, (target - a[i]) / sum);
    }

    return bonus < 1.0 - val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int tc = 1;
    while (T-- > 0) {
        scanf("%d", &n);
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        printf("Case #%d:", tc++);
        for (int i = 0; i < n; ++i) {
            double lo = 0.0;
            double hi = 1.0;
            for (int iter = 0; iter < 60; ++iter) {
                double mid = (lo + hi) / 2.0;
                if (can(i, mid)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            printf(" %.9lf", 100.0 * hi);
        }

        printf("\n");
    }

    return 0;
}
