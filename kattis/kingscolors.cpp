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

constexpr int MAXN = 2505;
constexpr int MOD = 1000000007;
int dp[MAXN][MAXN];
int fact[MAXN], tcaf[MAXN];
vector<int> tree[MAXN];

int sum(const int& a, const int& b) {
    int c = (a + b);
    if (c >= MOD)
        c -= MOD;
    return c;
}

int prod(const int& a, const int& b) {
    return 1LL * a * b % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (exp & p)
            res = prod(res, cur);
        cur = prod(cur, cur);
    }

    return res;
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

void gen_fact() {
    fact[0] = tcaf[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = prod(fact[i - 1], i);
    }
    tcaf[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
        assert(tcaf[i] == inv(fact[i]));
    }
}

int choose(int n, int k) {
    return prod(fact[n], prod(tcaf[k], tcaf[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();

    int n, k;
    cin >> n >> k;
    int par;
    for (int i = 1; i < n; ++i) {
        cin >> par;
        tree[par].push_back(i);
    }

    for (int u = n - 1; u > 0; --u) {
        for (int j = 2; j <= k; ++j) {
            dp[u][j] = j - 1;
            for (int v : tree[u]) {
                dp[u][j] = prod(dp[u][j], dp[v][j]);
            }
        }
    }

    int ans = 0;
    int sign = 1;
    for (int j = k; j >= 2; --j) {
        int cur = j;
        for (int v : tree[0]) {
            cur = prod(cur, dp[v][j]);
        }

        ans = sum(ans, prod(choose(k, j), prod(sign, cur)));
        sign = MOD - sign;
    }

    printf("%d\n", ans);

    return 0;
}
