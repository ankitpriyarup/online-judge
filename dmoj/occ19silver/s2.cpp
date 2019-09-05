#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<ll> opts;
    for (int len = 1; len <= 18; ++len) {
        for (int m = 0; m < (1 << len); ++m) {
            int v = m;
            ll res = 0;
            for (int k = 0; k < len; ++k) {
                res *= 10;
                res += 2 + (v & 1);
                v >>= 1;
            }

            opts.push_back(res);
        }
    }

    ll n;
    cin >> n;

    int ans = 0;
    for (ll x : opts) {
        if (x <= n)
            ++ans;
    }

    cout << ans << '\n';
    
    return 0;
}
