#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 2e5 + 5;
constexpr int MOD = 1e9 + 7;

int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

int prod(int a, int b) {
    return 1LL * a * b % MOD;
}

int modpow(int b, int e) {
    if (!e) return 1;
    if (e & 1) return prod(b, modpow(b, e ^ 1));
    return modpow(prod(b, b), e >> 1);
}

int inv(int x) {
    return modpow(x, MOD - 2);
}

int fact[MAXN], tcaf[MAXN];

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
    assert(0 <= k and k <= n);
    return prod(fact[n], prod(tcaf[k], tcaf[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();

    int n;
    cin >> n;

    int res = choose(2 * n, n);
    res = prod(res, inv(n + 1));

    cout << res << '\n';

    return 0;
}
