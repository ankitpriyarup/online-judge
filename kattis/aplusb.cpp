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
#include <valarray>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXV = 50000;

// Taken from kactl
typedef valarray<complex<ld> > carray;
void fft(carray& x, carray& roots) {
	int N = x.size();
	if (N <= 1) return;
	carray even = x[slice(0, N/2, 2)];
	carray odd = x[slice(1, N/2, 2)];
	carray rs = roots[slice(0, N/2, 2)];
	fft(even, rs);
	fft(odd, rs);
	for (int k = 0; k < N / 2; ++k) {
		auto t = roots[k] * odd[k];
		x[k    ] = even[k] + t;
		x[k+N/2] = even[k] - t;
	}
}

typedef vector<ld> vd;
// c[x] = a[i] b[x - i]
vd self_conv(const vector<ll>& a) {
	int s = a.size() + a.size() - 1;
    int L = 32 - __builtin_clz(s);
    int n = 1 << L;
	if (s <= 0) return {};

	carray av(n), bv(n), roots(n);

	for (int i = 0; i < n; ++i)
        roots[i] = polar(1.0, -2 * M_PI * i / n);

    for (int i = 0; i < a.size(); ++i) {
        av[i] = a[i];
        bv[i] = a[i];
    }
	fft(av, roots);
	fft(bv, roots);

	roots = roots.apply(conj);
	carray cv = av * bv;
    fft(cv, roots);
	vd c(s);

    for (int i = 0; i < s; ++i)
        c[i] = cv[i].real() / n;

	return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    scanf("%d", &n);
    vector<ll> freq(2 * MAXV + 1, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++freq[x + MAXV];
    }

    ll zero = freq[MAXV];
    freq[MAXV] = 0;

	vector<ld> c = self_conv(freq);
    ll ans = 0LL;

	for (int val = -MAXV; val <= MAXV; ++val) {
        if (val == 0) {
            ans += zero * (zero - 1) * (zero - 2);
            continue;
        }

        ll ways = static_cast<ll>(c[val + 2 * MAXV] + 0.5);
        if (val % 2 == 0) {
            int half = val / 2;
            ll f = freq[half + MAXV];
            ways -= f;
        }

        ans += ways * freq[val + MAXV];
        ans += 1LL * freq[val + MAXV] * freq[-val + MAXV] * zero;
        ans += 2LL * zero * freq[val + MAXV] * (freq[val + MAXV] - 1);
	}

    printf("%lld\n", ans);

    return 0;
}
