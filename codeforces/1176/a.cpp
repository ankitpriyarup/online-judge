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

    int q;
    cin >> q;
    while (q-- > 0) {
        ll n;
        cin >> n;

        int ans = 0;
        while (n > 1) {
            ++ans;
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 3 == 0) {
                n /= 3;
                n <<= 1;
            } else if (n % 5 == 0) {
                n /= 5;
                n <<= 2;
            } else {
                ans = -1;
                break;
            }
        }

        cout << ans << '\n';
    }

    
    return 0;
}
