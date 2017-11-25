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

constexpr int MAXN = 1e6 + 1e2;
constexpr int MOD = 1e9 + 7;

void sum(int& a, const int& b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (exp & p) {
            res = prod(res, cur);
        }

        cur = prod(cur, cur);
    }

    return res;
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

int fact[MAXN], tcaf[MAXN];

void gen_fact() {
    fact[0] = fact[1] = 1;
    tcaf[0] = tcaf[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        fact[i] = prod(fact[i - 1], i);
    }
    tcaf[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
        // assert(tcaf[i] == inv(fact[i]));
    }
}

inline int choose(int n, int k) {
    return prod(fact[n], prod(tcaf[k], tcaf[n - k]));
}

int sieve[MAXN];

void gen_sieve() {
    for (int i = 2; i < MAXN; i += 2) {
        sieve[i] = 2;
    }

    for (int i = 3; i < MAXN; i += 2) {
        if (sieve[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                sieve[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();
    gen_sieve();

    int T;
    scanf("%d", &T);

    int x, y;
    while (T-- > 0) {
        scanf("%d %d", &x, &y);
        int ans = 1;
        // sieve
        while (x > 1) {
            int factor = sieve[x];
            int ct = 0;
            while (x % factor == 0) {
                x /= factor;
                ++ct;
            }

            // printf("Factor %d count %d\n", factor, ct);
            // distribute ct balls over y bins
            ans = prod(ans, choose(y + ct - 1, ct));
        }

        printf("%d\n", prod(ans, modpow(2, y - 1)));
    }

    return 0;
}
