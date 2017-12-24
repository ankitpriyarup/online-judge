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

constexpr ll MAXN = 1e6 + 60;
ll n, m;

inline ll sum(const ll& a, const ll& b) {
    return (0LL + a + b) % m;
}

inline ll prod(const ll& a, const ll& b) {
    return (1LL * a * b) % m;
}

ll modpow(const ll& base, const ll& exp) {
    ll res = 1;
    ll cur = base;
    for (ll p = 1; p <= exp; p <<= 1) {
        if (exp & p) {
            res = prod(res, cur);
        }

        cur = prod(cur, cur);
    }

    return res;
}

inline ll inv(const ll& x) {
    return modpow(x, m - 2);
}

ll catalan(ll x) {
    ll count = 0;
    ll num = 1;
    ll den = 1;
    for (ll i = x + 1; i <= 2 * x; ++i) {
        ll v = i;
        while (v % m == 0) {
            ++count;
            v /= m;
        }

        num = prod(num, v);
    }

    for (ll i = 1; i <= x; ++i) {
        ll v = i;
        while (v % m == 0) {
            --count;
            v /= m;
        }

        den = prod(den, v);
    }

    if (count) return 0;
    return prod(num, inv(den));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%lld %lld", &n, &m);

        ll a = 1;
        ll b = 1;
        for (ll i = 0; i < n; ++i) {
            ll c = sum(a, b);
            a = b;
            b = c;
        }

        ll ans = b;
        if (n % 2 == 0) {
            // n choose n/2
            ans = sum(ans, catalan(n / 2));

            // subtract out overlap
            // n / 2 + 1 options for that
            ll sub = n / 2 + 1;
            sub %= m;

            ans = sum(ans, m - sub);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
