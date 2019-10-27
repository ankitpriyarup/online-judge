#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    vector<ll> sizes;
    for (ll s = 1; 2 * s < a; ++s) {
        ll l = a - 2 * s;
        ll w = b - 2 * s;
        ll h = s;
        ll vol = l * w * h;
        sizes.push_back(vol);
    }

    sort(all(sizes));
    sizes.erase(unique(all(sizes)), end(sizes));
    reverse(all(sizes));

    assert(sizes.size() >= 3);

    for (ll k = c; k <= g; k += sizes[0]) {
        if (f <= k and k % sizes[1] == d and k % sizes[2] == e) {
            cout << k << '\n';
            exit(0);
        }
    }
    
    return 0;
}
