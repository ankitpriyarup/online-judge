#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>


using namespace std;

using ld = long double;

constexpr ld EPS = 1e-5;
constexpr ld EEPS = 1e-6;

inline bool eq(const ld& x, const ld& y, const ld& eps=EEPS) {
    return abs(x - y) <= eps;
}

struct pt {
    ld x, y;

    bool operator==(const pt& other) const {
        return eq(x, other.x) and eq(y, other.y);
    }

    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }

    ld operator^(const pt& other) const {
        return x * other.y - y * other.x;
    }
};

int n;
vector<pt> pts;
vector<int> inds;

inline int sgn(ld x) {
    if (-EEPS < x and x < EEPS) {
        return 0;
    } else if (x < EEPS) {
        return -1;
    } else {
        return 1;
    }
}

bool intersect(const pair<pt, pt>& l1, const pair<pt, pt> l2) {
    if (l1.first == l2.first or l1.first == l2.second or l1.second == l2.first or l1.second == l2.second) {
        return false;
    }

    pt a1 = l1.first;
    pt a2 = l1.second;
    pt b1 = l2.first;
    pt b2 = l2.second;

    return sgn((a2 - a1) ^ (b1 - a1)) != sgn((a2 - a1) ^ (b2 - a1))
        and sgn((b2 - b1) ^ (a1 - b1)) != sgn((b2 - b1) ^ (a2 - b1));
}

bool safe() {
    vector<pair<pt, pt> > segs;
    for (int i = 0; i < n; ++i) {
        segs.push_back({pts[inds[i]], pts[inds[(i + 1) % n]]});
    }

    for (int i = 0; i < segs.size(); ++i) {
        for (int j = i + 1; j < segs.size(); ++j) {
            if (intersect(segs[i], segs[j])) {
                // printf("Segment from (%.3Lf %.3Lf) to (%.3Lf %.3Lf) intersects with (%.3Lf %.3Lf) to (%.3Lf %.3Lf)\n", segs[i].first.x, segs[i].first.y, segs[i].second.x, segs[i].second.y, segs[j].first.x, segs[j].first.y, segs[j].second.x, segs[j].second.y);

                return false;
            }
        }
    }

    return true;
}

ld get_area() {
    // shoelace theorem
    // x1 y1
    // x2 y2
    // x3 y3
    // area = x1y2 - 
    ld area = 0LL;
    for (int i = 0; i < n; ++i) {
        area += pts[inds[i]] ^ pts[inds[(i + 1) % n]];
    }

    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    scanf("%d", &T);
    n = 7;
    while (T-- > 0) {
        ld x, y;
        inds.clear();
        pts.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%Lf %Lf", &x, &y);

            pts.push_back({x, y});
            inds.push_back(i);
        }

        ld exp;
        scanf("%Lf", &exp);

        bool found = false;
        do {
            if (found) break;
            if (safe()) {
                ld area = abs(get_area());
                ld prob = area * area * area / 8.0L / 8.0L / 8.0L;
                // printf("%.3Lf %.3Lf\n", prob, exp);
                if (eq(prob, exp, EPS)) {
                    for (int x : inds) {
                        printf("%d ", x + 1);
                    }
                    printf("\n");
                    found = true;
                    break;
                }
            }
        } while (next_permutation(begin(inds), end(inds)));
    }

    return 0;
}
