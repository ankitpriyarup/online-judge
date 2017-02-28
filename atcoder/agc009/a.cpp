#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100005;

int n;
long long a[MAXN], b[MAXN];

long long compute(long long x, long long y) {
    if (x % y == 0) {
        return 0;
    }

    return y - (x % y);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", a + i, b + i);
    }

    long long steps = 0;
    for (int i = n - 1; i >= 0; --i) {
        steps += compute(a[i] + steps, b[i]);
    }

    printf("%lld\n", steps);

    return 0;
}
