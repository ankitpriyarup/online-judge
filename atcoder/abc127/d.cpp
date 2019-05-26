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

    int n, m;
    cin >> n >> m;
    map<int, int> f;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++f[x];
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        f[y] += x;
    }

    int rem = n;
    auto it = prev(end(f));
    ll ans = 0LL;
    while (rem > 0) {
        int take = min(it->second, rem);
        /*
        cout << "val: " << it->first << '\n';
        cout << "freq: " << it->second << '\n';
        cout << "take: " << take << '\n';
        */

        ans += 1LL * it->first * take;
        rem -= take;
        if (it != begin(f))
            it = prev(it);
    }

    cout << ans << '\n';
    
    return 0;
}
