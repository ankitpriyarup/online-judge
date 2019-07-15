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

    int l, r;
    cin >> l >> r;
    ll ans = 1e9;
    for (int i = l; i <= min(r, l + 2020); ++i)  {
        for (int j = i + 1; j <= min(r, i + 2020); ++j) {
            ans = min(ans, 1LL * i * j % 2019);
        }
    }

    cout << ans << '\n';
    
    return 0;
}
