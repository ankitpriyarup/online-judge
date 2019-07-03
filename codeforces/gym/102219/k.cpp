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
    for (int tc = 1; tc <= T; ++tc) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(all(a));
        ll cur = 0;
        int ans = 0;
        for (int x : a) {
            if (cur <= x) {
                cur += x;
                ++ans;
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }
    
    return 0;
}
