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

    int T;
    cin >> T;
    while (T-- > 0) {
        int a, b;
        cin >> a >> b;
        ll ans = min(a, b);
        if (a > ans) {
            ld dist = 1.0 + log(2.0L) * (a - ans) / log(10);
            ans += dist;
        } else {
            ld dist = 1.0 + log(5.0L) * (b - ans) / log(10);
            ans += dist;
        }

        cout << ans << '\n';
    }
    
    return 0;
}
