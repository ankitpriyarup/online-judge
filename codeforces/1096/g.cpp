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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

/**
 * Author: Simon Lindholm
 * Date: 2016-09-10
 * License: CC0
 * Source: based on KACTL's FFT
 * Description: Can be used for convolutions modulo specific nice primes
 * of the form $2^a b+1$, where the convolution result has size at most $2^a$.
 * For other primes/integers, use two different primes and combine with CRT.
 * May return negative values.
 * Time: O(N \log N)
 * Status: Somewhat tested
 */
const ll mod = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

typedef vector<ll> vl;
void ntt(ll* x, ll* temp, ll* roots, int N, int skip) {
    if (N == 1) return;
    int n2 = N/2;
    ntt(x     , temp, roots, n2, skip*2);
    ntt(x+skip, temp, roots, n2, skip*2);
    rep(i,0,N) temp[i] = x[i*skip];
    rep(i,0,n2) {
        ll s = temp[2*i], t = temp[2*i+1] * roots[skip*i];
        x[skip*i] = (s + t) % mod; x[skip*(i+n2)] = (s - t) % mod;
    }
}

void ntt(vl& x, bool inv = false) {
    ll e = modpow(root, (mod-1) / sz(x));
    if (inv) e = modpow(e, mod-2);
    vl roots(sz(x), 1), temp = roots;
    rep(i,1,sz(x)) roots[i] = roots[i-1] * e % mod;
    ntt(&x[0], &temp[0], &roots[0], sz(x), 1);
}

vl conv(vl a, vl b) {
    int s = sz(a) + sz(b) - 1; if (s <= 0) return {};
    int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
    if (s <= 200) { // (factor 10 optimization for |a|,|b| = 10)
        vl c(s);
        rep(i,0,sz(a)) rep(j,0,sz(b))
            c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
        return c;
    }
    a.resize(n); ntt(a);
    b.resize(n); ntt(b);
    vl c(n); ll d = modpow(n, mod-2);
    rep(i,0,n) c[i] = a[i] * b[i] % mod * d % mod;
    ntt(c, true); c.resize(s); return c;
}

vl poly_exp(vl a, int e) {
    int s = sz(a) * e; if (s <= 0) return {};
    int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
    a.resize(n); ntt(a);
    vl c(n); ll d = modpow(n, mod - 2);
    rep(i,0,n) c[i] = modpow(a[i], e) * d % mod;
    ntt(c, true); c.resize(s); return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vl a(10, 0);
    int x;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        a[x] = 1;
    }

    while (a.back() == 0)
        a.pop_back();

    /*
    for (int i = 0; i < a.size(); ++i) {
        cout << "a[" << i << "] = " << a[i] << '\n';
    }
    */

    int half = n >> 1;
    vl res = poly_exp(a, half);

    /*
    for (int i = 0; i < res.size(); ++i) {
        cout << "res[" << i << "] = " << res[i] << '\n';
    }
    o*/

    ll ans = 0LL;
    for (ll v : res) {
        while (v < mod) {
            v += mod;
        }
        ans += v * v % mod;
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}
