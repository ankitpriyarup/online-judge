#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 4003;

int sum(int a, int b, int mod=MOD) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

inline int prod(int a, int b, int mod=MOD) {
    return (1LL * a * b) % mod;
}

int modpow(int base, int exp, int mod=MOD) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur, mod);
        }

        cur = prod(cur, cur, mod);
    }

    return res;
}

inline int inv(int x, int mod=MOD) {
    return modpow(x, mod - 2, mod);
}

int fact[MAXN], tcaf[MAXN];

void gen_fact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = prod(fact[i - 1], i);
    }

    tcaf[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
    }
}

int choose(int n, int k) {
    if (k < 0 or k > n or n < 0) {
        return 0;
    }

    return prod(fact[n], prod(tcaf[k], tcaf[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; ++i) {
        // break up k balls into i non-empty groups
        // (k - 1) choose (i - 1)
        int splits = choose(k - 1, i - 1);

        // red + 1 places to put them
        int spots = choose(n - k + 1, i);

        cout << prod(splits, spots) << '\n';
    }
    
    return 0;
}
