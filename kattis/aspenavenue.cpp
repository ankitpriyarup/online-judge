#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
using ld = long double;

constexpr int MAXN = 2003;
constexpr ld INF = 1e18;
int n;
int half;
int l, w;
int p[MAXN];
ld dp[MAXN][MAXN];

ld getx(int a) {
    ld res = 1.0L * a * l / (half - 1.0L);
    return res;
}

ld dist(ld dx, ld dy) {
    return sqrt(dx * dx + dy * dy);
}

ld solve(int a, int b) {
    int x = a + b;
    if (x == n) {
        // printf("solve(%d, %d) = %.4Lf\n", a, b, 0.0L);
        return 0.0L;
    }

    ld& res = dp[a][b];
    if (res > -0.5) return res;

    res = INF;
    if (a < half) {
        res = min(res, dist(p[x] - getx(a), 0.0) + solve(a + 1, b));
    }
    if (b < half) {
        res = min(res, dist(p[x] - getx(b), w) + solve(a, b + 1));
    }

    // printf("solve(%d, %d) = %.4Lf\n", a, b, res);
    return res;
}

int main() {
    scanf("%d", &n);
    half = n >> 1;
    scanf("%d %d", &l, &w);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    sort(p, p + n);

    for (int i = 0; i <= half; ++i) {
        for (int j = 0; j <= half; ++j) {
            dp[i][j] = -1.0;
        }
    }
    printf("%.17Lf\n", solve(0, 0));

    return 0;
}
