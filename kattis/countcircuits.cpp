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

    int n;
    cin >> n;

    vi x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    int m = min(n, 20);
    map<pii, int> left;
    for (int mask = 0; mask < (1 << m); ++mask) {
        int dx = 0;
        int dy = 0;
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                dx += x[i];
                dy += y[i];
            }
        }

        ++left[pii{dx, dy}];
    }

    if (m == n) {
        cout << left[pii{0, 0}] - 1 << '\n';
    } else {
        int m2 = n - m;
        ll ans = 0LL;
        for (int mask = 0; mask < (1 << m2); ++mask) {
            int dx = 0;
            int dy = 0;
            for (int i = 0; i < m2; ++i) {
                if (mask & (1 << i)) {
                    dx += x[m + i];
                    dy += y[m + i];
                }
            }

            ans += left[pii{-dx, -dy}];
        }

        cout << ans - 1 << '\n';
    }
    
    return 0;
}
