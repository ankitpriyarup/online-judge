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

struct pt {
    ld x, y;

    pt operator+(const pt& o) const {
        return {x + o.x, y + o.y};
    }
    pt operator-(const pt& o) const {
        return {x - o.x, y - o.y};
    }
    pt operator*(const ld& v) const {
        return {x * v, y * v};
    }
    ld dot(const pt& other) const {
        return x * other.x + y * other.y;
    }
} pts[3], v;

int r;

ld hit_time(const pt& p1, const pt& v, const pt& p2) {
    // (p1 + vt - p2)^2 = (2r)^2
    // p1^2 + 2 p1vt - 2 p1p2 - 2 vt p2 + v^2 t^2 + p2^2 = 4r^2
    // v^2 t^2 + (2 p1 v - 2 v p2) t + (p1^2 - 2 p1 p2 + p2^2 - 4r^2) = 0
    ld a = v.dot(v);
    ld b = 2.0L * (p1.dot(v) - p2.dot(v));
    ld c = (p1.dot(p1) - 2 * p1.dot(p2) + p2.dot(p2) - 4.0 * r * r);

    ld disc = b * b - 4.0L * a * c;
    if (disc < 0.0L) {
        return -1;
    }

    return (-b - sqrt(disc)) / 2.0 / a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; ++i) {
        scanf("%Lf %Lf", &pts[i].x, &pts[i].y);
    }

    scanf("%Lf %Lf %d", &v.x, &v.y, &r);

    ld time_2 = hit_time(pts[0], v, pts[1]);
    ld time_3 = hit_time(pts[0], v, pts[2]);

    if (time_2 < 0 and time_3 < 0) {
        printf("%d\n", 5);
        return 0;
    }

    if (time_3 < 0 or (time_2 > 0 and time_2 < time_3)) {
        // hit 2 first
        pts[0] = pts[0] + v * time_2;
        pt nv = pts[1] - pts[0];

        /*
        printf("p0: %.2Lf %.2Lf\n", pts[0].x, pts[0].y);
        printf("p1: %.2Lf %.2Lf\n", pts[1].x, pts[1].y);
        printf("nv: %.2Lf %.2Lf\n", nv.x, nv.y);
        printf("ht: %.2Lf\n", ht);
        */

        ld ht = hit_time(pts[1], nv, pts[2]);
        if (ht < 0) {
            printf("%d\n", 3);
        } else {
            printf("%d\n", 1);
        }
    } else {
        // hit 3 first
        pts[0] = pts[0] + v * time_3;
        pt nv = pts[2] - pts[0];

        if (hit_time(pts[2], nv, pts[1]) < 0) {
            printf("%d\n", 4);
        } else {
            printf("%d\n", 2);
        }
    }

    return 0;
}
