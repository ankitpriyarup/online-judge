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

    friend ostream& operator<<(ostream& out, const Point &p) {
        return out << p.x << ", " << p.y;
    }
};

using pt = Point<ll>;
using line = tuple<ll, ll, ll>;
constexpr int MAXN = 1003;
int n;
pt pts[MAXN];

ll gcd(ll a, ll b) {
    if (a == 0 and b == 0)
        return 1;

    if (a < 0)
        return gcd(-a, b);
    if (b < 0)
        return gcd(a, -b);

    return b == 0 ? a : gcd(b, a % b);
}

line make_line(const pt& p0, const pt& p1) {
    // find the equation of the line going through these points
    // ax0 + by0 = c
    // ax1 + by1 = c
    //
    // m = dy / dx
    // y = mx + b
    // y' = dy / dx x' + b
    // dx y' = dy x' + dx b
    // dx y' - dy x' = dx b
    // b = (dx y' - dy x') / dx
    //
    // y = mx + b
    // y = dy / dx x + (dx y' - dy x') / dx
    // dx y = dy x + dx y' - dy x'
    // 0 = dy x - dx y + dx y' - dy x'
    ll dx = p1.x - p0.x;
    ll dy = p1.y - p0.y;
    assert(!(dx == 0 and dy == 0));

    ll a = dy;
    ll b = -dx;
    ll c = dx * p0.y - dy * p0.x;

    ll g = gcd(a, gcd(b, c));

    if (a / g < 0 or (a == 0 and b / g < 0))
        g *= -1;

    return make_tuple(a / g, b / g, c / g);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        pts[i] = pt{2 * x, 2 * y};
    }

    map<pt, int> ptCenters;
    map<line, int> lines;
    for (int i = 0; i < n; ++i) {
        ptCenters[pts[i]] += 1;
        for (int j = i + 1; j < n; ++j) {
            pt midpoint = (pts[i] + pts[j]) / 2LL;
            ptCenters[midpoint] += 2;

            pt perp = (pts[j] - pts[i]).perp();
            lines[make_line(midpoint, midpoint + perp)] += 2;
            lines[make_line(pts[i], pts[j])] += 0;
        }
    }

    int ans = n;
    for (const auto& center : ptCenters) {
        ans = min(ans, n - center.second);
    }

    ll a, b, c;
    for (const auto& l : lines) {
        tie(a, b, c) = l.first;
        int cur = n - l.second;
        for (int i = 0; i < n; ++i) {
            if (a * pts[i].x + b * pts[i].y + c == 0) {
                --cur;
            }
        }

        ans = min(ans, cur);
    }

    printf("%d\n", ans);
    
    return 0;
}
