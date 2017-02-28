#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const long long MAXN = 100005;

int sieve[MAXN];

void gen_primes() {
    memset(sieve, -1, sizeof(sieve));

    for (int i = 2; i < MAXN; i += 2) {
        sieve[i] = 2;
    }

    for (int i = 3; i < MAXN; ++i) {
        if (sieve[i] == -1) {
            sieve[i] = i;
            for (long long j = 1LL * i * i; j < MAXN; j += 2 * i) {
                sieve[j] = i;
            }
        }
    }
}

int n;
int counts[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    gen_primes();

    cin >> n;
    int ans = 1;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;

        while (x > 1) {
            int factor = sieve[x];
            ++counts[factor];

            ans = max(ans, counts[factor]);

            while (x % factor == 0) {
                x /= factor;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
