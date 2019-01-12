#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

// thanks kactl

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    ll c;
    cin >> n >> c;
    // (hj - hi)^2 + C
    // hj^2 - 2hj hi + hi^2 + C
    // Each hi creates a line of the form -2 hi x + hi^2 + C
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    // returns max, so negate the lines
    // negation of ax + b is -ax - b
    LineContainer lc;
    lc.add(2LL * h[0], -h[0] * h[0] - c);

    constexpr ll INF = 1e18;
    vector<ll> dp(n, INF);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        dp[i] = -lc.query(h[i]) + h[i] * h[i];
        lc.add(2LL * h[i], - h[i] * h[i] - c - dp[i]);
        
        // cout << "dp[" << i << "] = " << dp[i] << '\n';
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
