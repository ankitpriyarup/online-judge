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

constexpr int MOD = 1e3;

struct mat {
    int a, b, c, d;
    mat()
        : a(1), b(0), c(0), d(1) {}
    mat(int a, int b, int c, int d)
        : a(a % MOD), b(b % MOD), c(c % MOD), d(d % MOD) {
    }

    mat mul(const mat& other) {
        int aa = a * other.a + b * other.c;
        int bb = a * other.b + b * other.d;
        int cc = c * other.a + d * other.c;
        int dd = c * other.b + d * other.d;

        return mat(aa, bb, cc, dd);
    }
};

mat cache[32];

mat exp(uint32_t exp) {
    mat res;
    for (uint32_t i = 0, p = 1; p <= exp; p <<= 1, ++i) {
        if (exp & p) {
            res = res.mul(cache[i]);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    uint32_t n;

    cache[0] = mat(3, 5, 1, 3);
    for (int i = 1; i <= 31; ++i) {
        cache[i] = cache[i - 1].mul(cache[i - 1]);
    }

    int tc = 1;
    while (T-- > 0) {
        scanf(" %u", &n);
        mat res = exp(n);
        int ans = 2 * res.a + 999;
        ans %= 1000;
        printf("Case #%d: %03d\n", tc++, ans);
    }

    return 0;
}
