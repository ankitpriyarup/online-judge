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
        ll a;
        cin >> a;
        // find max d such that
        // da - 2^d - 1
        ll d1 = 1;
        ll d2 = 0;
        ll max_prof = 0;
        for (ll d = 1; d <= 60; ++d) {
            ll profit = 1LL * d * a - 1LL * (1LL << d) + 1LL;
            if (profit > 0) {
                d1 = d;
            }
            if (profit > max_prof) {
                max_prof = profit;
                d2 = d;
            }
        }

        cout << d1 << ' ' << d2 << '\n';
    }
    
    return 0;
}
