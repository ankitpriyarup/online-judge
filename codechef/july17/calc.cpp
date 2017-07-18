#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <complex>

using namespace std;

const long long BOUND = 2e2;
long long n, b;

void read() {
    scanf("%lld %lld", &n, &b);
}

long long f(long long x) {
    return x * ((n - x) / b);
}

void solve() {
    if (b >= n) {
        printf("%d\n", 0);
        return;
    }

    long long ans = 0LL;
    long long center = b * n / 2LL;

    for (long long i = max(0LL, center - BOUND); i <= min(n, center + BOUND); ++i) {
        ans = max(ans, f(i));
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        read();
        solve();
    }

    return 0;
}
