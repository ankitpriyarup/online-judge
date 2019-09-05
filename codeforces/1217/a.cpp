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

    int T;
    cin >> T;
    while (T-- > 0) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a + c <= b) {
            cout << 0 << '\n';
        } else {
            ll lo = -1;
            ll hi = c;
            while (lo + 1 < hi) {
                ll mid = lo + (hi - lo) / 2;
                if (a + mid <= b + (c - mid)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            ll ans = c - lo;
            cout << ans << '\n';
        }
    }
    
    return 0;
}
