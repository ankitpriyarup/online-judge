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

ll l, r;
int dp[62][2][2][2];
int solve(int k, bool xl, bool yr, bool x0) {
    if (k < 0) {
        return 1;
    }

    int& res = dp[k][xl][yr][x0];
    if (res != -1)
        return res;

    int lb = (l >> k) & 1;
    int rb = (r >> k) & 1;

    res = 0;
    // 00, 01, 11
    for (int a = 0; a <= 1; ++a) {
        for (int b = a; b <= 1; ++b) {
            bool a_valid = xl or lb <= a;
            bool b_valid = yr or rb >= b;

            // cout << k << ' ' << a << ' ' << b << ' ' << xl << ' ' << yr << ' ' << lb << ' ' << rb << '\n';

            if (a_valid and b_valid and (x0 or a == b)) {
                res = sum(res, solve(k - 1, xl or lb < a, yr or rb > b, x0 or a));
            }
        }
    }

    // cout << "dp[" << k << "][" << xl << "][" << yr << "] = " << res << '\n';
    return res;
}

int brute() {
    int ans = 0;
    for (ll x = l; x <= r; ++x) {
        for (ll y = x; y <= r; ++y) {
            if ((y ^ x) == (y % x)) {
                // cout << x << ' ' << y << '\n';
                ans++;
                assert((y & x) == x);
                assert(2 * x > y and (y & x) == x);
            }

            if (2 * x > y and ((y & x) == x)) {
                assert((y & x) == x);
                // --ans;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> l >> r;
    // seems to happen if bits in x are a subset of the bits in y
    // and y is no more than double x
    // state is:
    // index of bit we're filling
    // whether x is > L yet
    // whether y is < R yet
    //
    // 1100100
    // 0001010
    //
    // alternately: pretty easy to compute for under a power of 2
    // 1 1 = 1
    // 1 3 = 5
    // 1 7 = 19
    // for b bits, this is 3^n - 2^n
    
    memset(dp, -1, sizeof(dp));
    int ans = solve(61, false, false, false);

    cout << ans << '\n';
    // cout << brute() << '\n';
    
    return 0;
}
