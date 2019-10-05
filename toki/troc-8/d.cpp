#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;


constexpr int MAXN = 1003;
int n;
ll k;
ll a[4][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> a[j][i];
        }

        sort(a[j], a[j] + n);
    }

    vector<ll> found;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll res = a[0][i] + a[1][j];
            if (res > k) break;
            found.push_back(res);
        }
    }
    sort(all(found));

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll res = a[2][i] + a[3][j];
            if (res > k) break;

            ans += upper_bound(all(found), k - res) - begin(found);
        }
    }

    cout << ans << '\n';
    
    return 0;
}
