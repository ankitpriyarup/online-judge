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

constexpr int MOD = 998244353;

inline int sum(const int& a, const int& b) {
    return (a + b) % MOD;
}

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

inline int modpow(const int& base, const int& exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur);
        }
        cur = prod(cur, cur);
    }

    return res;
}

int fact[20003];
int tcaf[20003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    // k + 1 sections
    // first section has m options
    // rest have m - 1
    int colors = m;
    for (int i = 0; i < k; ++i) {
        colors = prod(colors, m - 1);
    }

    fact[0] = tcaf[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = prod(i, fact[i - 1]);
        tcaf[i] = modpow(fact[i], MOD - 2);
    }

    // n - 1 choose k ways to partition
    int ways;
    if (k <= n - 1)
        ways = prod(fact[n - 1], prod(tcaf[k], tcaf[n - 1 - k]));
    else
        ways = 0;

    int ans = prod(colors, ways);

    cout << ans << '\n';

    return 0;
}
