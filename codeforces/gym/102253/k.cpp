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

    ll n, k;
    int tc = 1;
    while (cin >> n >> k) {
        --k;

        ll ans;
        if (k < n) {
            ans = k;
        } else {
            k -= n;
            k %= 2 * (n - 1);
            if (k == 2 * (n - 1) - 1) {
                ans = n - 1;
            } else {
                ans = k % (n - 1);
            }
        }

        cout << "Case #" << tc++ << ": " << (ans + 1) << '\n';
    }

    /**
     * 3 pairs
     *
     * 1234567
     * 1231213
     *
     * 123456789
     * 1234123124
     *
     */
    
    return 0;
}
