#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

inline ll myceil(ll x, ll y) {
    ll d = x / y;
    if (d * y < x)
        return d + 1;
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        ll m, k, x;
        cin >> m >> k >> x;

        ll lo = -1e18;
        ll hi = 1e18;

        while (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            ll pow = myceil(2LL * mid + m, k);
            if (pow <= x) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        lo = max(0LL, lo);
        if (lo > 1e9) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
            cout << lo << '\n';
    }
    
    return 0;
}
