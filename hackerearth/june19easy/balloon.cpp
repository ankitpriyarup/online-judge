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
        ll g, p;
        cin >> g >> p;
        int n;
        cin >> n;
        int gs = 0;
        int ps = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            gs += x;
            ps += y;
        }

        ll ans = min(g * gs + p * ps, g * ps + p * gs);
        cout << ans << '\n';
    }
    
    return 0;
}
