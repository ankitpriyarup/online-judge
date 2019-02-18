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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int m = max(b, d);
    vi square(m + 1, false);
    vi divs(m + 1, 0);
    ll ans = 1LL * (b - a + 1) * (d - c + 1);
    for (int i = 2; i * i <= m; ++i) {
        for (int j = i * i; j <= m; j += i * i)
            square[j] = true;
    }

    for (int i = 2; i <= m; ++i) {
        if (square[i]) continue;
        if (divs[i] == 0) {
            // prime i
            for (int j = i; j <= m; j += i) {
                ++divs[j];
            }
        }

        int v1 = (b / i) - ((a - 1) / i);
        int v2 = (d / i) - ((c - 1) / i);
        int sgn = (divs[i] & 1) ? -1 : 1;
        ans += 1LL * sgn * v1 * v2;

        // cout << "i: " << i << " v1 v2 " << v1 << " " << v2 << "  divs sgn " << divs[i] << " " << sgn << '\n';
    }

    cout << ans << '\n';
    
    return 0;
}
