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

constexpr int MAXN = 100005;
int n, m;

bool sieve[MAXN];
vector<int> primes;

void gen_sieve() {
    primes.push_back(2);
    for (int i = 3; i < MAXN; i += 2) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < MAXN; j += 2LL * i) {
                sieve[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_sieve();

    scanf("%d %d", &n, &m);
    // find smallest prime > n - 2
    int p = *upper_bound(begin(primes), end(primes), n - 2);
    int last_weight = p - (n - 2);

    vector<tuple<int, int, int> > edges;

    printf("%d %d\n", p, p);
    for (int k = 1; k <= n - 2; ++k) {
        edges.push_back(make_tuple(k, k + 1, 1));
    }
    edges.push_back(make_tuple(n - 1, n, last_weight));

    int cap = 999999999;
    for (int i = 1; i <= n; ++i) {
        if (edges.size() == m) break;

        for (int j = i + 2; j <= n; ++j) {
            if (edges.size() == m) break;

            edges.push_back(make_tuple(i, j, cap));
        }
    }
    
    assert(edges.size() == m);
    for (auto& e : edges) {
        printf("%d %d %d\n", get<0>(e), get<1>(e), get<2>(e));
    }

    return 0;
}
