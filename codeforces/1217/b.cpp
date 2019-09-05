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
        int n;
        ll x;
        cin >> n >> x;
        vector<pair<ll, ll>> v(n);

        ll big = 0;
        ll net = 0;

        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
            big = max(big, v[i].first);
            net = max(net, v[i].first - v[i].second);
        }

        // k * net + big > x
        // k * net >= x - big
        // k >= (x - big) / net
        if (x <= big) {
            cout << "1\n";
        } else if (net <= 0) {
            cout << "-1\n";
        } else {
            ll k = (x - big + net - 1) / net;
            cout << (k + 1) << '\n';
        }
    }

    return 0;
}
