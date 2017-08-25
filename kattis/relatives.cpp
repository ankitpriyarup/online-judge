#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

const int MAXV = 32000;
int sieve[MAXV];
vector<int> primes;

void gen_sieve() {
    memset(sieve, 0, sizeof(sieve));

    sieve[0] = 0;
    sieve[1] = 0;
    sieve[2] = 2;

    for (int i = 2; i < MAXV; i += 2) {
        sieve[i] = 2;
    }

    primes.push_back(2);

    for (int i = 3; i < MAXV; i += 2) {
        if (!sieve[i]) {
            sieve[i] = i;
            primes.push_back(i);

            for (long long j = 1LL * i * i; j < MAXV; j += 2 * i) {
                sieve[j] = i;
            }
        }
    }
}

int main() {
    int x;
    gen_sieve();
    while (scanf("%d", &x) == 1) {
        if (x == 0) {
            break;
        }

        int ans = 1;
        for (const auto& prime : primes) {
            if (prime > x) {
                break;
            }

            if (x % prime != 0) {
                continue;
            }

            x /= prime;
            int a = 1;
            int b = prime;

            while (x % prime == 0) {
                x /= prime;
                a *= prime;
                b *= prime;
            }

            ans *= (b - a);
        }

        if (x > 1) {
            ans *= (x - 1);
        }

        if (x == 1 and ans == 1) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
