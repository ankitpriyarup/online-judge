#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000006;

// sieve[i] = 0 iff i is prime
bool sieve[MAXN];
int cum[MAXN];

int a, b, k;

void gen_sieve() {
    memset(sieve, 0, sizeof(sieve));
    sieve[0] = sieve[1] = 1;
    for (int i = 4; i < MAXN; i += 2) {
        sieve[i] = 1;
    }

    for (int i = 3; i < MAXN; i += 2) {
        if (!sieve[i]) {
            for (long long j = 1LL * i * i; j < MAXN; j += i) {
                sieve[j] = 1;
            }
        }
    }
}

void gen_cum() {
    cum[0] = 0;
    for (int i = 1; i < MAXN; ++i) {
        cum[i] = cum[i - 1] + (sieve[i] == 0);
    }
}

bool works(int l) {
    for (int x = a; x + l - 1 <= b; ++x) {
        // printf("Interval [%d, %d] has %d primes\n", x, x + l - 1, cum[x + l - 1] - cum[x - 1]);
        if (cum[x + l - 1] - cum[x - 1] < k)
            return false;
    }

    return true;
}

int main() {
    scanf("%d %d %d", &a, &b, &k);

    gen_sieve();
    gen_cum();

    if (!works(b - a + 1)) {
        printf("%d\n", -1);
    } else if (works(1)) {
        printf("%d\n", 1);
    } else {
        int lo = 1;
        int hi = b - a + 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (works(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        printf("%d\n", hi);
    }

    return 0;
}
