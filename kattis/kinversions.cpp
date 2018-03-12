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

// Taken from kactl
typedef valarray<complex<double> > carray;
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

typedef vector<double> vd;
// c[x] = sum of a[i] b[x - i] over all i
vd conv(const vector<int>& a, const vector<int>& b) {
    int s = a.size() + b.size() - 1;
    int L = 32 - __builtin_clz(s);
    int n = 1 << L;
    if (s <= 0) return {};

    carray av(n), bv(n), roots(n);

    for (int i = 0; i < n; ++i)
        roots[i] = polar(1.0, -2 * M_PI * i / n);

    for (int i = 0; i < a.size(); ++i) {
        av[i] = a[i];
        bv[i] = b[i];
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

constexpr int MAXN = 1000006;
int n;
char s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    int n = strlen(s);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        a[i]         = s[i] == 'A' ? 0 : 1;
        b[n - i - 1] = s[i] == 'A' ? 1 : 0;
    }

    vd c = conv(a, b);
    for (int i = n - 2; i >= 0; --i) {
        printf("%lld\n", static_cast<ll>(0.4 + c[i]));
    }

    return 0;
}
