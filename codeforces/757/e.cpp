#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 1000006;
const int LOGN = 20;
const int MOD = 1000000007;

int sieve[MAXN];

inline int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD) {
        c -= MOD;
    }

    return c;
}

inline int prod(int a, int b) {
    return (1LL * a * b) % MOD;
}

void gen_sieve() {
    memset(sieve, -1, sizeof(sieve));
    for (int i = 2; i < MAXN; i += 2) {
        sieve[i] = 2;
    }

    for (int i = 3; i < MAXN; i += 2) {
        if (sieve[i] != -1) {
            continue;
        }

        sieve[i] = i;
        for (long long j = 1LL * i * i; j < MAXN; j += 2 * i) {
            sieve[j] = i;
        }
    }
}

int table[MAXN][LOGN];

int main() {
    ios_base::sync_with_stdio(false);
    gen_sieve();
    table[0][0] = 1;
    for (int k = 1; k < LOGN; ++k) {
        table[0][k] = 2;
    }

    for (int r = 1; r < MAXN; ++r) {
        table[r][0] = 1;
        for (int k = 1; k < LOGN; ++k) {
            table[r][k] = sum(table[r][k - 1], table[r - 1][k]);
        }
    }

    // f_r(1) = 1
    // f_r(p) = r + 2
    // f_r(p^2) = (p + 1) * (p + 4) / 2
    // f_r(p^3) = (p + 1) * (p + 2) * (p + 6) / 6

    int q;
    scanf("%d", &q);
    int r, n;
    while (q-- > 0) {
        scanf("%d %d", &r, &n);
        int ans = 1;
        while (n > 1) {
            int pf = sieve[n];
            int k = 0;
            while (n % pf == 0) {
                ++k;
                n /= pf;
            }

            ans = prod(ans, table[r][k]);
        }

        printf("%d\n", ans);
    }

    return 0;
}
