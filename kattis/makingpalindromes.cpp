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

constexpr int MAXN = 404;
constexpr int MOD = 1e9 + 7;
int n;
char s[MAXN];

int dp[MAXN][MAXN][MAXN];

int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

int prod(int a, int b) {
    return 1LL * a * b % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (exp & p) {
            res = prod(res, cur);
        }
        cur = prod(cur, cur);
    }
    return res;
}

int solve(int len, int pref, int suff) {
    if (pref > suff) {
        // cout << "pref > suff ret " << modpow(26, n - len) << '\n';
        return modpow(26, n - len);
    }
    if (len == n) {
        // cout << "pref > suff ret " << 0 << '\n';
        return 0;
    }

    int& res = dp[len][pref][suff];
    if (res != -1) 
        return res;

    res = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        int np = c == s[pref] ? pref + 1 : pref;
        int ns = c == s[suff] ? suff - 1 : suff;
        // cout << "Trying " << c << " for spot " << len << '\n';
        res = sum(res, solve(len + 1, np, ns));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    scanf(" %s", s);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, 0, n - 1));
    
    return 0;
}
