#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

inline ll dist(int x, int y, int m) {
    ll res = abs(x - y);
    for (int k = -1; k <= 1; ++k) {
        res = min(res, abs(x - y + 1LL * k * m));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int m, n;
        cin >> m >> n;
        vi a(n);
        for (auto& x : a) {
            cin >> x;
            --x;
        }

        ll ans = 0LL;
        for (int i = 1; i < n; ++i) {
            ans += dist((a[i - 1] + 1) % m, a[i], m);
        }

        cout << ans << '\n';
    }
    
    return 0;
}
