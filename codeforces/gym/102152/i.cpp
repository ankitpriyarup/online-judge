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
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (int& x : a) {
            cin >> x;
        }
        sort(all(a));
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0 and k > 0) {
                --k;
                a[i] = -a[i];
            }
        }
        sort(all(a));
        if (k & 1) {
            a[0] = -a[0];
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i];
        }
        cout << ans << '\n';
    }
    
    return 0;
}
