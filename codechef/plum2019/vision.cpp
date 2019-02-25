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

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vi> dp(n + 1, vi(m + 1));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = min(dp[i][j], (s[i - 1] != t[j - 1]) + dp[i - 1][j - 1]);
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    cout << dp[n][m] << '\n';
    
    return 0;
}
