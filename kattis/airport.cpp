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
using ld = double;
using pii = pair<int, int>;

template <class T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0): x(x), y(y) {}

    using P = Point;

    P operator+(const P& p) const {
        return {x + p.x, y + p.y};
    }

    P operator-(const P& p) const {
        return {x - p.x, y - p.y};
    }

    P operator*(const T& t) const {
        return {x * t, y * t};
    }

    P operator/(const T& t) const {
        return {x / t, y / t};
    }

    ld dot(const P& p) const {
        return x * p.x + y * p.y;
    }

    ld cross(const P& p) const {
        return x * p.y - y * p.x;
    }

    T dist2() const {
        return x * x + y * y;
    }

    ld dist() const {
        return sqrt(dist2());
    }
};

using pt = Point<ld>;
constexpr int MAXN = 202;
constexpr ld eps = 1e-9;
int n;
pt pts[MAXN];

inline void intersect(const pt& a, const pt& b, const pt& p, const pt& q, vector<pt>& ints) {
    pt v = b - a;
    pt w = q - p;
    pt pa = p - a;
    ld vpa = v.cross(pa);
    if (abs(v.cross(w)) < eps) {
        return;
    }

    if (vpa * v.cross(q - a) > eps) {
        return;
    }

    pt res = p - w * vpa / v.cross(w);
    ints.push_back(res);
}

ld segDist(const pt& a, const pt& b, const pt& c) {
    pt v = b - a;
    pt w = c - a;
    auto d = v.dist2(), t = min(d, max(static_cast<ld>(0.0), w.dot(v)));
    return (w * d - v * t).dist2() / d;
}

bool inside(const pt& p) {
    int hits = 0;
    for (pt *i = &pts[0], *j = &pts[n - 1]; i != &pts[n]; j = i++) {
        if (segDist(*i, *j, p) <= eps) {
            return true;
        }

        hits += (max(i->y, j->y) > p.y and min(i->y, j->y) <= p.y and
                ((*j - *i).cross(p - *i) > 0) == (i->y <= p.y));
    }

    return hits & 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);

    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &x, &y);
        pts[i] = pt(static_cast<ld>(x), static_cast<ld>(y));
    }
    pts[n] = pts[0];

    ld ans = 0.0L;
    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            pt v = pts[b] - pts[a];
            vector<pt> ints;
            ints.push_back(pts[a] - (pts[b] - pts[a]) * 1e7);
            ints.push_back(pts[a] + (pts[b] - pts[a]) * 1e7);
            for (int i = 0; i < n; ++i) {
                intersect(pts[a], pts[b], pts[i], pts[i + 1], ints);
            }

            sort(begin(ints), end(ints), [&](const pt& p, const pt& q) {
                return (p - pts[a]).dot(v) < (q - pts[a]).dot(v);
            });

            pt last = ints[0];
            for (int k = 0; k + 1 < ints.size(); ++k) {
                pt mid = (ints[k] + ints[k + 1]) * 0.5;
                if (!inside(mid)) {
                    last = ints[k + 1];
                }

                ans = max(ans, (ints[k + 1] - last).dist2());
            }
        }
    }

    printf("%.11lf\n", sqrt(ans));

    return 0;
}
