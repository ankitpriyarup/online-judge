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
        vi a(3, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++a[x % 3];
        }
        int ans = a[0];
        int m = min(a[1], a[2]);
        ans += m;
        a[1] -= m;
        a[2] -= m;
        ans += (a[1] / 3) + (a[2] / 3);

        cout << ans << '\n';
    }
    
    return 0;
}
