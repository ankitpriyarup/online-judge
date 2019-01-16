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
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));

    double ans = 1e9 + 7;
    for (int i = 1; i + 1 < n; ++i) {
        double r = (a[i + 1] + a[i]) / 2.0;
        double l = (a[i] + a[i - 1]) / 2.0;

        ans = min(ans, r - l);
    }

    cout << setprecision(1) << fixed << ans << '\n';
    
    return 0;
}
