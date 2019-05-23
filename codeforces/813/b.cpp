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

    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<ll> xs = {1};
    while (xs.back() <= (r + x - 1) / x) {
        xs.push_back(xs.back() * x);
    }
    vector<ll> ys = {1};
    while (ys.back() <= (r + y - 1) / y) {
        ys.push_back(ys.back() * y);
    }

    vector<ll> unlucky;
    for (ll a : xs) {
        for (ll b : ys) {
            if (l <= a + b and a + b <= r) {
                unlucky.push_back(a + b);
            }
        }
    }

    sort(all(unlucky));
    if (unlucky.empty()) {
        cout << (r - l + 1) << '\n';
        return 0;
    }

    ll ans = max(unlucky[0] - l, r - unlucky.back());
    for (int i = 1; i < unlucky.size(); ++i) {
        ans = max(ans, unlucky[i] - unlucky[i - 1] - 1);
    }

    cout << ans << '\n';
    
    return 0;
}
