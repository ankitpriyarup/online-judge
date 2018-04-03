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
using pii = pair<ll, ll>;
using line = tuple<ll, ll, ll>;

ll gcd(ll a, ll b) {
    if (a < 0) return gcd(-a, b);
    if (b < 0) return gcd(a, -b);
    return b ? gcd(b, a % b) : a;
}

pii normalize(const pii& p) {
    ll a = p.first;
    ll b = p.second;
    ll g = gcd(a, b);
    a /= g;
    b /= g;

    if (a < 0 or (a == 0 and b < 0)) {
        a *= -1;
        b *= -1;
    }

    return make_pair(a, b);
}

pii perp(const pii& p) {
    pii res(-p.second, p.first);
    return normalize(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    ll x1, y1, x2, y2;

    vector<line> lines;
    for (int i = 0; i < n; ++i) {
        scanf(" %lld %lld %lld %lld", &x1, &y1, &x2, &y2);

        pii slope(x1 - x2, y1 - y2);
        slope = normalize(slope);

        ll a = -slope.second;
        ll b = slope.first;
        ll c = -a * x1 - b * y1;

        assert(b >= 0);
        assert(a * x1 + b * y1 + c == 0);
        assert(a * x2 + b * y2 + c == 0);

        lines.push_back(make_tuple(a, b, c));
        // printf("Line %lld, %lld, %lld\n", get<0>(lines.back()), get<1>(lines.back()), get<2>(lines.back()));
    }

    // (a, b) -> dist -> freq
    map<pair<pii, ll>, ll> m;
    ll a1, b1, c1;
    ll a2, b2, c2;
    for (int i = 0; i < n; ++i) {
        tie(a1, b1, c1) = lines[i];
        for (int j = i + 1; j < n; ++j) {
            tie(a2, b2, c2) = lines[j];
            if (a1 != a2 or b1 != b2)
                continue;

            ll dc = abs(c1 - c2);

            // printf("Distance between lines %d and %d is like %lld\n", i, j, dc);

            pii slope = normalize(make_pair(a1, b1));
            m[make_pair(slope, dc)] += 1;
        }
    }

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        tie(a1, b1, c1) = lines[i];
        for (int j = i + 1; j < n; ++j) {
            tie(a2, b2, c2) = lines[j];
            if (a1 != a2 or b1 != b2)
                continue;

            ll dc = abs(c1 - c2);

            pii other = perp(make_pair(a1, b1));
            ans += m[make_pair(other, dc)];

            /*
            printf("At slope %lld %lld\n", a1, b1);
            printf("Distance between lines %d and %d is like %lld\n", i, j, dc);
            printf("Looking for slope %lld %lld\n", other.first, other.second);
            printf("Found %lld intersections\n", m[make_pair(other, dc)]);
            */
        }
    }

    printf("%lld\n", ans / 2LL);

    return 0;
}
