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

constexpr int CAP = 1e6 + 6;
bool sieve[CAP];
vector<int> primes;

void gen_primes() {
    primes.push_back(2);
    for (int i = 3; i < CAP; i += 2) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < CAP; j += 2LL * i) {
                sieve[j] = true;
            }
        }
    }
}

int uf[CAP];

void reset(int n) {
    for (int i = 0; i <= n; ++i)
        uf[i] = i;
}

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

bool unite(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;

    if (rand() % 2)
        uf[xr] = yr;
    else
        uf[yr] = xr;

    return true;
}

ll a, b, p;
ll ans;

void update(ll prime) {
    // find the smallest multiple >= a
    ll delta = (prime - (a % prime)) % prime;
    for (ll val = a + delta; val <= b; val += prime) {
        int ind = val - a;
        if (ind - prime >= 0) {
            bool diff = unite(ind, ind - prime);
            ans -= diff;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int tc = 1;

    gen_primes();
    while (T-- > 0) {
        scanf("%lld %lld %lld", &a, &b, &p);

        reset(b - a + 1);
        ans = b - a + 1;
        for (int prime : primes) {
            if (prime < p) continue;
            if (prime >= b) break;

            update(prime);
        }

        printf("Case #%d: %lld\n", tc++, ans);
    }

    return 0;
}
