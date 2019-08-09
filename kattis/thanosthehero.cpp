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
    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    ll ans = 0LL;
    for (int i = n - 2; i >= 0; --i) {
        ll v = min(a[i], a[i + 1] - 1);
        if (a[i] > v) {
            ans += a[i] - v;
            a[i] = v;
        }
    }

    if (a[0] < 0) {
        cout << 1 << '\n';
    } else {
        cout << ans << '\n';
    }
    
    return 0;
}
