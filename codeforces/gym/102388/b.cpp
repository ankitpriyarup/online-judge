#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        ll x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        ll dx = abs(x1 - x0);
        ll dy = abs(y1 - y0);
        if (dx == 0 and dy == 0) {
            cout << 1 << '\n';
        } else {
            cout << 1 + gcd(dx, dy) << '\n';
        }
    }
    
    return 0;
}
