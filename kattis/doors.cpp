#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <complex>

using namespace std;

const double EPS = 1e-6;
typedef complex<double> pt;

double dot(const pt &a, const pt &b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

double cross(const pt &a, const pt &b, const pt &c) {
    const pt ba = b - a;
    const pt ca = c - a;

    return ba.real() * ca.imag() - ba.imag() * ca.real();
}

double dist(const pt &a, const pt &b) {
    return abs(a - b);
}

double line_pt_dist(const pt &a, const pt &b, const pt &c) {
    const pt vec = b - a;
    double proj = dot(vec, c - a) / dot(vec, vec);

    proj = max(0.0, min(proj, 1.0));
    const pt closest = a + proj * vec;

    return dist(c, closest);
}

int main() {
    // ios_base::sync_with_stdio(false);

    int r, l, w;
    scanf("%d %d %d", &r, &l, &w);
    double cap = min(2.0 * r, (double) min(l, w));

    int T;
    scanf("%d", &T);

    double A, B;
    while (T-- > 0) {
        scanf("%lf %lf", &A, &B);

        double ans = l;
        // cout << "0 " << ans << endl;
        pt start = pt(0, w);
        pt tip = pt(l * cos(A), w + l * sin(A));
        pt end = pt(l, w);

        if (A <= EPS + M_PI / 2) {
            ans = min(ans, line_pt_dist(start, tip, end));
            // cout << "1 " << ans << endl;
        }

        pt b_tip = pt(l * cos(B), l * sin(B));
        if (B <= M_PI / 2) {
            double gap = line_pt_dist(start, tip, b_tip);

            ans = min(ans, gap);

            gap = line_pt_dist(pt(0, 0), b_tip, start);
            ans = min(ans, gap);
            // cout << "2 " << ans << endl;
        } else {
            double gap = w - b_tip.imag();
            ans = min(ans, gap);
            // cout << "3 " << ans << endl;
        }

        printf("%.9lf\n", min(ans, cap) / 2.0);
    }

    return 0;
}
