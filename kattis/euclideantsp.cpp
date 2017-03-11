#include <cstdio>
#include <cmath>

using namespace std;

int n;
long double p, s, v;

long double f(long double c) {
    long double compute = n * pow(log2(n), c * sqrt(2)) / (p * 1e9);
    long double travel = s * (1.0L + 1.0L / c) / v;

    return compute + travel;
}

int main() {
    scanf("%d %Lf %Lf %Lf", &n, &p, &s, &v);

    long double lo = 1e-6;
    long double hi = 1000;

    while (isinf(f(2.0L * hi / 3.0))) {
        hi /= 2.0;
    }
    for (int iter = 0; iter <= 100; ++iter) {
        long double mid1 = lo + (hi - lo) / 3.0L;
        long double mid2 = lo + 2.0L * (hi - lo) / 3.0L;
        // printf("%.6Lf %.6Lf %.6Lf %.6Lf\n", lo, mid1, mid2, hi);
        // printf("%.6Lf %.6Lf\n", f(mid1), f(mid2));
        if (f(mid1) < f(mid2)) {
            hi = mid2;
        } else {
            lo = mid1;
        }
    }

    long double c = (lo + hi) / 2.0L;
    printf("%.12Lf %.12Lf\n", f(c), c);
    return 0;
}
