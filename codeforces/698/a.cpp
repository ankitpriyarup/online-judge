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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    constexpr int INF = 1e9;
    // min days of rest if you end day i with activity j
    vector<vi> dp(n + 1, vi(3, INF));
    for (int j = 0; j < 3; ++j)
        dp[0][j] = 0;

    for (int i = 0; i < n; ++i) {
        int d = min(dp[i][0], min(dp[i][1], dp[i][2]));
        dp[i + 1][0] = min(dp[i + 1][0], d + 1);
        for (int j = 1; j <= 2; ++j) {
            if ((a[i] & j) == 0) {
                continue;
            }

            dp[i + 1][j] = min(dp[i + 1][j], dp[i][0]);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][3 ^ j]);
        }
    }

    int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << ans << '\n';
    
    return 0;
}
