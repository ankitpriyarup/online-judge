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
    vector<array<int, 3>> h(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> h[i][j];
        }
    }

    vector<array<ll, 3>> dp(n);
    for (int j = 0; j < 3; ++j) {
        dp[0][j] = h[0][j];
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], h[i][j] + dp[i - 1][k]);
            }
        }
    }

    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << '\n';
    
    return 0;
}
