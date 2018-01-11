#include <cstdio>

using namespace std;

long long n, s;

long long digsum(long long x) {
    long long ans = 0LL;
    while (x) {
        ans += x % 10;
        x /= 10;
    }

    return ans;
}

long long f(long long x) {
    return x - digsum(x);
}

int main() {
    scanf("%lld %lld", &n, &s);

    if (f(n) < s) {
        printf("%d\n", 0);
        return 0;
    }

    long long lo = 1LL;
    long long hi = n;

    while (lo + 1 < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (f(mid) >= s) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%lld\n", n - lo);

    return 0;
}
