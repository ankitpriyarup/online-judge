/*
USER: rednano1
PROG: fc
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <complex>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef complex<double> pt;
int n;
vector<pt> points;
vector<pt> convex_hull;

bool cmp(pt& a, pt& b) {
    if (a.real() == b.real()) {
        return a.imag() < b.imag();
    }

    return a.real() < b.real();
}

double dist(pt a, pt b) {
    double x = a.real() - b.real();
    double y = a.imag() - b.imag();
    return sqrt(x * x + y * y);
}

/*
 *  i j k
 *  a b 0
 *  c d 0
 */

double ccw(pt a, pt b, pt c) {
    return (b.real() - a.real()) * (c.imag() - a.imag()) - (b.imag() - a.imag()) * (c.real() - a.real());
}

void compute_hull() {
    convex_hull.clear();

    for (int step = 0; step < 2; ++step) {
        size_t start = convex_hull.size();

        for (pt p : points) {
            while (convex_hull.size() >= start + 2 
                    and ccw(convex_hull[convex_hull.size() - 2], convex_hull[convex_hull.size() - 1], p) <= 0) {
                convex_hull.pop_back();
            }

            convex_hull.push_back(p);
        }

        convex_hull.pop_back();
        reverse(points.begin(), points.end());
    }
}

int main() {
    ifstream fin("fc.in");
    ofstream fout("fc.out");

    fin >> n;
    double x, y;
    for (int i = 0; i < n; ++i) {
        fin >> x >> y;
        points.push_back(pt(x, y));
    }
    fin.close();

    if (n <= 1) {
        fout << 0 << '\n';
        fout.close();
        return 0;
    }

    // find the smallest point
    sort(points.begin(), points.end(), cmp);

    compute_hull();

    int sz = convex_hull.size();
    double ans = 0;
    for (int i = 1; i < sz; ++i) {
        ans += dist(convex_hull[i], convex_hull[i - 1]);
    }

    if (sz > 2)
        ans += dist(convex_hull[sz - 1], convex_hull[0]);

    fout << fixed << setprecision(2) << ans << '\n';
    fout.close();

    return 0;
}
