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
    vector<ll> costs(n), sums(n), m(n);
    for (int i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        m[i] = max(a, max(b, c));
        costs[i] = a + b + c - m[i] + 2;
        sums[i] = a + b + c;
    }

    sort(all(costs));
    for (int i = 0; i < n; ++i) {
        // count the number of values <= sums[i]
        int ans = upper_bound(all(costs), sums[i]) - begin(costs);
        if (sums[i] - m[i] + 2 <= sums[i])
            --ans;
        cout << ans << ' ';
    }
    
    return 0;
}
