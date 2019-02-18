#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;

    return c;
}

int prod(int a, int b) {
    return (1LL * a * b) % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (exp & p) {
            res = prod(res, cur);
        }

        cur = prod(cur, cur);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, r, c, k;
    cin >> n >> r >> c >> k;
    // Say we fix an r' x c' with top left corner at x, y
    // Ways to choose left: (x + 1)^n - x^n
    // Ways to choose right: (r - x - r' + 1)^n - (r - x - r')^n
    // do all row products
    // do all col products
    // sum!!!
    int m = max(r, c);
    vi d(m + 1);
    {
        int x = 0;
        for (int i = 0; i <= m; ++i) {
            int y = modpow(i + 1, n);
            d[i] = sum(y, MOD - x);
            x = y;
        }
    }

    /*
    cout << "d: ";
    for (int i = 0; i <= m; ++i) {
        cout << d[i] << " ";
    }
    cout << '\n';
    */

    vi rows(r + 1, 0), cols(c + 1, 0);
    for (int rr = 1; rr <= r; ++rr) {
        for (int x = 0; x + rr <= r; ++x) {
            // left: d[x]
            // right: d[r - x - rr]
            rows[rr] = sum(rows[rr], prod(d[x], d[r - x - rr]));
        }
    }

    for (int cc = 1; cc <= c; ++cc) {
        for (int y = 0; y + cc <= c; ++y) {
            cols[cc] = sum(cols[cc], prod(d[y], d[c - y - cc]));
        }
    }

    int ans = 0;
    for (int rr = 1; rr <= r; ++rr) {
        for (int cc = 1; cc <= c; ++cc) {
            if (rr * cc >= k)
                ans = sum(ans, prod(rows[rr], cols[cc]));
        }
    }

    cout << ans << '\n';
    
    return 0;
}
