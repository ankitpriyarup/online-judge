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

    ll n, k;
    int m;
    cin >> n >> m >> k;
    vector<ll> a(m);
    for (auto& x : a) {
        cin >> x;
        --x;
    }

    int l = 0;
    int ans = 0;
    while (l < m) {
        ll pos = a[l] - l;
        ll page = pos / k;
        ll end = (page + 1) * k;

        int r = l;
        while (r + 1 < m and a[r + 1] - l < end) {
            ++r;
        }

        // cout << l << ' ' << r << '\n';
        ++ans;
        l = r + 1;
    }

    cout << ans << '\n';
    
    return 0;
}
