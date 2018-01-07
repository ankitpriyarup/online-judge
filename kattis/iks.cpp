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

constexpr int MAXN = 102;
constexpr int MAXV = 1e6 + 6;

int n;
int a[MAXN];
int b[MAXN];

int sieve[MAXV];

vector<int> primes;
void gen_sieve() {
    for (int i = 2; i < MAXV; ++i) {
        if (sieve[i] == 0) {
            primes.push_back(i);
            sieve[i] = i;
        }

        for (int j = 0; j < primes.size() and primes[j] <= sieve[i] and i * primes[j] < MAXV; ++j) {
            sieve[i * primes[j]] = primes[j];
        }
    }
}

pair<int, int> run(int p) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        b[i] = 0;
        int x = a[i];
        while (x % p == 0) {
            ++b[i];
            x /= p;
        }

        total += b[i];
    }

    int ret = total / n;

    // printf("Prime %d has score %d\n", p, ret);
    int moves = 0;

    for (int i = 0; i < n; ++i) {
        moves += max(0, ret - b[i]);
    }

    return {ret, moves};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    gen_sieve();

    int ans = 1;
    int total = 0;
    int exp, moves;
    for (int p : primes) {
        tie(exp, moves) = run(p);
        for (int i = 0; i < exp; ++i)
            ans *= p;

        total += moves;
    }

    printf("%d %d\n", ans, total);

    return 0;
}
