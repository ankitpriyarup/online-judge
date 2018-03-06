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

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 500005;
int na, nb, nc;
ll a[MAXN], b[MAXN], c[MAXN];

ll mycount(ll* v, int len, const ll& a, const ll& b) {
    return upper_bound(v, v + len, b) - lower_bound(v, v + len, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll d;
    while (scanf("%lld %d %d %d", &d, &na, &nb, &nc) == 4) {
        for (int i = 0; i < na; ++i) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < nb; ++i) {
            scanf("%lld", &b[i]);
        }
        for (int i = 0; i < nc; ++i) {
            scanf("%lld", &c[i]);
        }

        ll ans = 0LL;
        for (int i = 0; i < na; ++i) {
            ans += mycount(b, nb, a[i], a[i] + d) * mycount(c, nc, a[i], a[i] + d);
        }

        for (int i = 0; i < nb; ++i) {
            ans += mycount(a, na, b[i] + 1, b[i] + d) * mycount(c, nc, b[i], b[i] + d);
        }

        for (int i = 0; i < nc; ++i) {
            ans += mycount(a, na, c[i] + 1, c[i] + d) * mycount(b, nb, c[i] + 1, c[i] + d);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
