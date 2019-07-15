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
        ll m;
        cin >> m;
        ll lo = 0;
        ll hi = 4e9;
        while (lo + 1 < hi) {
            ll mid = lo + ((hi - lo) >> 1);
            ll ed = mid * (mid - 1) / 2;
            if (ed >= m) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        cout << hi << '\n';
    }
    
    return 0;
}
