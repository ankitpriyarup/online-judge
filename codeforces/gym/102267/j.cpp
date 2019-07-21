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

constexpr int MAXN = 1e5 + 5;

// dp i j = number of paths of length i with sum j
int dp[2][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    int ans = 0;
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        int v = i & 1;
        memset(dp[v ^ 1], 0, sizeof(dp[v ^ 1]));
        for (int j = 0; j <= k; ++j) {
            if (j) {
                dp[v ^ 1][j - 1] = sum(dp[v ^ 1][j - 1], dp[v][j]);
            }
            if (j + 1 <= k) {
                dp[v ^ 1][j + 1] = sum(dp[v ^ 1][j + 1], dp[v][j]);
            }
        }

        ans = sum(ans, dp[v ^ 1][0]);
    }

    cout << prod(2 * n, ans) << '\n';

    return 0;
}
