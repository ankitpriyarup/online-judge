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

constexpr int MAXN = 200045;
constexpr int MOD = 1e9 + 7;

inline int prod(int a, int b) {
    return (1LL * a * b) % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (exp & p)
            res = prod(res, cur);
        cur = prod(cur, cur);
    }

    return res;
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

int fact[MAXN], tcaf[MAXN];

void gen_fact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        fact[i] = prod(i, fact[i - 1]);
        
    tcaf[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
        assert(inv(fact[i]) == tcaf[i]);
    }
}

int choose(int n, int k) {
    if (k < 0 or k > n) return 0;
    return prod(fact[n], prod(tcaf[n - k], tcaf[k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    gen_fact();

    int n, m;
    while (T-- > 0) {
        scanf(" %d %d", &n, &m);
        if (n < 0) n = -n;
        // l + r = m
        // l - r = n
        // 2l = m + n
        if (n > m or ((m + n) & 1) > 0) {
            printf("%d\n", 0);
        } else {
            int num = choose(m, (n + m) / 2);
            int den = inv(modpow(2, m));
            printf("%d\n", prod(num, den));
        }
    }
   
    return 0;
}
