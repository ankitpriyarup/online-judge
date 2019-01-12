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
    vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
    dp[0][0] = 1.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
        }
    }

    double ans = 0.0;

    for (int j = (n + 1) >> 1; j <= n; ++j) {
        ans += dp[n][j];
    }

    cout << setprecision(10) << fixed << ans << '\n';
    
    return 0;
}
