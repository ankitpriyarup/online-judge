#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1000003;
int fact[MOD], tcaf[MOD];

inline int sum(const int& a, const int& b) {
    int c = a + b;
    if (c >= MOD) {
        c -= MOD;
    }

    return c;
}

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

int modpow(int base, int exp) {
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

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

void gen_fact() {
    fact[0] = tcaf[0] = 1;
    for (int i = 1; i < MOD; ++i) {
        fact[i] = prod(fact[i - 1], i);
    }
    tcaf[MOD - 1] = inv(fact[MOD - 1]);
    for (int i = MOD - 2; i >= 0; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();

    // 7 2 4
    // 7 9 11 13
    // 2 * (7/2) * 2 * (7/2 + 1) + 2 * (7 / 2 + 2) + ...
    // 2^n (7/2)*(7/2 + 1)*(7/2 + 2)*(7/2 + 3)
    // all under modulo...
    // d^n (x/d + n)! / (x/d - 1)!
    int q;
    cin >> q;
    while (q-- > 0) {
        int x, d, n;
        cin >> x >> d >> n;

        if (x == 0 or d == 0) {
            int ans = modpow(x, n);
            cout << ans << '\n';
            continue;
        }

        int a = modpow(d, n);
        int v = prod(x, inv(d));

        int ans = 0;
        if (0 < v and v + n - 1 < MOD) {
            int k = prod(fact[v + n - 1], tcaf[v - 1]);
            ans = prod(a, k);
        }

        cout << ans << '\n';
    }
    
    return 0;
}
