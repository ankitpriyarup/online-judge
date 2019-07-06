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
    int ans = 0;
    for (ll k = 5; k <= n; k *= 5) {
        ans += (n / k);
    }

    cout << ans << '\n';

    return 0;
}
