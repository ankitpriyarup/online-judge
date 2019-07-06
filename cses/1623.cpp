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
    vi a(n);

    ll tot = 0;
    for (auto& x : a) {
        cin >> x;
        tot += x;
    }

    ll ans = tot;
    for (int mask = 1; mask < (1 << n); ++mask) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += a[i];
            }
        }

        ans = min(ans, abs(sum - (tot - sum)));
    }

    cout << ans << '\n';

    return 0;
}
