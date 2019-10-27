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
    for (auto& x : a)
        cin >> x;

    vi b(all(a));
    vi c(all(a));
    for (int i = 1; i < n; ++i) {
        b[i] = max(b[i - 1], b[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        c[i] = min(c[i], c[i + 1]);
    }

    int ans = a[0] < c[1];
    ans += a[n - 1] >= b[n - 2];
    for (int i = 1; i + 1 < n; ++i) {
        ans += b[i - 1] <= a[i] and a[i] < c[i + 1];
    }

    cout << ans << '\n';
    
    return 0;
}
