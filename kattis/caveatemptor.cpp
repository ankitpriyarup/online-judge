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

int solve(const string& s) {
    int n = s.size();
    int ans = 0;
    for (int len = 2; len < n; len += 2) {
        int half = len >> 1;
        // 9 digits, 2 special, 7 nonspecial
        // two options:
        // start with a 6 or 8, 
        int first = prod(2, prod(prod(modpow(2, half - 1), modpow(7, half)), choose(len - 1, half)));

        // start with something else
        // only 6 starts because no 0
        int second = prod(6, prod(prod(modpow(2, half), modpow(7, half - 1)), choose(len - 1, half)));
        ans = sum(ans, sum(first, second));
    }

    if (n % 2 == 1) {
        return ans;
    }

    int half = n >> 1;
    int lucky = 0;
    for (int i = 0; i < n; ++i) {
        int start = i == 0 ? 1 : 0;
        for (int d = start; d < s[i] - '0'; ++d) {
            if (d == 4) 
                continue;

            int curLucky = lucky + (d == 6 or d == 8);
            int curUnlucky = i + 1 - curLucky;

            if (curLucky <= half and curUnlucky <= half) {
                int luckyOpts = modpow(2, half - curLucky);
                int unluckyOpts = modpow(7, half - curUnlucky);
                int ways = prod(prod(luckyOpts, unluckyOpts), choose(n - i - 1, half - curLucky));
                ans = sum(ans, ways);
            }
        }

        if (s[i] == '4') {
            break;
        }
        if (s[i] == '6' or s[i] == '8') {
            ++lucky;
        }
        if (lucky > half) {
            break;
        }
    }

    return ans;
}

int valid(const string& s) {
    int n = s.size();
    if (n % 2 == 1) return false;
    int lucky = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '4') {
            return false;
        }
        if (s[i] == '6' or s[i] == '8')
            ++lucky;
    }

    return 2 * lucky == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();

    string l, r;
    cin >> l >> r;

    int ans = solve(r);
    ans = sum(ans, MOD - solve(l));
    if (valid(r))
        ans = sum(ans, 1);

    cout << ans << '\n';

    return 0;
}
