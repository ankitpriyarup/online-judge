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
    vi a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;

    int ans = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, a[i] + b[i]);
    }

    cout << ans << '\n';
    cout << 0 << '\n';
    for (int i = 0; i < n; ++i) {
        cout << min(a[i], ans) << '\n';
    }
    cout << ans << '\n';
    
    return 0;
}
