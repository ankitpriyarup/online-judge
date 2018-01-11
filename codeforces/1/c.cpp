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

struct pt {
    ld x, y;

    pt operator+(const pt& other) const {
        return {x + other.x, y + other.y};
    }
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
    pt operator*(const ld& v) const {
        return {v * x, v * y};
    }

    pt operator/(const ld& v) const {
        return {x / v, y / v};
    }

    pt perp() const {
        return {-y, x};
    }

    ld abs() const {
        return hypot(x, y);
    }

    ld cross(const pt& p) const {
        return x * p.y - y * p.x;
    }

    pt rotate(const ld& theta) const {
        return {x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)};
    }
} pts[3];

pt operator*(const ld& v, const pt& p) {
    return p * v;
}

const ld PI = acos(-1.0L);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ld x, y;
    for (int i = 0; i < 3; ++i) {
        scanf("%Lf %Lf", &x, &y);
        pts[i] = pt{x, y};
    }

    // find the circumcenter of these points
    // intersection of the perpendicular bisectors
    pt s1 = (pts[1] + pts[2]) / 2.0L;
    pt e1 = s1 + 1000.0L * (pts[1] - pts[2]).perp();

    pt s2 = (pts[0] + pts[2]) / 2.0L;
    pt e2 = s2 + 1000.0L * (pts[2] - pts[0]).perp();

    ld c1 = (s2 - s1).cross(e1 - s1);
    ld c2 = (e2 - s1).cross(e1 - s1);
    pt center = (c1 * e2 - c2 * s2) / (c1 - c2);

    // printf("Center: %.4Lf %.4Lf\n", center.x, center.y);

    for (int i = 0; i < 3; ++i)
        pts[i] = pts[i] - center;

    ld theta = atan2(pts[0].y, pts[0].x);
    for (int i = 0; i < 3; ++i)
        pts[i] = pts[i].rotate(-theta);

    ld rad = pts[0].x;
    constexpr ld EPS = 1e-4;
    int sides = 3;
    for (; ; ++sides) {
        int match = 0;
        for (int i = 0; i < sides; ++i) {
            pt p = {rad, 0.0L};
            p = p.rotate(2.0L * PI * i / sides);
            // printf("Considering %d sides index %d: (%.4Lf, %.4Lf)\n", sides, i, p.x, p.y);

            ld min_delta = 1e12;
            for (int j = 0; j < 3; ++j) {
                ld delta = (pts[j] - p).abs();
                min_delta = min(min_delta, delta);
                if (delta < EPS) ++match;
            }

            // printf("Min delta %.6Lf\n", min_delta);
        }

        // printf("%d matches\n", match);
        if (match == 3)
            break;
    }

    theta = 2.0L * PI / sides;
    ld tri_area = 0.5L * rad * rad * sin(theta);
    ld ans = sides * tri_area;

    printf("%.17Lf\n", ans);
}
