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

    ll ans = 0.0;
    for (int i = 1; i <= n; ++i) {
        ans += 1LL * i * (i - 1);
    }

    ld exp = static_cast<ld>(ans) / n;
    cout << setprecision(15) << fixed << exp << '\n';

    return 0;
}
