#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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
using pt = pair<ll, ll>;

constexpr int MAXN = 10004;
ll ccw(const pt& a, const pt& b, const pt& c) {
    ll x1 = b.first - a.first;
    ll y1 = b.second - a.second;
    ll x2 = c.first - a.first;
    ll y2 = c.second - a.second;

    return x1 * y2  - x2 * y1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    ll x, y;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        vector<pt> pts;
        for (int i = 0; i < n; ++i) {
            scanf("%lld %lld", &x, &y);
            pts.push_back({x, y});
        }

        sort(begin(pts), end(pts));
        pts.erase(unique(begin(pts), end(pts)), end(pts));

        vector<pt> hull;
        if (pts.size() <= 2) {
            hull = pts;
        } else {
            for (int qqq = 0; qqq < 2; ++qqq) {
                int start = hull.size();
                for (int i = 0; i < n; ++i) {
                    while (hull.size() >= start + 2 and ccw(hull[hull.size() - 2], hull[hull.size() - 1], pts[i]) <= 0) {
                        hull.pop_back();
                    }

                    hull.push_back(pts[i]);
                }

                hull.pop_back();
                reverse(begin(pts), end(pts));
            }
        }

        int sz = hull.size();
        if (hull.size() <= 2) {
            printf("0.0\n");
        } else {
            ll area = hull[sz - 1].first * hull[0].second - hull[sz - 1].second * hull[0].first;
            for (int i = 0; i + 1 < sz; ++i) {
                area += hull[i].first * hull[i + 1].second - hull[i].second * hull[i + 1].first;
            }

            printf("%lld.%d\n", area / 2, area & 1 ? 5 : 0);
        }
    }
    
    return 0;
}
