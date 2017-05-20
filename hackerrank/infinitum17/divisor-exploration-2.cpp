#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

constexpr int MOD = 1000000007;

inline int sum(int a, int b) {
    return (a + b) % MOD;
}

inline int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

inline int prod(int a, int b) {
    return (1LL * a * b) % MOD;
}

inline int mod_pow(int base, int exponent) {
    int result = 1;
    int cur_pow = base;
    for (int p = 1; p <= exponent; p <<= 1) {
        if (exponent & p) {
            result = prod(result, cur_pow);
        }

        cur_pow = prod(cur_pow, cur_pow);
    }

    return result;
}

// Return x^-1 (mod MOD)
int inv(int x) {
    return mod_pow(x, MOD - 2);
}

vector<int> primes;

// bool segment[50000];

void gen_primes() {
    primes.clear();
    // Push back 1 because we never access primes[0]
    primes.push_back(1);
    primes.push_back(2);

    long long candidate = 3;
    while (primes.size() <= 100005) {
        bool is_prime = true;
        for (int i = 1; i < primes.size() and 1LL * primes[i] * primes[i] <= 1LL * candidate; ++i) {
            if (candidate % primes[i] == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes.push_back(candidate);
        }

        candidate += 2;
    }
}

// Computes the sum of sigma(d) for all d | p^e.
// a(p^e) = (p * (p^(e + 1) - 1) - (p - 1) * (e + 1)) / (p - 1)^2
// a(p^e) = (p^(e + 2) - pe - 2p + e + 1) / (p - 1)^2

// Prime < 2e6, exponent < 1e6
int compute(int prime, int exponent) {
    int result = mod_pow(prime, exponent + 2);
    result = sub(result, prod(prime, exponent));
    result = sub(result, prod(2, prime));
    result = sum(result, exponent);
    result = sum(result, 1);

    int denominator = prod(prime - 1, prime - 1);
    return prod(result, inv(denominator));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    gen_primes();

    int num_queries, num_divisors, exponent_add;
    scanf("%d", &num_queries);

    while (num_queries-- > 0) {
        scanf("%d %d", &num_divisors, &exponent_add);

        int value = 1;
        int ans = 1;
        for (int i = 1; i <= num_divisors; ++i) {
            int c = compute(primes[i], i + exponent_add);
            // printf("%d %d = %d\n", primes[i], i + exponent_add, c);
            ans = prod(ans, c);
            value = prod(value, mod_pow(primes[i], i + exponent_add));
        }

        // printf("%d\n", ans);
        printf("%d %d\n", value, ans);
    }
}
