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

    int n, h, v;
    cin >> n >> h >> v;
    ll ans = 4LL * max(h, n - h) * max(v, n - v);
    cout << ans << '\n';
    
    return 0;
}
