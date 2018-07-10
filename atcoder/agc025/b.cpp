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

constexpr int MAXN = 300005;
constexpr int MOD = 998244353;

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
        if (exp & p)
            res = prod(res, cur);
        cur = prod(cur, cur);
    }
    return res;
}

int fact[MAXN], tcaf[MAXN];
void gen_fact() {
    fact[0] = tcaf[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = prod(fact[i - 1], i);
    }
    tcaf[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
    }
}

int choose(int n, int k) {
    if (k < 0 or k > n)
        return 0;
    return prod(fact[n], prod(tcaf[k], tcaf[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();

    // ax + by = k
    // x <= n
    // y <= n
    int n, a, b;
    ll k;
    scanf(" %d %d %d %lld", &n, &a, &b, &k);
    int ans = 0;
    for (int x = 0; x <= n; ++x) {
        ll rem = k - 1LL * x * a;
        if (rem % b == 0) {
            ll y = rem / b;
            if (0 <= y and y <= n)
                ans = sum(ans, prod(choose(n, x), choose(n, y)));
        }
    }

    printf("%d\n", ans);

    return 0;
}
