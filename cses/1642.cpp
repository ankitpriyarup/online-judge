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
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto& y : a) {
        cin >> y;
    }

    if (n < 4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    map<ll, pii> m;
    for (int k = 2; k < n; ++k) {
        for (int i = 0; i < k - 1; ++i) {
            m[a[i] + a[k - 1]] = pii{i + 1, k};
        }

        for (int l = k + 1; l < n; ++l) {
            ll goal = x - a[k] - a[l];
            auto it = m.find(goal);
            if (it != end(m)) {
                cout << it->second.first << ' ' << it->second.second << ' ' << k + 1 << ' ' << l + 1 << '\n';
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}
