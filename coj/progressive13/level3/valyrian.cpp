#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int NMOD = 3;
constexpr int MODS[] = {1000000007, 1000000009, 1000000021};
constexpr int MAXN = 505;
int fact[NMOD][MAXN], tcaf[NMOD][MAXN];

inline int sum(int a, int b, int m) {
    int c = (a + b);
    if (c >= m) c -= m;
    return c;
}

inline int prod(int a, int b, int m) {
    return 1LL * a * b % m;
}

int modpow(int b, int e, int m) {
    if (!e) return 1;
    if (e & 1) return prod(b, modpow(b, e ^ 1, m), m);
    return modpow(prod(b, b, m), e >> 1, m);
}

inline int inv(int x, int m) {
    return modpow(x, m - 2, m);
}

void gen_fact() {
    for (int k = 0; k < 3; ++k) {
        fact[k][0] = tcaf[k][0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            fact[k][i] = prod(fact[k][i - 1], i, MODS[k]);
        }

        tcaf[k][MAXN - 1] = inv(fact[k][MAXN - 1], MODS[k]);
        for (int i = MAXN - 2; i >= 0; --i) {
            tcaf[k][i] = prod(tcaf[k][i + 1], i + 1, MODS[k]);
        }
    }
}

int choose(int a, int b, int k) {
    if (b < 0 or b > a) return 0;
    return prod(fact[k][a], prod(tcaf[k][b], tcaf[k][a - b], MODS[k]), MODS[k]);
}

vector<int> count(int c, int v, int l) {
    vi res(NMOD, 0);
    for (int k = 0; k < NMOD; ++k) {
        // use i consonants
        for (int i = 0; 2 * i <= l; ++i) {
            // number of words is: c^i v^(l - i) C(l - i, i)
            int cur = prod(modpow(c, i, MODS[k]), modpow(v, l - i, MODS[k]), MODS[k]);
            cur = prod(cur, choose(l - i, i, k), MODS[k]);
            res[k] = sum(res[k], cur, MODS[k]);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();

    int T;
    cin >> T;
    while (T-- > 0) {
        int c, v, l, k;
        cin >> c >> v >> l >> k;

        vi cur = count(c, v, l);
        bool overflow = false;
        for (int i = 0; i < NMOD; ++i) {
            for (int j = i + 1; j < NMOD; ++j) {
                overflow |= cur[i] != cur[j];
            }

            overflow |= cur[i] >= k;
        }

        cout << cur[0] << ' ' << (overflow ? "Accepted" : "Rejected") << '\n';
    }
    
    return 0;
}
