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
    map<int, int> m;
    int cur = 0;
    m[cur] = 1;

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x = ((x % n) + n) % n;
        cur = (cur + x) % n;
        ans += m[cur];
        ++m[cur];
    }

    cout << ans << '\n';

    return 0;
}
