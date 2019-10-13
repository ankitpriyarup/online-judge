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

    ll n, m, x;
    cin >> n >> m >> x;
    if (x % n == 0 or x % m == 0) {
        cout << "1\n";
        return 0;
    }

    ll y = n * m - x;

    bool valid = x >= min((n - 1) * m, n * (m - 1));
    // must be some a <= n and b <= m such that a * b = x
    for (ll a = 1; a <= n; ++a) {
        if (x % a == 0) {
            ll b = x / a;
            if (b <= m) {
                valid = true;
                break;
            }
        }

        if (y % a == 0) {
            ll b = y / a;
            if (b <= m) {
                valid = true;
                break;
            }
        }
    }

    cout << (valid ? 2 : 3) << "\n";
    
    return 0;
}
