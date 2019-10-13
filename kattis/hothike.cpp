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

    int ans = 0;
    int mx = max(a[0], a[2]);
    for (int i = 1; i + 1 < n; ++i) {
        int cur = max(a[i - 1], a[i + 1]);
        if (cur < mx) {
            mx = cur;
            ans = i - 1;
        }
    }

    cout << ans + 1 << ' ' << mx << '\n';
    
    return 0;
}
