#include <cstdio>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#define MAXN 1000006
#define MAXP 1003

using namespace std;

bool not_prime[MAXP];
vector<int> primes;
int counts[MAXN];

int n;
int a[MAXN];

void gen_primes() {
    primes.clear();
    primes.push_back(2);
    memset(not_prime, 0, sizeof(not_prime));
    for (long long i = 3; i < MAXP; i += 2) {
        if (!not_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < MAXP; j += 2 * i) {
                not_prime[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    gen_primes();
    int num_primes = primes.size();

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &n);
        memset(counts, 0, sizeof(counts));

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);

            for (int pi = 0; pi < num_primes and primes[pi] <= a[i]; ++pi) {
                int p = primes[pi];
                int p2 = p * p;
                while (a[i] % p2 == 0) {
                    a[i] /= p2;
                }

                if (a[i] % p == 0) {
                    ++counts[p];
                    a[i] /= p;
                }
            }

            if (a[i] > 1) {
                ++counts[a[i]];
            }
        }

        long long ans = 0;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            ans += min(it->second, n - it->second);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
