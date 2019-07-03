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
        ll r;
        int k;
        cin >> r >> k;
        r *= r;
        --k;

        // circle area is pi r^2
        // square area is r^2
        // circle -> square: r *= 2
        // square -> circle: r *= sqrt(2)
        while (k >= 2) {
            k -= 2;
            r <<= 1;
        }

        if (k) {
            cout << (4 * r) << '\n';
        } else {
            cout << r << "PI\n";
        }
    }
    
    return 0;
}
