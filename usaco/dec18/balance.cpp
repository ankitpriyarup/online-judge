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
using pt = pair<ll, ll>;

constexpr int MAXN = 100005;
int n;
ll f[MAXN];

ll ccw(const pt& a, const pt& b, const pt& c) {
    ll x1 = b.first - a.first;
    ll y1 = b.second - a.second;
    ll x2 = c.first - a.first;
    ll y2 = c.second - a.second;

    return x1 * y2 - x2 * y1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);

    vector<pt> pts;
    pts.emplace_back(0, 0);
    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf(" %lld", &f[i]);
        pts.emplace_back(i, f[i]);
    }
    pts.emplace_back(n + 1, 0);

    vector<pt> hull;
    for (const pt& p : pts) {
        while (hull.size() >= 2 and ccw(hull[(int)hull.size() - 2], hull.back(), p) >= 0) {
            hull.pop_back();
        }

        hull.push_back(p);
    }

    /*
    for (const pt& p : hull) {
        printf("%lld, %lld\n", p.first, p.second);
    }
    */

    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        while (idx + 1 < hull.size() and hull[idx + 1].first <= i) {
            ++idx;
        }

        ll dy = hull[idx + 1].second - hull[idx].second;
        ll dx = hull[idx + 1].first - hull[idx].first;

        ll qx = i - hull[idx].first;

        // 10^5, 10^5, 10^9 ... so close
        // unsigned?
        ld ans = hull[idx].second + qx * dy / static_cast<ld>(dx);
        constexpr ld EPS = 5e-6;
        printf("%lld\n", static_cast<ll>(100000LL * ans + EPS));
    }

    return 0;
}
