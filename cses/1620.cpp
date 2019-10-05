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
    ll t;
    cin >> n >> t;

    vector<ll> k(n);
    for (auto& x : k)
        cin >> x;

    ll lo = 0;
    ll hi = 1e18 + 1;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        ll built = 0;
        for (auto& x : k) {
            built += mid / x;
            if (built >= t) break;
        }

        if (built >= t) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << '\n';

    return 0;
}
