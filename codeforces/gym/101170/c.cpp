#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 102;
int num_shields;

// firefly coords
int fx, fy;

int lower[MAXN];
int upper[MAXN];
long double factor[MAXN];

long double find_x(const long double vx) {
    // distance = rate * time
    int remaining = fy;
    long double pos = 0;
    for (int i = 0; i < num_shields; ++i) {
        int height = upper[i] - lower[i];
        remaining -= height;
        pos += vx * factor[i] * height;
    }

    pos += remaining * vx;

    return pos;
}

int main() {
    scanf("%d %d", &fx, &fy);
    scanf("%d", &num_shields);
    for (int i = 0; i < num_shields; ++i) {
        scanf("%d %d %Lf", lower + i, upper + i, factor + i);
    }

    long double lo = -1e18;
    long double hi = 1e18;

    for (int iter = 0; iter < 200; ++iter) {
        long double mid = (lo + hi) / 2.0L;
        if (find_x(mid) < (long double) fx) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%.12Lf\n", (lo + hi) / 2.0L);

    return 0;
}
