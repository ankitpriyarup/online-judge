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

    int n, m, k;
    cin >> n >> m >> k;

    assert(n + m >= k);

    double ans = min(m, k - 1) / static_cast<double>(k);
    int rem = m - (k - 1);
    if (rem > 0) {
        ans += rem / static_cast<double>(n + rem) / k;
    }

    cout << fixed << setprecision(10) << ans << '\n';
    
    return 0;
}
