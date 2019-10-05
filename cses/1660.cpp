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
    ll x;
    cin >> n >> x;
    ll cur = 0;
    ll ans = 0;
    map<ll, int> m;
    ++m[0];

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        cur += v;

        ans += m[cur - x];
        ++m[cur];
    }

    cout << ans << '\n';
    
    return 0;
}
