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
        int m = 1e9 + 7;
        int n;
        cin >> n;
        vi a(n);
        for (auto& x : a) {
            cin >> x;
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (m < a[i]) ++ans;
            m = min(a[i], m);
        }
        cout << ans << '\n';
    }
    
    return 0;
}
