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
using pii = pair<ll, ll>;

constexpr int MAXN = 200005;
int n;
ll T;
pii spouts[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll num = 0LL;
    ll den = 0LL;

    scanf(" %d %lld", &n, &T);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &spouts[i].second);
    }
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &spouts[i].first);

        num += spouts[i].first * spouts[i].second;
        den += spouts[i].second;
    }

    sort(spouts, spouts + n);

    if (num < T * den) {
        T *= -1;
        for (int i = 0; i < n; ++i) {
            spouts[i].first *= -1LL;
        }
        reverse(spouts, spouts + n);
        num *= -1;
    }

    int ptr = n - 1;
    while (ptr >= 0 and num > T * den) {
        num -= spouts[ptr].first * spouts[ptr].second;
        den -= spouts[ptr].second;
        --ptr;
    }

    ++ptr;
    ld lo = 0.0;
    ld hi = spouts[ptr].second;
    for (int iter = 0; iter < 100; ++iter) {
        ld mid = (lo + hi) / 2.0L;
        ld nn = num + mid * spouts[ptr].first;
        ld dd = den + mid;
        if (nn <= T * dd) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%.17Lf\n", den + lo);

    return 0;
}
