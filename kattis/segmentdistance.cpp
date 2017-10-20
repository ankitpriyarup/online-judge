#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

int x[5], y[5];

ll ccw(int a, int b, int c) {
    ll x1 = x[b] - x[a];
    ll x2 = x[c] - x[a];

    ll y1 = y[b] - y[a];
    ll y2 = y[c] - y[a];

    return x1 * y2 - x2 * y1;
}

bool intersect() {
    ll v1 = ccw(0, 1, 2);
    ll v2 = ccw(0, 1, 3);
    ll v3 = ccw(2, 3, 0);
    ll v4 = ccw(2, 3, 1);

    return v1 * v2 < 0 and v3 * v4 < 0;
}

ld dist(int a, int b, int c) {
    int xd = (x[b] - x[a]) * (x[c] - x[a]);
    int yd = (y[b] - y[a]) * (y[c] - y[a]);

    int len = (x[b] - x[a]) * (x[b] - x[a]) + (y[b] - y[a]) * (y[b] - y[a]);

    ld t = (0.0L + xd + yd) / ((ld)len);
    t = min(1.0L, max(0.0L, t));

    ld xx = x[a] + t * (x[b] - x[a]);
    ld yy = y[a] + t * (y[b] - y[a]);

    ld xxd = xx - x[c];
    ld yyd = yy - y[c];

    return sqrt(xxd * xxd + yyd * yyd);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        for (int i = 0; i < 4; ++i) {
            scanf("%d %d", x + i, y + i);
        }

        if (intersect()) {
            printf("%.2f\n", 0.0);
        } else {
            ld l1 = dist(0, 1, 2);
            ld l2 = dist(0, 1, 3);
            ld l3 = dist(2, 3, 0);
            ld l4 = dist(2, 3, 1);

            // printf("%.3Lf %.3Lf %.3Lf %.3Lf \n", l1, l2, l3, l4);

            printf("%.2Lf\n", min(min(l1, l2), min(l3, l4)));
        }
    }
    
    return 0;
}
