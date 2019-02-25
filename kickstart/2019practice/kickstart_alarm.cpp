#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int modpow(int b, int e) {
    if (!e) return 1;
    if (e & 1) return 1LL * b * modpow(b, e ^ 1) % MOD;
    return modpow(1LL * b * b % MOD, e >> 1);
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n, k, c, d, e1, e2, f;
        cin >> n >> k;

        vi xs(n), ys(n);
        cin >> xs[0] >> ys[0] >> c >> d >> e1 >> e2 >> f;

        vi a(n);
        a[0] = (xs[0] + ys[0]) % f;

        for (int i = 1; i < n; ++i) {
            xs[i] = 1LL * c * xs[i - 1] % f + 1LL * d * ys[i - 1] % f + e1;
            xs[i] %= f;

            ys[i] = 1LL * d * xs[i - 1] % f + 1LL * c * ys[i - 1] % f + e2;
            ys[i] %= f;

            a[i] = (xs[i] + ys[i]) % f;
        }
        // sum_{i = 0}^n x^i = \frac{1}{x - 1} (x^(i + 1) - 1)
        int ans = 0;
        int powsum = k;
        for (int i = 0; i < n; ++i) {
            // how many subarrays are you first, second third, etc
            // j <= i
            // max(0, n - i) for first
            // max(0, n - i - 1) for second
            // max(0, n - i - j) spots where you're j-th
            //
            // for example, 3 is first twice, and second 0 times 3 * 2 * (1 + 1^2 + 1^3)
            // 2 is first once and second once 2 * 1 * (1 + 1^2 + 1^3) + 2 * 1 * (2 + 2^2 + 2^3)
            //
            // say array is of length 5. Then matrix is
            // 5 0 0 0 0
            // 4 4 0 0 0
            // 3 3 3 0 0
            // 2 2 2 2 0
            // 1 1 1 1 1
            // :o
            // so sum is a[0] * (n - 0) * (1 + 1^2 + ... + 1^k)
            //         + a[1] * (n - 1) * (1 + 1^2 + ... + 1^k + 2 + 2^2 + ... + 2^k)
            int term = 1LL * a[i] * (n - i) % MOD;
            term = 1LL * term * powsum % MOD;

            int powterm = modpow(i + 2, k + 1) + MOD - 1;
            if (powterm >= MOD)
                powterm -= MOD;

            powterm = 1LL * powterm * inv(i + 1) % MOD;
            powsum += powterm;
            if (powsum >= MOD)
                powsum -= MOD;
            --powsum;
            if (powsum < 0)
                powsum += MOD;

            ans += term;
            if (ans >= MOD)
                ans -= MOD;
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}
