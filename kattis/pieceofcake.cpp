#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;
using ld = long double;

constexpr int MAXN = 2500;
int n, k;
ld p[MAXN][2];
ld prob[MAXN];

ld cross(int a, int b) {
    // negated because points are given clockwise
    return -(p[a][0] * p[b][1] - p[a][1] * p[b][0]);
}

/**
 * Linearity of expectation. Take the area of each directed
 * possible edge and multiply by probability of using it.
 */
int main() {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf(" %Lf %Lf", &p[i][0], &p[i][1]);
    }
    // ((n - 2) C (k - 2)) / (n C k)
    // [(n - 2)! k! (n - k)!] / [(k - 2)! (n - k)! n!]
    // [k (k - 1)] / [n (n - 1)]
    prob[0] = k * (k - 1.0) / n / (n - 1.0);
    for (int i = 1; i < n - 1; ++i) {
        prob[i] = prob[i - 1] * (n - k + 1 - i) / (n - 1 - i);
    }

    ld ans = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < i + n; ++j) {
            ld area = cross(i, (j % n));
            ans += area * prob[j - i - 1];
        }
    }

    printf("%.9Lf\n", ans / 2.0L);
}
