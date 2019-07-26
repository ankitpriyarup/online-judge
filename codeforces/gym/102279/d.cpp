#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

ll g(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll x0, y0, r;
    int n;
    cin >> x0 >> y0 >> r >> n;

    ll r2 = r * r;
    int ans = 0;
    set<pair<ll, ll>> s;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        ll dx = x - x0;
        ll dy = y - y0;
        ll d = dx * dx + dy * dy;

        ll g = gcd(dx, dy);
        dx /= g;
        dy /= g;

        if (d <= r2 and !s.count({dx, dy})) {
            s.emplace(dx, dy);
            ++ans;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
