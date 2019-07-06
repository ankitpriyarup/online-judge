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
    vector<ll> a(n + 1), p(n + 1);
    p[0] = a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = a[i];
    }

    for (int sz = 2; sz <= n; ++sz) {
        for (int i = 1; i + sz <= n + 1; ++i) {
            int j = i + sz - 1;

            dp[i][j] = p[j] - p[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}
