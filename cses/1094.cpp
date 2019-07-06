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
    ll last = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ans += max(0LL, last - x);
        last = max(last, x);
    }

    cout << ans << '\n';

    return 0;
}
