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

    ll r;
    cin >> r;
    for (int x = 1; x * x <= r; ++x) {
        ll v = r - x * x - x - 1;
        if (v < 0) break;
        if (v % (2 * x) == 0) {
            ll y = v / (2 * x);
            cout << x << ' ' << y << '\n';
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}
