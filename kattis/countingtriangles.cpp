#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <complex>

using namespace std;

typedef complex<double> pt;

const int MAXN = 50;
int n;

pt segs[MAXN][2];

inline double cross(const pt &a, const pt &b) { return imag(conj(a) * b); }

// cross product of (a - c) and (b - c)
inline double ccw(pt a, pt b, pt c) {
    return cross(a - c, b - c);
}

// check if two line segments intersect
bool intersect(int a, int b) {
    double s1 = ccw(segs[a][0], segs[a][1], segs[b][0]);
    double s2 = ccw(segs[a][0], segs[a][1], segs[b][1]);

    double t1 = ccw(segs[b][0], segs[b][1], segs[a][0]);
    double t2 = ccw(segs[b][0], segs[b][1], segs[a][1]);

    // ensure that the signs are different in both cases
    return s1 * s2 < 0 and t1 * t2 < 0;
}

int main() {
    double x1, y1, x2, y2;
    while (scanf("%d", &n) == 1) {
        if (n == 0)
            break;

        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            segs[i][0] = pt(x1, y1);
            segs[i][1] = pt(x2, y2);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!intersect(i, j))
                    continue;

                for (int k = j + 1; k < n; ++k) {
                    if (intersect(i, k) and intersect(j, k)) {
                        ++ans;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
