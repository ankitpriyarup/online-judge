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

    string s, a, b;
    cin >> s >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vi> dp(n + 1, vi(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (!dp[i][j]) continue;

            if (i < n and s[i + j] == a[i]) {
                dp[i + 1][j] = 1;
            }
            if (j < m and s[i + j] == b[j]) {
                dp[i][j + 1] = 1;
            }
        }
    }

    cout << (dp[n][m] ? "yes" : "no");
    
    return 0;
}
