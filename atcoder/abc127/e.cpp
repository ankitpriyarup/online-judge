#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
constexpr int MOD = 1e9 + 7;
int fact[MAXN], tcaf[MAXN];

inline int sum(int a, int b) {
    int c = (a + b);
    if (c >= MOD)
        c -= MOD;
    return c;
}

inline int prod(int a, int b) {
    return 1LL * a * b % MOD;
}

int modpow(int b, int e) {
    if (e == 0) return 1;
    if (e & 1) return prod(b, modpow(b, e ^ 1));
    else return modpow(prod(b, b), e >> 1);
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

void gen_fact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = prod(i, fact[i - 1]);
    }
    tcaf[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
    }
}

int choose(int n, int k) {
    return prod(fact[n], prod(tcaf[k], tcaf[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    gen_fact();

    // fix (x, y). What is the sum of distances to all other cells?
    // 01
    // 12 
    //
    // avg dist = 4/3
    //
    // dist = Ex + Ey
    // n^2 * sum i * (m - i)
    //
    // (n * m choose k) * (k choose 2) * e

    int ex = prod(prod(prod(n, n), choose(m + 1, 3)), inv(choose(n * m, 2)));
    int ey = prod(prod(prod(m, m), choose(n + 1, 3)), inv(choose(n * m, 2)));
    int e = sum(ex, ey);

    int ans = prod(prod(choose(n * m, k), choose(k, 2)), e);

    cout << ans << '\n';

    return 0;
}
