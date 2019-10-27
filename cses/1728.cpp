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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // P(a[i] > a[j]) ?
            // a[i] * a[j] / 2
            double cur;
            if (a[i] > a[j]) {
                double bonus = a[j] * (a[i] - a[j]);
                cur = bonus + a[j] * (a[j] - 1) / 2.0;
            } else {
                cur = a[i] * (a[i] - 1) / 2.0;
            }

            ans += cur / a[i] / a[j];
        }
    }

    cout << fixed << setprecision(6);
    cout << ans << '\n';
    
    return 0;
}
