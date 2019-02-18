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

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));
    ll ans = 0LL;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        ll x = a[i] + a[j];
        ans += x * x;
    }

    cout << ans << '\n';
    
    return 0;
}
