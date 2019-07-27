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
    vi a(n + 1), b(n);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (a[i] < b[i]) {
            int take = min(a[i + 1], b[i] - a[i]);
            a[i + 1] -= take;
            a[i] += take;
        }

        ans += min(a[i], b[i]);
    }

    cout << ans << '\n';
    
    return 0;
}
