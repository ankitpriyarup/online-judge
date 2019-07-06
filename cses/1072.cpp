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

    ll k;
    cin >> k;
    for (ll n = 1; n <= k; ++n) {
        ll ans = (n - 1) * (n + 4) * (n * n - 3 * n + 4) / 2;
        cout << ans << '\n';
    }

    return 0;
}
