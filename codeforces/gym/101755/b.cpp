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
    vector<pii> a(n);
    for (auto& p : a) {
        cin >> p.first >> p.second;
    }

    ll ans = 5e18;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        int k = (j + 1) % n;
        ll dx1 = a[j].first - a[i].first;
        ll dy1 = a[j].second - a[i].second;
        ll dx2 = a[k].first - a[i].first;
        ll dy2 = a[k].second - a[i].second;

        ll area = dx1 * dy2 - dx2 * dy1;
        if (area > 0) {
            ans = min(ans, area);
        }
    }

    cout << ans << '\n';
    
    return 0;
}
