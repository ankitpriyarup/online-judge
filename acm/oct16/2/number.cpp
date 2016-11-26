#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#define MAXN 1000003

using namespace std;

long long inp;
bool sieve[1000005];
vector<int> primes;

void gen_sieve() {
    memset(sieve, 0, sizeof(sieve));
    primes.push_back(2);

    for (long long i = 3; i < MAXN; i += 2) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < MAXN; j += 2 * i) {
                sieve[j] = true;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    gen_sieve();

    while (T-- > 0) {
        cin >> inp;
        if (inp == 1) {
            cout << "Bob wins after move 0\n";
            continue;
        }

        int factors = 0;
        for (int p : primes) {
            while (inp % p == 0) {
                ++factors;
                inp /= p;
            }
        }

        if (inp != 1) {
            ++factors;
        }

        cout << (factors % 2 == 0 ? "Alice" : "Bob") << " wins after move " << (factors - 1) << '\n';
    }

    return 0;
}
