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

constexpr int MAXN = 200005;

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
// c[x] = sum of a[i] a[x - i] over all i
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
    vector<ll> a(MAXN, 0LL);
    a[0] = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[x] = 1;
    }

    vd b = self_conv(a);

    int q;
    scanf("%d", &q);
    int ans = 0;
    while (q-- > 0) {
        scanf("%d", &x);
        if (a[x] > 0 or b[x] > 0.5L) {
            ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}
