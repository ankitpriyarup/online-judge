#include <cstdio>
#include <cmath>

using namespace std;

using ld = long double;

ld PI = acos(-1.0L);

inline ld cylinder(ld radius, ld height) {
    return PI * radius * radius * height;
}

inline ld cone(ld radius, ld height) {
    return cylinder(radius, height) / 3.0;
}

ld solve(ld D, ld v) {
    ld lo = 0.0L;
    ld hi = D;

    for (int iter = 0; iter < 100; ++iter) {
        ld d = (lo + hi) / 2.0L;

        ld total = cylinder(D / 2.0L, D);
        ld remaining = cylinder(d / 2.0, d)
            + 2.0L * (cone(D / 2.0, D / 2.0) - cone(d / 2.0, d / 2.0));

        if (total - remaining > v) {
            lo = d;
        } else {
            hi = d;
        }
    }

    return (lo + hi) / 2.0;
}

int main() {
    int d, v;

    while (scanf("%d %d", &d, &v) == 2) {
        if (d == 0 and v == 0) {
            break;
        }

        printf("%.12Lf\n", solve(d, v));
    }
    return 0;
}
