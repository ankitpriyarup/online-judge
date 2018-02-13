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
constexpr int MAXV = 100005;

int sieve[MAXV];
int carol_num[MAXV];

void gen_sieve() {
    memset(sieve, -1, sizeof(sieve));
    memset(carol_num, 0, sizeof(carol_num));

    for (int i = 2; i < MAXV; ++i) {
        if (sieve[i] == -1) {
            sieve[i] = i;

            for (int j = i; j < MAXV; j += i) {
                sieve[j] = i;
            }

            for (ll pp = i; pp < MAXV; pp *= 1LL * i) {
                for (int j = pp; j < MAXV; j += pp) {
                    ++carol_num[j];
                }
            }
        }
    }
}

int n, k;
int a[MAXN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_sieve();

    scanf("%d %d", &n, &k);
    map<int, int> gcds;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);

        map<int, int> new_gcds;
        for (const auto& it : gcds) {
            new_gcds[gcd(a[i], it.first)] += it.second;
        }
        ++new_gcds[a[i]];

        gcds = new_gcds;

        for (auto& it : gcds) {
            if (carol_num[it.first] == k) {
                ans += it.second;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
