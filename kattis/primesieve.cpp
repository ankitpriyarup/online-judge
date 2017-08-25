#include <cstdio>
#include <bitset>

using namespace std;

constexpr int MAXN = 100000002;

bitset<MAXN> sieve;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    sieve[0] = 1;
    sieve[1] = 1;

    int primes = 0;
    for (int i = 2; i <= n; ++i) {
        if (!sieve[i]) {
            ++primes;
            for (long long j = 1LL * i * i; j <= n; j += i) {
                sieve[j] = i;
            }
        }
    }

    printf("%d\n", primes);
    printf("%d\n", sieve[10]);

    int x;
    while (q-- > 0) {
        scanf("%d", &x);
        printf("%d\n", !sieve[x]);
    }

    return 0;
}
