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

    int n, d;
    cin >> n >> d;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++m[x / d];
    }

    ll ans = 0;
    for (auto& p : m) {
        ans += 1LL * p.second * (p.second - 1) / 2;
    }

    cout << ans << '\n';
    
    return 0;
}
