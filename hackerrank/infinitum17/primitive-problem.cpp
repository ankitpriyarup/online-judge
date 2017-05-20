#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int mod_pow(int base, int exponent, int mod) {
    long long result = 1;
    long long current = base;

    for (int two_power = 1; two_power <= exponent; two_power <<= 1) {
        if (exponent & two_power) {
            result *= current;
            result %= mod;
        }

        current *= current;
        current %= mod;
    }

    return (int) result;
}

bool is_root(int x, int prime, vector<int> powers) {
    for (int power : powers) {
        if (mod_pow(x, (prime - 1) / power, prime) == 1) {
            return false;
        }
    }

    return true;
}

int phi(int x, vector<int>& candidates) {
    // Computes the totient of x. Also pushes its prime divisors to candidates.
    int totient = 1;

    int two_exponent = 1;
    while (x % 2 == 0) {
        two_exponent <<= 1;
        x >>= 1;
    }

    if (two_exponent > 1) {
        totient *= (two_exponent >> 1);
        candidates.push_back(2);
    }

    for (int i = 3; 1LL * i * i <= 1LL * x; i += 2) {
        if (x % i == 0) {
            int power = 1;
            while (x % i == 0) {
                power *= i;
                x /= i;
            }

            totient *= (power / i) * (i - 1);
            candidates.push_back(i);
        }
    }

    if (x > 1) {
        totient *= (x - 1);
        candidates.push_back(x);
    }

    return totient;
}

int main() {
    int prime;
    cin >> prime;

    vector<int> powers;
    int num_roots = phi(prime - 1, powers);

    bool found_root = false;
    int root = -1;

    for (int i = 2; !found_root and i < prime; ++i) {
        if (is_root(i, prime, powers)) {
            root = i;
            found_root = true;
        }
    }

    cout << root << ' ' << num_roots << '\n';

    return 0;
}
