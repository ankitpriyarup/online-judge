#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 300000001;
constexpr int SQRT = 18000;
uint32_t n, a, b, c, d;
bitset<SQRT> sieve;
vector<int> primes;

inline uint32_t f(uint32_t x) {
    uint32_t x2 = x * x;
    uint32_t x3 = x2 * x;

    return a * x3 + b * x2 + c * x + d;
}

inline uint32_t score(uint32_t p) {
    uint32_t occ = 0;
    for (ll po = 1LL * p; po <= n; po *= p) {
        occ += static_cast<uint32_t>(n / po);
    }

    // printf("score(%u) = %u\n", p, f(p) * occ);
    return f(p) * occ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %u %u %u %u %u", &n, &a, &b, &c, &d);
    primes.push_back(2);
    for (uint32_t i = 3; i < SQRT; i += 2) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (uint32_t j = i * i; j < SQRT; j += 2 * i) {
                sieve[j] = 1;
            }
        }
    }

    uint32_t ans = 0;
    for (uint32_t p : primes) {
        if (p > n) break;
        ans += score(p);
    }

    for (uint32_t start = SQRT; start <= n; start += SQRT) {
        uint32_t end = start + SQRT;

        sieve.reset();
        for (uint32_t p : primes) {
            // find smallest multiple of p >= start
            uint32_t x = start / p;
            if (p * x < start)
                ++x;

            ll v = 1LL * x * p;
            for (; v < end; v += p) {
                sieve[v - start] = 1;
            }
        }

        for (uint32_t x = start; x < end; ++x) {
            if (!sieve[x - start]) {
                ans += score(x);
            }
        }
    }

    printf("%u\n", ans);

    return 0;
}
