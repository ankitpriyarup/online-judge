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

constexpr int MAXN = 1000006;
int sieve[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);

    vector<int> primes;
    for (int i = 3; i < MAXN; i += 2) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < MAXN; j += 2LL * i) {
                sieve[j] = 1;
            }
        }
    }

    int steps = 0;
    while (n > 4) {
        for (int p : primes) {
            if (!sieve[n - p]) {
                // printf("%d = %d + %d\n", n, p, n - p);
                ++steps;
                n -= 2 * p;
                break;
            }
        }
    }

    if (n == 4)
        ++steps;

    printf("%d\n", steps);

    return 0;
}
