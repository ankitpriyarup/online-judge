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

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll cur = 0LL;
    for (ll d = 60; d >= 0; --d) {
        ll b = (1LL << d);
        if ((cur ^ b) > k) continue;
        // count frequency of 0s and 1s 
        // if 0s > 1s, use the bit
        int zeros = 0;
        for (ll x : a) {
            if ((x & b) == 0) {
                ++zeros;
            }
        }

        int ones = n - zeros;
        if (zeros > ones) {
            cur ^= b;
        }
    }

    ll res = 0LL;
    for (ll x : a) {
        res += (x ^ cur);
    }

    cout << res << '\n';
    return 0;
}
