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
    vector<pair<ll, ll>> v(n);
    for (auto& p : v) {
        cin >> p.first >> p.second;
    }
    sort(all(v));

    ll ans = 0;
    ll t = 0;
    for (auto& p : v) {
        t += p.first;
        ans += p.second - t;
    }

    cout << ans << '\n';
    
    return 0;
}
