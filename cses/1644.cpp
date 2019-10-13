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

    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];
    }

    // a = [3, 2, 6]
    // p = [0, 3, 5, 11]
    
    ll ans = -1e18;
    multiset<ll> ms;
    for (int i = a; i <= n; ++i) {
        ms.insert(p[i - a]);
        if (i - b > 0) {
            ms.erase(ms.find(p[i - b - 1]));
        }

        ans = max(ans, p[i] - *begin(ms));
    }

    cout << ans << '\n';

    return 0;
}
