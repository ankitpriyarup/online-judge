#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int n;

long long x[20];
long long y[20];
long long r[20];

long long dist(int i, int j) {
    long long xd = x[i] - x[j];
    long long yd = y[i] - y[j];

    return xd * xd + yd * yd;
}

bool intersect(int i, int j) {
    // two circles intersect if the distances between the centers is less than
    // the sum of the radii. If the quantities are equal we say they intersect

    return dist(i, j) <= (r[i] + r[j]) * (r[i] + r[j]);
}

bool valid(int mask) {
    for (int i = 0, p = 1; p <= mask; p <<= 1, ++i) {
        for (int j = 0, q = 1; q <= mask; q <<= 1, ++j) {
            if ((mask & p) > 0 and (mask & q) and i != j and intersect(i, j)) {
                // printf("%d %d intersect\n", i, j);
                return false;
            }
        }
    }

    return true;
}

long long get_area(int mask) {
    long long ans = 0LL;
    for (int i = 0, p = 1; p <= mask; p <<= 1, ++i) {
        if (mask & p) {
            ans += r[i] * r[i];
        }
    }

    return ans;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld %lld %lld", x + i, y + i, r + i);
        }

        long long ans = 0LL;
        for (int mask = 1; mask < (1 << n); ++mask) {
            // printf("mask: %x\n", mask);
            if (valid(mask)) {
                ans = max(ans, get_area(mask));
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
