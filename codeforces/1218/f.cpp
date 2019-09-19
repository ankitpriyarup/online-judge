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
    ll cur;
    cin >> n >> cur;
    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    ll boost;
    cin >> boost;

    vi c(n);
    for (auto& x : c) {
        cin >> x;
    }

    multiset<int> ms;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ms.insert(c[i]);
        while (!ms.empty() and cur < a[i]) {
            cur += boost;
            ans += *ms.begin();
            ms.erase(begin(ms));
        }

        if (cur < a[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << '\n';

    return 0;
}
