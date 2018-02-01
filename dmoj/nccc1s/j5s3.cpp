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

    int n;
    scanf("%d", &n);
    ll threshold = 1LL * n * (n - 1LL) / 2LL;
    /*
    ll count = 0;
    ll res = 1;
    for (int k = 1; k < n; ++k) {
        res = k;
        count += n - k;
    }
    */
    // n - 1 + n - 2 + ... >= threshold
    // k * n - k * (k - 1) / 2 >= threshold
    // 2 kn - k^2 - k >= n^2 / 2 - n / 2
    // 4 kn - 2 k^2 - 2 k >= n^2 - n
    // -2 k^2 + (4n - 2)k - (n^2 - n) >= 0
    // (-(4n - 2) +- sqrt((4n - 2)^2 - 4*2*(n^2 -n)))) / -4
    int lo = -1;
    int hi = n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2LL;
        ll res = 1LL * mid * n - 1LL * mid * (mid + 1) / 2LL;

        if (2LL * res >= threshold)
            hi = mid;
        else
            lo = mid;
    }

    printf("%d\n", max(1, min(n - 1, hi)));

    return 0;
}
