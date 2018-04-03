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

template <typename T>
struct Point {
    using P = Point;

    T x, y;

    Point(T x=0, T y=0): x(x), y(y) {}

    P operator+(const P& p) const {
        return P(x + p.x, y + p.y);
    }

    P operator-(const P& p) const {
        return P(x - p.x, y - p.y);
    }

    T dot(const P& p) const {
        return x * p.x + y * p.y;
    }

    T cross(const P& p) const {
        return x * p.y - y * p.x;
    }
};

using P = Point<ll>;

// check if c is on segment a, b inclusive
bool on_seg(const P& a, const P& b, const P& c) {
    P da = c - a;
    P db = c - b;

    return da.cross(db) == 0 and da.dot(db) <= 0;
}

template <class It, class P>
bool insidePolygon(It begin, It end, const P& p, bool& on_edge) {
    on_edge = false;
    int n = 0;
    for (It i = begin, j = end - 1; i != end; j = i++) {
        if (on_seg(*i, *j, p)) {
            on_edge = true;
            return false;
        }
        n += (max(i->y, j->y) > p.y and min(i->y, j->y) <= p.y and
                ((*j - *i).cross(p - *i) > 0) == (i->y <= p.y));
    }

    return n & 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (scanf(" %d", &n) == 1) {
        if (n == 0) break;

        vector<P> pts;
        ll x, y;
        for (int i = 0; i < n; ++i) {
            scanf(" %lld %lld", &x, &y);
            pts.push_back({x, y});
        }

        int q;
        scanf("%d", &q);
        while (q-- > 0) {
            scanf(" %lld %lld", &x, &y);
            P query(x, y);
            bool on_edge = false;
            bool hits = insidePolygon(begin(pts), end(pts), query, on_edge);

            if (on_edge) {
                printf("on\n");
            } else if (hits) {
                printf("in\n");
            } else {
                printf("out\n");
            }
        }
    }

    return 0;
}
