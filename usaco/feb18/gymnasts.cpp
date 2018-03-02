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

constexpr ll MOD = 1e9 + 7;

inline ll sum(const ll& a, const ll& b) {
    return (a + b) % MOD;
}

inline ll prod(const ll& a, const ll& b) {
    return (1LL * a * b) % MOD;
}

inline ll modpow(const ll& base, const ll& exp) {
    ll res = 1;
    ll cur = base;
    for (ll p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur);
        }
        cur = prod(cur, cur);
    }

    return res;
}

inline ll inv(const ll& x) {
    return modpow(x, MOD - 2);
}

inline ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll phi(ll n) {
    ll res = n;
    for (ll d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            while (n % d == 0) {
                n /= d;
            }

            res -= res / d;
        }
    }

    if (n > 1)
        res -= res / n;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("gymnasts.in", "r", stdin);
    freopen("gymnasts.out", "w", stdout);

    ll n;
    scanf("%lld", &n);

    ll ans = (n % MOD);
    bool is_prime = true;
    for (ll d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            ll factor = modpow(2, d) - 2;
            ans = sum(ans, prod(factor, phi(n / d)));
            if (d != n / d) {
                factor = modpow(2, n / d) - 2;
                ans = sum(ans, prod(factor, phi(d)));
            }
        }
    }

    // 35 36 38 39 40
    // assert(n == 36);
    printf("%lld\n", ans);

    return 0;
}
