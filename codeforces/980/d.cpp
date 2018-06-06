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

constexpr int MAXN = 5003;
constexpr int SQRTV = 10004;
int n;
int a[MAXN], b[MAXN];
bool used[MAXN];
vector<int> primes;
bool sieve[SQRTV];
int ans[MAXN];

void gen_sieve() {
    primes.push_back(2);
    for (int d = 3; d < SQRTV; d += 2) {
        if (!sieve[d]) {
            primes.push_back(d);
            for (int j = d; j < SQRTV; j += 2 * d) {
                sieve[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_sieve();

    scanf(" %d", &n);
    vector<int> vals;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);

        // make squarefree
        if (a[i] == 0) continue;
        for (int p : primes) {
            int p2 = p * p;
            while (a[i] % p2 == 0) {
                a[i] /= p2;
            }
        }
        vals.push_back(a[i]);
    }

    // coordinate compress
    sort(begin(vals), end(vals));
    vals.erase(unique(begin(vals), end(vals)), end(vals));

    for (int i = 0; i < n; ++i) {
        b[i] = lower_bound(begin(vals), end(vals), a[i]) - begin(vals);
    }

    for (int i = 0; i < n; ++i) {
        memset(used, 0, sizeof(used));
        int cur = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] != 0) {
                if (!used[b[j]]) {
                    ++cur;
                }
                used[b[j]] = true;
            }

            ++ans[max(1, cur)];
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }

    return 0;
}
