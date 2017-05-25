#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 1003;
int n, t;
pair<int, int> segments[MAXN];

long double time(long double c) {
    long double ret = 0;
    for (int i = 0; i < n; ++i) {
        // d = r * t
        ret += segments[i].first / (segments[i].second + c);
    }

    return ret;
}

int main() {
    scanf("%d %d", &n, &t);
    int d, s;
    long double m = 1e9;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &d, &s);
        segments[i] = make_pair(d, s);
        m = min(m, (long double) s);
    }

    long double hi = 1e9L;
    long double lo = -m;
    for (int iter = 0; iter < 100; ++iter) {
        long double mid = (lo + hi) / 2.0L;

        if (time(mid) <= ((long double) t)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%.17Lf\n", (lo + hi) / 2.0L);

    return 0;
}
