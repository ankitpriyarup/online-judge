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
using ld = double;
using pii = pair<int, int>;

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
vd conv(const vd& a, const vd& b) {
	int s = a.size() + b.size() - 1;
    int L = 32 - __builtin_clz(s);
    int n = 1 << L;
	if (s <= 0) return {};

	carray av(n), bv(n), roots(n);

	for (int i = 0; i < n; ++i)
        roots[i] = polar(1.0, -2 * M_PI * i / n);

    copy(begin(a), end(a), begin(av));
	fft(av, roots);

    copy(begin(b), end(b), begin(bv));
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

    int T;
    ll x;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, m;
        scanf("%d", &n);
        vector<ld> a(n + 1);
        for (int i = 0; i <= n; ++i) {
            scanf("%lld", &x);
            a[i] = x;
        }

        scanf("%d", &m);
        vector<ld> b(m + 1);
        for (int i = 0; i <= m; ++i) {
            scanf("%lld", &x);
            b[i] = x;
        }

        vector<ld> c = conv(a, b);
        vector<ll> ret(c.size(), 0LL);
        for (int i = 0; i < c.size(); ++i) {
            ld sgn = c[i] < 0 ? -1 : 1;
            ret[i] = c[i] + sgn * 0.5;
        }

        while (ret.size() > 1 and ret.back() == 0) {
            ret.pop_back();
        }

        printf("%lu\n", ret.size() - 1);
        for (ll x : ret) {
            printf("%lld ", x);
        }
        printf("\n");
    }
    
    return 0;
}
