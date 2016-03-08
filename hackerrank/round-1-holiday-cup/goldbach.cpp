#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

vector<int> primes;
bool not_prime[32001];

void gen_sieve() {
    memset(not_prime, 0, sizeof(not_prime));
    not_prime[0] = 1;
    not_prime[1] = 1;
    primes.push_back(2);

    for (int i = 3; i < 32001; i += 2) {
        if (!not_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < 32001; j += 2 * i) {
                not_prime[j] = 1;
            }
        }
    }
}

int main() {
    int N, x;
    cin >> N;
    gen_sieve();

    set<int> prime_set(primes.begin(), primes.end());
    while (N-- > 0) {
        cin >> x;
        vector<pair<int, int> > ans;
        for (auto it = primes.begin(); it != primes.end(); ++it) {
            if (*it > x - *it) break;
            if (prime_set.find(x - *it) != prime_set.end()) {
                ans.push_back(make_pair(*it, x - *it));
            }
        }

        cout << x << " has " << ans.size() << " representation(s)" << '\n';
        for (auto it = ans.begin(); it != ans.end(); ++it) {
            cout << it->first << '+' << it->second << '\n';
        }

        if (N > 1) cout << '\n';
    }
    return 0;
}
