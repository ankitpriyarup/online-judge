#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
    int g;
    cin >> g;

    vector<double> p;
    for (int i = 0; i < g; ++i) {
        int c;
        double x;
        cin >> c >> x;
        for (int j = 0; j < c; ++j) {
            p.push_back(x);
        }
    }

    int m = p.size();

    int atts;
    cin >> atts;
    // dp[i][j] = probability of being at pos j after i attempts
    vector<double> dp(m + 1, 0.0);
    dp[0] = 1.0;
    for (int i = 0; i < atts; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            dp[j + 1] += dp[j] * p[j];
            dp[j] *= (1.0 - p[j]);
        }

        /*
        for (int j = 0; j <= m; ++j) {
            cout << dp[j] << ' ';
        }
        cout << '\n';
        */
    }

    cout << dp.back() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(3);
    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
