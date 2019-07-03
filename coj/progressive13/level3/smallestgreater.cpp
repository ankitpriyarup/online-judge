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

    ll m, k;
    ll INF = 1e18;
    while (cin >> m >> k) {
        ll mask = (1LL << k) - 1LL;
        ll ans = INF;
        if (mask >= m) ans = mask;

        ll rem = 0;
        for (; mask <= 2 * m; mask <<= 1) {
            ll t = (m | mask) & ~rem;
            // cout << m << ' ' << mask << ' ' << t << '\n';
            ans = min(ans, m | mask);
            if (t >= m)
                ans = min(ans, t);
            rem <<= 1LL;
            rem |= 1LL;
        }

        cout << ans << '\n';
    }
    
    return 0;
}
