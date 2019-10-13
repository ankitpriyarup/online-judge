#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        vector<pair<ll, ll>> b(3);
        for (int i = 0; i < 3; ++i) {
            cin >> b[i].first >> b[i].second;
        }

        ll ans = 4e18;
        for (int m = 0; m < 8; ++m) {
            vector<pair<ll, ll>> a(all(b));
            for (int i = 0; i < 3; ++i) {
                if (m & (1 << i)) {
                    swap(a[i].first, a[i].second);
                }
            }

            /*
            cout << '\n';
            for (int i = 0; i < 3; ++i) {
                cout << "{" << a[i].first << ", " << a[i].second << "}, ";
            }
            cout << '\n';
            */

            ll sumx = 0;
            ll maxx = 0;
            ll sumy = 0;
            ll maxy = 0;

            for (int i = 0; i < 3; ++i) {
                sumx += a[i].first;
                maxx = max(maxx, a[i].first);

                sumy += a[i].second;
                maxy = max(maxy, a[i].second);
            }

            // cout << sumx * maxy << " " << maxx * sumy << '\n';
            // all on x axis
            ans = min(ans, sumx * maxy);
            //all on y axis
            ans = min(ans, maxx * sumy);

            sort(all(a));
            do {
                // ....
                // 3...
                // 12..
                ll x = max(a[0].first + a[1].first, a[2].first);
                ll y;
                if (a[2].first <= a[0].first) {
                    y = max(a[0].second + a[2].second, a[1].second);
                } else {
                    y = max(a[0].second, a[1].second) + a[2].second;
                }

                // cout << x * y << '\n';
                ans = min(ans, x * y);
            } while (next_permutation(all(a)));
        }
    
        cout << ans << '\n';
    }

    return 0;
}
