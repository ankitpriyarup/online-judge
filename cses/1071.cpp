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
        int x, y;
        cin >> x >> y;
        --x; --y;
        int ring = max(x, y);
        if (ring % 2 == 0) {
            swap(x, y);
        }

        ll ans;
        ll base = 1LL * (ring + 1) * (ring + 1);
        if (x == ring) {
            ans = base - y;
        } else {
            ans = base - ring - (ring - x);
        }

        cout << ans << '\n';
    }

    return 0;
}
