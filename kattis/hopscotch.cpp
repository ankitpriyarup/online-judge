#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr ll MAXN = 2000006;
constexpr ll MOD = 1000000007;

inline ll sum(const ll& a, const ll& b) {
    ll c = a + b;
    if (c > MOD)
        c -= MOD;
    return c;
}

inline ll prod(const ll& a, const ll& b) {
    return (1LL * a * b) % MOD;
}

ll modpow(ll base, ll exp) {
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

ll inv(ll x) {
    return modpow(x, MOD - 2);
}

ll fact[MAXN], tcaf[MAXN];

ll choose(ll n, ll k) {
    return prod(fact[n], prod(tcaf[k], tcaf[n - k]));
}

ll get_top(ll n, ll x, ll k) {
    return n - x * k + k - 1;
    return n - x - (k - 1) * (x + 1) + k - 1LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fact[0] = fact[1] = 1;
    tcaf[0] = tcaf[1] = 1;

    for (ll i = 2; i < MAXN; i++) {
        fact[i] = prod(fact[i - 1], i);
        tcaf[i] = inv(fact[i]);
    }

    ll n, x, y;
    scanf("%lld %lld %lld", &n, &x, &y);
    ll ans = 0;

    for (ll k = 1; k <= MAXN; ++k) {
        ll top_x = get_top(n, x, k);
        ll top_y = get_top(n, y, k);
        
        if (n - x * k < 0 || n - y * k < 0) continue;

        ll by_x = choose(top_x % MOD, k - 1);
        ll by_y = choose(top_y % MOD, k - 1);

        ans = sum(ans, prod(by_x, by_y));
    }

    printf("%lld\n", ans);

    return 0;
}
