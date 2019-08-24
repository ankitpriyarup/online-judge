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
    for (auto& x : a) {
        cin >> x;
    }

    sort(all(a));
    vector<vector<double>> dp(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = a[i];
    }

    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i + k <= n; ++i) {
            for (int j = i; j + 1 < i + k; ++j) {
                dp[i][i + k - 1] = max(dp[i][i + k - 1], (dp[i][j] + dp[j + 1][i + k - 1]) / 2.0);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[0][n - 1] << '\n';
    
    return 0;
}
