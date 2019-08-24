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
        int n;
        cin >> n;
        vi a(n);
        map<int, int> m;
        for (auto& x : a) {
            cin >> x;
            ++m[x];
        }

        ll ans = 0LL;
        for (auto& x : a) {
            ans += m[2 * x];
        }

        cout << ans << '\n';
    }
    
    return 0;
}
