#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vi p(26);
    for (int i = 0; i < 26; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = prod(x, inv(y));
    }

    vi dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vi ndp(m + 1, 0);

        for (int j = 0; j < m; ++j) {
            if (dp[j] == 0) continue;

            // advance
            int cp = p[s[j] - 'a'];
            ndp[j + 1] += prod(dp[j], cp);
            ndp[j] += prod(dp[j], sum(1, MOD - cp));
        }

        ndp[m] = sum(ndp[m], dp[m]);
        swap(dp, ndp);
    }
    
    cout << dp[m] << '\n';
    return 0;
}
