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

constexpr int MAXN = 500005;
constexpr int LOGN = 20;
const double PI = acos(-1);

using carray = valarray<complex<double> >;

void fft(carray& x, carray& roots) {
    int N = x.size();
    if (N <= 1) return;

    carray even = x[slice(0, N / 2, 2)];
    carray odd = x[slice(1, N / 2, 2)];
    carray rs = roots[slice(0, N / 2, 2)];

    fft(even, rs);
    fft(odd, rs);

    for (int k = 0; k < N / 2; ++k) {
        auto t = roots[k] * odd[k];
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
    }
}

using vd = vector<double>;
vd conv(const vd& a, const vd& b) {
    int s = a.size() + b.size() - 1;
    int L = 32 - __builtin_clz(s);
    int n = 1 << L;

    if (s <= 0) return {};
    carray av(n), bv(n), roots(n);
    for (int i = 0; i < n; ++i) {
        roots[i] = polar(1.0, -2 * PI * i / n);
    }
    copy(begin(a), end(a), begin(av));
    fft(av, roots);

    copy(begin(b), end(b), begin(bv));
    fft(bv, roots);

    roots = roots.apply(conj);
    carray cv = av * bv;
    fft(cv, roots);

    vd c(s);
    for (int i = 0; i < s; ++i) {
        c[i] = cv[i].real() / n;
    }

    return c;
}

vd precomp() {
    vector<double> divs(MAXN, 0);
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            divs[j] += 1.0;
        }
    }

    return conv(divs, divs);
}

int st[LOGN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vd ans = precomp();
    for (int i = 1; i < MAXN; ++i) {
        st[0][i] = i;
    }

    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int i = 1; i < MAXN; ++i) {
            int k = i + (1 << j);
            if (k >= MAXN) 
                st[j + 1][i] = st[j][i];
            else {
                int a = st[j][i];
                int b = st[j][k];

                if (ans[a] >= ans[b])
                    st[j + 1][i] = a;
                else
                    st[j + 1][i] = b;
            }
        }
    }

    int T, a, b;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d", &a, &b);
        ++b;

        int dep = 31 - __builtin_clz(b - a);
        int c1 = st[dep][a];
        int c2 = st[dep][b - (1 << dep)];

        if (ans[c2] > ans[c1]) {
            printf("%d %d\n", c2, static_cast<int>(ans[c2] + 0.5));
        } else {
            printf("%d %d\n", c1, static_cast<int>(ans[c1] + 0.5));
        }

    }

    return 0;
}
