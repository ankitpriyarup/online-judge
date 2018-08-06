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

constexpr int MOD = 1e9 + 9;

int sum(const int& a, const int& b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp)
            res = prod(res, cur);
        cur = prod(cur, cur);
    }

    return res;
}

char s[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b, k;
    scanf(" %d %d %d %d", &n, &a, &b, &k);
    scanf(" %s", s);

    int base = 0;
    for (int i = 0; i < k; ++i) {
        int sgn = s[i] == '+' ? 1 : MOD - 1;
        int poly = prod(modpow(a, n - i), modpow(b, i));
        base = sum(base, prod(sgn, poly));
    }

    int inva = modpow(a, MOD - 2);
    int factor = prod(modpow(inva, k), modpow(b, k));

    // b + kb + k^2 b + ...
    // b (1 + k + k^2 ...)
    int terms = (n + 1) / k;
    int res;
    if (factor == 1) {
        res = terms;
    } else {
        res = prod(sum(modpow(factor, terms), MOD - 1), modpow(factor - 1, MOD - 2));
    }

    res = prod(res, base);
    printf("%d\n", res);

    return 0;
}
