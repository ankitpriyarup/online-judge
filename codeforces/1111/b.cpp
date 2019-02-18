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

    int n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));
    vector<ll> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; ++i)
        p[i] = p[i - 1] + a[i];

    double ans = -1.0;
    for (int take = 0; take < n; ++take) {
        if (take > m) break;
        ll inc = min(1LL * k * (n - take), 1LL * m - take);
        ll sum = p[n - 1] - (take == 0 ? 0LL : p[take - 1]) + inc;
        ans = max(ans, sum / static_cast<double>(n - take));
    }

    cout << setprecision(10) << fixed << ans << '\n';
    
    return 0;
}
