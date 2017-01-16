#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int SQRTN = 50000;

vector<int> primes;
vector<pair<int, int> > factors;

int sieve[SQRTN];

void gen_sieve() {
    memset(sieve, -1, sizeof(sieve));

    primes.push_back(2);
    for (int i = 2; i < SQRTN; i += 2) {
        sieve[i] = 2;
    }

    for (int i = 3; i < SQRTN; i += 2) {
        if (sieve[i] == -1) {
            sieve[i] = i;
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < SQRTN; j += 2LL * i) {
                sieve[j] = i;
            }
        }
    }
}

void factorize(long long m) {
    factors.clear();
    for (int i : primes) {
        if (i > m) {
            break;
        }

        int count = 0;
        while (m % i == 0) {
            m /= i;
            ++count;
        }

        if (count > 0) {
            factors.push_back(make_pair(i, count));
        }
    }

    if (m > 1) {
        factors.push_back(make_pair(m, 1));
    }
}

int count_factor(int p, int n) {
    long long power = p;
    int count = 0;

    while (power <= n) {
        count += n / power;

        power *= p;
    }

    return count;
}

bool divides_factorial(int n, int m) {
    if (m == 0) {
        return false;
    }

    if (m == 1 or n >= m) {
        return true;
    }

    factorize(m);

    for (pair<int, int> factor_pair : factors) {
        if (count_factor(factor_pair.first, n) < factor_pair.second) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    gen_sieve();

    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        const char* out_str = divides_factorial(n, m) ? "divides" : "does not divide";
        printf("%d %s %d!\n", m, out_str, n);
    }

    return 0;
}
