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

constexpr int MAXK = 1003;
constexpr int MOD = 1000000007;

char n[MAXK];
int nlen;
int k;
int dp[MAXK];
int fact[MAXK];
int tcaf[MAXK];

inline int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;

    return c;
}

int modpow(int base, int exp) {
    int cur = base;
    int res = 1;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp)
            res = 1LL * res * cur % MOD;
        cur = 1LL * cur * cur % MOD;
    }

    return res;
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

int choose(int n, int k) {
    if (k < 0 or k > n)
        return 0;

    return 1LL * fact[n] * tcaf[k] % MOD * tcaf[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", n);
    scanf("%d", &k);

    fact[0] = tcaf[0] = 1;
    for (int i = 1; i < MAXK; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        tcaf[i] = inv(fact[i]);
    }

    nlen = strlen(n);

    if (k == 0) {
        printf("%d\n", 1);
        return 0;
    } else if (k == 1) {
        printf("%d\n", nlen - 1);
        return 0;
    }

    --k;
    int ans = 0;

    nlen = strlen(n);

    dp[1] = 0;
    for (int i = 2; i < MAXK; ++i) {
        dp[i] = 1 + dp[__builtin_popcount(i)];
    }

    int taken = 0;
    for (int i = 0; i < nlen; ++i) {
        if (n[i] == '1') {
            for (int j = 0; j < MAXK; ++j) {
                if (dp[j] == k) {
                    ans = sum(ans, choose(nlen - i - 1, j - taken));
                }
            }

            ++taken;
        }
    }

    if (dp[taken] == k) {
        ans = sum(ans, 1);
    }

    printf("%d\n", ans);

    return 0;
}
