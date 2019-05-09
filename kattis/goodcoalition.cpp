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

    int T;
    cin >> T;
    while (T-- > 0) {
        vector<double> dp(151, 0.0);
        dp[0] = 1.0;

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int s, p;
            cin >> s >> p;
            for (int j = 150 - s; j >= 0; --j) {
                dp[j + s] = max(dp[j + s], dp[j] * p / 100.0);
            }
        }

        double ans = 0.0;
        for (int j = 76; j <= 150; ++j) {
            ans = max(ans, dp[j]);
        }

        ans *= 100.0;
        cout << fixed << setprecision(10) << ans << '\n';
    }
    
    return 0;
}
