#include <cstdio>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    if (a <= 0) {
        return a;
    }

    return a * b / gcd(a, b);
}

int main() {
    int T;
    scanf("%d", &T);

    int n, x;
    while (T-- > 0) {
        scanf("%d", &n);
        long long ans = 1LL;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);

            ans = lcm(ans, x);
        }

        if (ans < 0 or ans > 1e9L) {
            printf("%s\n", "More than a billion.");
        } else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}
