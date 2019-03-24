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

    int v;
    cin >> v;

    int ans = 1e9 + 7;
    // find min surface area of box with volume v
    for (int x = 1; x <= v; ++x) {
        for (int y = 1; x * y <= v; ++y) {
            int z = v / x / y;
            if (x * y * z == v) {
                ans = min(ans, 2 * (x * y + x * z + y * z));
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
