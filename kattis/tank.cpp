#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int ITER = 100;
constexpr ld EPS = 1e-6;

constexpr int MAXN = 104;

struct pt {
    ld x, y;
};
int n;
ld d, l;
pt pts[MAXN];

ld f(const ld& height) {
    vector<pt> cur_pts;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if (pts[i].y > height and pts[j].y > height) {
            continue;
        }

        if (pts[i].y <= height) {
            cur_pts.push_back(pts[i]);
        }

        if (pts[j].y > height) {
            ld new_x;
            if (abs(pts[i].y - pts[j].y) <= EPS) {
                new_x = pts[i].x;
            } else {
                new_x = pts[i].x + (pts[j].x - pts[i].x) * (height - pts[i].y) / (pts[j].y - pts[i].y);
            }

            cur_pts.push_back({new_x, height});
            continue;
        } 

        if (pts[i].y > height and pts[j].y <= height) {
            ld new_x;
            if (abs(pts[i].y - pts[j].y) <= EPS) {
                new_x = pts[i].x;
            } else {
                new_x = pts[i].x + (pts[j].x - pts[i].x) * (height - pts[i].y) / (pts[j].y - pts[i].y);
            }

            cur_pts.push_back({new_x, height});
        }
    }

    ld area = 0.0L;
    for (int i = 0; i < cur_pts.size(); ++i) {
        int j = (i + 1) % cur_pts.size();
        area += cur_pts[i].x * cur_pts[j].y - cur_pts[i].y * cur_pts[j].x;
    }

    return abs(area) / 2.0L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int dd, lll;
    scanf("%d %d", &dd, &lll);
    d = dd / 100.0L;
    l = lll / 1000.0L;

    ld maxY = 0.0L;
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        pts[i] = {(ld)x / 100.0L, (ld)y / 100.0L};

        maxY = max(maxY, pts[i].y);
    }

    ld lo = 0;
    ld hi = maxY + EPS;

    for (int iter = 0; iter <= ITER; ++iter) {
        ld mid = (lo + hi) / 2.0L;
        ld vol = d * f(mid);

        if (vol <= l) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%.2Lf\n", 100.0L * (lo + hi) / 2.0L);

    return 0;
}
