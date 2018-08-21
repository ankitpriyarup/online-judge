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

struct pt {
    ll x, y, h;
};
constexpr int MAXN = 1000006;
int n;
ll tx, ty;
pt pts[MAXN];

ll gcd(ll a, ll b) {
    if (a < 0) return gcd(-a, b);
    if (b < 0) return gcd(a, -b);
    return b ? gcd(b, a % b) : a;
}

int lis(const vector<pair<ll, ll>>& v) {
    vector<pair<ll, int>> res;
    for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        pair<ll, int> el = make_pair(v[i].second, i);
        auto it = lower_bound(begin(res), end(res), make_pair(v[i].second, 0));
        if (it == res.end()) {
            res.push_back(el);
            it = --res.end();
        }
        *it = el;
    }

    return res.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> tx >> ty;
    cin >> n;
    map<pair<ll, ll>, vector<pair<ll, ll> > > by_slope;
    ll x, y, h;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> h;
        ll dx = x - tx;
        ll dy = y - ty;
        ll dist = dx * dx + dy * dy;
        ll g = gcd(dx, dy);
        dx /= g;
        dy /= g;

        pair<ll, ll> slope = make_pair(dx, dy);
        by_slope[slope].push_back({dist, h});
    }

    ll ans = 0LL;
    for (auto& item : by_slope) {
        sort(begin(item.second), end(item.second));
        ans += lis(item.second);
    }

    cout << ans << '\n';

    return 0;
}
