#include <iostream>

using namespace std;

int n;
int a[101];
int dp[101];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        dp[i] = 1000;
        if (a[i] == 1) continue;
        if (i + 1 < n and a[i + 1] == 0) {
            dp[i] = min(dp[i], 1 + dp[i + 1]);
        }
        if (i + 2 < n and a[i + 2] == 0) {
            dp[i] = min(dp[i], 1 + dp[i + 2]);
        }
    }

    cout << dp[0] << '\n';
    return 0;
}
