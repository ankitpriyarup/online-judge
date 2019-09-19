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

    int base, bonus;
    cin >> base >> bonus;
    int T;
    cin >> T;
    while (T-- > 0) {
        int x;
        cin >> x;
        ll ans = min(x, 1000) * base + max(0, x - 1000) * bonus;
        cout << x << ' ' << ans << '\n';
    }
    
    return 0;
}
