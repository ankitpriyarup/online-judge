#include <cstdio>
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

const int MAXN = 2003;
const int MODS[] = {1000000007, 1000000009};
long long n;

inline int sum(const int& a, const int& b, const int& m) {
    int c = a + b;
    if (c >= m) {
        c -= m;
    }

    return c;
}

inline int prod(const int& a, const int& b, const int& m) {
    return (1LL * a * b) % m;
}

int modpow(const int& base, const int& exp, const int& m) {
    int cur = base;
    int ret = 1;
    for (int p = 1; p <= exp; p <<= 1) {
        if (exp & p) {
            ret = prod(ret, cur, m);
        }

        cur = prod(cur, cur, m);
    }

    return ret;
}

inline int inv(const int& x, const int& m) {
    return modpow(x, m - 2, m);
}

void read() {
    scanf("%lld\n", &n);
}

inline int gcd(const int& a, const int& b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    --n;
    for (int i = 0; i < 2; ++i) {
        // (2n - 2)! / (n - 1)! (n - 1)! `div` 2n! / (n + 1)! n!
        // [(2n - 2)! (n + 1)! n!] / [(n - 1)! (n - 1)! 2n!]
        // [(2n - 2)! n * (n + 1) * n] / [2n!]
        // [n * (n + 1) * n] / [(2n - 1) * 2n]
        // [(n + 1) * n] / [(2n - 1) * 2]

        // long long num = 1LL * (n + 1LL) * n / 2LL;
        // long long den = 2LL * n - 1;

        int m = n % MODS[i];
        int num = prod(prod(m + 1LL, m, MODS[i]), inv(2, MODS[i]), MODS[i]);
        int den = sum(prod(2, m, MODS[i]), MODS[i] - 1, MODS[i]);

        printf("%d%c", prod(num, inv(den, MODS[i]), MODS[i]), i ? '\n' : ' ');
    }
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
