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

    int n, d;
    cin >> n >> d;
    vector<vi> x(n, vi(d, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> x[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll v = 0;
            for (int k = 0; k < d; ++k) {
                ll dx = x[i][k] - x[j][k];
                dx *= dx;
                // cout << dx <<' ';
                v += dx;
            }

            ll s = sqrt(v);
            // cout << "| " << s << ' ' << v << '\n';
            if (s * s == v or (s - 1) * (s - 1) == v or (s + 1) * (s + 1) == v) {
                ++ans;
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
