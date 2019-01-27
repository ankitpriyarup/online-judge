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
    cin >> n;
    deque<ll> a;
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        tot += x;
        a.push_back(x);
        while (a.size() >= 3) {
            int m = a.size();
            if (a[m - 2] < max(a[m - 1], a[m - 3]))
                break;

            ll v = a[m - 1] - a[m - 2] + a[m - 3];
            for (int j = 0; j < 3; ++j)
                a.pop_back();
            a.push_back(v);
        }
    }

    ll d = 0;
    ll sgn = 1;
    while (!a.empty()) {
        if (a.front() >= a.back()) {
            d += sgn * a.front();
            a.pop_front();
        } else {
            d += sgn * a.back();
            a.pop_back();
        }

        sgn = -sgn;
    }

    ll ans = (tot + d) / 2LL;
    cout << ans << '\n';

    return 0;
}
