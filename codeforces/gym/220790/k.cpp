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
int n, w, h;
int x[MAXN], y[MAXN];

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

    scanf("%d %d %d", &n, &w, &h);
    vector<pt> pts;
    int x, y;
    int min_h = MAXN;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        pts.emplace_back(x, y);
        min_h = min(min_h, y);
    }

    pts.emplace_back(0, h);
    pts.emplace_back(w, h);

    sort(begin(pts), end(pts));
    pts.erase(unique(begin(pts), end(pts)), end(pts));

    /*
    for (const auto& pt : pts) {
        printf("%lld %lld\n", pt.first, pt.second);
    }
    */

    vector<pt> hull;
    if (pts.size() <= 2) {
        hull = pts;
    } else {
        for (int qqq = 0; qqq < 2; ++qqq) {
            int start = hull.size();
            for (int i = 0; i < pts.size(); ++i) {
                while (hull.size() >= start + 2 and ccw(hull[hull.size() - 2], hull[hull.size() - 1], pts[i]) <= 0) {
                    hull.pop_back();
                }

                hull.push_back(pts[i]);
            }

            hull.pop_back();
            reverse(begin(pts), end(pts));
        }
    }

    /*
    for (const auto& pt : hull) {
        printf("%lld %lld\n", pt.first, pt.second);
    }
    */

    ld area = w * h - w * min_h;
    for (int i = 0; i < hull.size(); ++i) {
        int j = (i + 1) % hull.size();
        // printf("Points (%lld, %lld) to (%lld, %lld)\n", hull[i].first, hull[i].second, hull[j].first, hull[j].second);
        if (hull[i].second == h and hull[j].second == h) {
            continue;
        }
        if (hull[i].first == hull[j].first)
            continue;

        ld m = (hull[j].second - hull[i].second) / static_cast<ld>(hull[j].first - hull[i].first);
        ld b = hull[i].second - m * hull[i].first;

        ld y1 = b;
        ld y2 = m * w + b;
        // printf("%.2Lf %.2Lf\n", y1, y2);
        ld aa = w * (y1 + y2) / 2.0L;
        // printf("%.2Lf\n", aa);
        area = min(area, w * h - aa);
    }

    printf("%.17Lf\n", area);

    return 0;
}
