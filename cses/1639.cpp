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

    vi dp(m + 1);
    iota(all(dp), 0);

    // dp[i][j] = 1 + dp[i - 1][j], 1 + dp[i][j - 1] , (1?) + dp[i - 1][j - 1]
    for (int i = 0; i < n; ++i) {
        vi ndp(m + 1, 1e9);
        for (int j = 0; j < m; ++j) {
            ndp[j] = min(ndp[j], 1 + dp[j]);
            ndp[j + 1] = min(ndp[j + 1], 1 + ndp[j]);
            ndp[j + 1] = min(ndp[j + 1], (s[i] != t[j]) + dp[j]);
        }

        swap(dp, ndp);
    }

    cout << dp.back() << '\n';
    
    return 0;
}
