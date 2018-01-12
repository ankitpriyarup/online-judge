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

constexpr int MAXN = 303;
constexpr int MOD = 1e9 + 7;
int n;
int vals[MAXN];
bool adj[MAXN][MAXN];

int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;

    return c;
}

int prod(int a, int b) {
    return (1LL * a * b) % MOD;
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

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline int inc(int x) {
    return x == n - 1 ? 0 : x + 1;
}

int dp[MAXN][MAXN][2];

// if flag, then we can connect to u. Otherwise, we cannot connect directly to u
int solve(int u, int v, bool flag) {
    if (u == v)
        return 0;

    if (inc(u) == v) {
        return 1;
    }

    if (dp[u][v][flag] != -1) {
        return dp[u][v][flag];
    }

    int ret = 0;
    for (int k = inc(u); k != v; k = inc(k)) {
        if (adj[u][k] and flag) {
            ret = sum(ret, prod(solve(u, k, flag), solve(k, v, flag)));
        }

        if (adj[k][v]) {
            ret = sum(ret, prod(solve(u, k, 0), solve(k, v, 1)));
        }
    }

    return dp[u][v][flag] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vals[i]);
    }

    for (int i = 0; i < n; ++i) {
        adj[i][i] = false;
        for (int j = i + 1; j < n; ++j) {
            adj[i][j] = adj[j][i] = gcd(vals[i], vals[j]) > 1;
        }
    }

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!adj[i][j]) continue;

            ans = sum(ans, prod(solve(i, j, 1), solve(j, i, 1)));
        }
    }

    ans = prod(ans, inv(n - 1));
    printf("%d\n", ans);

    return 0;
}
