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
    int tc = 1;
    while (T-- > 0) {
        int d, n;
        cin >> d >> n;
        ll ans = 1LL * d * (2 * n - 2);
        cout << "Grid #" << tc++ << ": ";
        if (d > (n - 1) * (n - 1) + 1) {
            cout << "impossible\n";
        } else {
            cout << ans << '\n';
        }

        cout << '\n';
    }
    
    return 0;
}
