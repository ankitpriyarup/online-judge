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
        ll x;
        cin >> x;
        int ans = 0;
        while (x > 0) {
            if (x % 2 == 0) {
                ++ans;
            }
            x /= 2LL;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
