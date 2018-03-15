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

template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }

    P fixneg() const {
        if (x >= 0) return *this;
        else return P(-x, -y);
    }

    friend ostream& operator<<(ostream& out, const Point &p) {
        return out << p.x << ", " << p.y;
    }
};

template <class P>
bool onSegment(const P& s, const P& e, const P& p) {
    if (s == p or e == p) return false;
    P ds = p-s, de = p-e;
    bool res = ds.cross(de) == 0 && ds.dot(de) <= 0;
    // cout << p << " on " << "(" << s << ", " << e << ") = " << res << '\n';
    return res;
}

template <class P>
bool segmentIntersectionQ(P s1, P e1, P s2, P e2) {
    // cout << "seg (" << "(" << s1 << ", " << e1 << ", " << s2 << ", " << e2 << ") = " << '\n';
    if (s1 == s2) {
        return onSegment(s1, e1, e2) or onSegment(s2, e2, e1);
    }
    if (s1 == e2) {
        return onSegment(s1, e1, s2) or onSegment(s2, e2, e1);
    }
    if (e1 == s2) {
        return onSegment(s1, e1, e2) or onSegment(s2, e2, s1);
    }
    if (e1 == e2) {
        return onSegment(s1, e1, s2) or onSegment(s2, e2, s1);
    }

    P v1 = e1 - s1, v2 = e2 - s2, d = s2 - s1;
    auto a = v1.cross(v2), a1 = d.cross(v1), a2 = d.cross(v2);
    if (a == 0) { // parallel
        auto b1 = s1.dot(v1), c1 = e1.dot(v1),
             b2 = s2.dot(v1), c2 = e2.dot(v1);
        return !a1 && max(b1,min(b2,c2)) <= min(c1,max(b2,c2));
    }

    if (a < 0) { a = -a; a1 = -a1; a2 = -a2; }

    return (0 <= a1 && a1 <= a && 0 <= a2 && a2 <= a);
}

using pt = Point<ll>;

constexpr int MAXN = 3003;
int n, m;
pt pts[MAXN];
pii edges[MAXN];
int uf[MAXN];

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}
int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;
    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        pts[i] = pt{(ll)x, (ll)y};
        uf[i] = i;
    }

    int comps = n;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        edges[i] = make_pair(x, y);
        comps -= merge(x, y);
    }

    if (comps != 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (segmentIntersectionQ(pts[edges[i].first], pts[edges[i].second], pts[edges[j].first], pts[edges[j].second])) {
                // cout << pts[edges[i].first] << ' ' <<  pts[edges[i].second] << ' ' <<  pts[edges[j].first] << ' ' <<  pts[edges[j].second] << '\n';
                cout << "-1\n";
                return 0;
            }
        }

        for (int j = 0; j < n; ++j) {
            if (j == edges[i].first or j == edges[i].second)
                continue;
            if (onSegment(pts[edges[i].first], pts[edges[i].second], pts[j])) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << (2 - n + m) << '\n';

    return 0;
}
