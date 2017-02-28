#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <complex>

using namespace std;

typedef complex<double> pt;

const double PI = 3.14159265358979323846264338;
const double EPS = 1e-7;

bool inside(long double dist, int r1, int r2) {
    return (dist - r2 - EPS <= -r1) or (r1 >= dist + r2 - EPS);
}

long double slice(long double dist, long double r1, long double r2) {
    // We have two variables here. The circles intersect at some point h above
    // the x axis. The other variable is s, which is the length along the x axis
    // from the origin where the point is above. To summarize:
    // h^2 + s^2 = r1^2
    // (d - s)^2 + h^2 = r2^2
    //
    // Really all we care about is the angle tho. Let's solve for s.
    // s^2 - (d - s)^2 = r1^2 - r2^2
    // s^2 - d^2 + 2ds - s^2 = r1^2 - r2^2
    // -d^2 + 2ds = r1^2 - r2^2
    // s = (r1^2 - r2^2 + d^2) / 2d
    //
    // Now once we have s, theta is just 2 * acos(s / r1)

    long double s = (r1 * r1 - r2 * r2 + dist * dist) / (2.0L * dist);
    long double theta = 2 * acos(s / r1);

    // area of the cone is pi * r * r * theta / 2 pi
    // area of the triangle is 1/2 r * r * sin theta

    long double cone_area = r1 * r1 * theta / 2.0L;
    long double triangle_area = r1 * r1 * sin(theta) / 2.0L;

    return cone_area - triangle_area;
}

int main() {
    int x1, y1, r1;
    int x2, y2, r2;

    scanf("%d %d %d", &x1, &y1, &r1);
    scanf("%d %d %d", &x2, &y2, &r2);

    // center (x1 y1) at the origin
    x2 -= x1;
    y2 -= y1;
    x1 = 0;
    y1 = 0;

    long double rot_angle = -atan2(y2, x2);
    // rotate (x, y) down to the x axis
    // cos t -sin t
    // sin t cos t

    // d is the distance from the origin on the x axis to the center of the circle
    long double d = cos(rot_angle) * x2 - sin(rot_angle) * y2;
    long double d2 = d * d;

    if (r1 + r2 <= d - EPS) {
        printf("%.12f\n", 0.0);
    } else if (inside(d, r1, r2)) {
        double r = min(r1, r2);
        printf("%.12f\n", PI * r * r);
    } else {
        long double s1 = slice(d, r1, r2);
        long double s2 = slice(d, r2, r1);

        printf("%.12Lf\n", s1 + s2);
    }

    return 0;
}
