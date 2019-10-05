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
    ll ans = 0;
    ll cur = 0;
    ll max_val = -1e9 - 7;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        cur = max(cur + x, x);
        ans = max(ans, cur);
        max_val = max(max_val, x);
    }

    if (max_val < 0) {
        ans = max_val;
    }

    cout << ans << '\n';
    
    return 0;
}
