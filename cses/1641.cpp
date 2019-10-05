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

    map<ll, int> m;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto it = m.find(x - a[i] - a[j]);
            if (it != end(m)) {
                cout << (it->second + 1) << ' ' << (i + 1) << ' ' << (j + 1) << '\n';
                return 0;
            }
        }
        m[a[i]] = i;
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}
