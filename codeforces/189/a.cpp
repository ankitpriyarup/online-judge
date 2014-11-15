#include <iostream>
#include <algorithm>

using namespace std;

int N, A, B, C;
int dp[4444];
int main() {
    cin >> N >> A >> B >> C;
    fill(dp, dp + N + 2, -1);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (i >= A && dp[i - A] >= 0) {
            dp[i] = max(dp[i], 1 + dp[i - A]);
        }
        if (i >= B && dp[i - B] >= 0) {
            dp[i] = max(dp[i], 1 + dp[i - B]);
        }
        if (i >= C && dp[i - C] >= 0) {
            dp[i] = max(dp[i], 1 + dp[i - C]);
        }
    }

    cout << dp[N] << '\n';
}
