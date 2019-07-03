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

    int days;
    cin >> days;
    for (int tc = 1; tc <= days; ++tc) {
        int n, s;
        cin >> n >> s;
        ll ans = -1e18;
        for (int i = 0; i < n; ++i) {
            ll f, t;
            cin >> f >> t;
            ans = max(ans, f - max(0LL, t - s));
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    
    return 0;
}
