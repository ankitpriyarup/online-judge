#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100005];
// dp[i][0] is the maximum sum up to and including index i without skips
// dp[i][1] is the maximum sum up to and including index i with skips
long long dp[100005][2];

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        bool non_neg = false;
        int max_v = -1000000010;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            non_neg |= a[i] >= 0;
            max_v = max(max_v, a[i]);
        }

        if (!non_neg) {
            cout << max_v << '\n';
        } else {
            dp[0][0] = dp[0][1] = a[0];
            long long ans = a[0];
            for (int i = 1; i < n; ++i) {
                dp[i][0] = max((long long)a[i], dp[i - 1][0] + a[i]);
                dp[i][1] = max((long long)a[i], dp[i - 1][1] + a[i]);
                if (i >= 2)
                    dp[i][1] = max(dp[i - 2][0] + a[i], dp[i][1]);

                ans = max(ans, max(dp[i][0], dp[i][1]));
            }

            /*
            for (int i = 0; i < n; ++i) {
                cout << dp[i][0] << ' ';
            }
            cout << '\n';
            for (int i = 0; i < n; ++i) {
                cout << dp[i][1] << ' ';
            }
            cout << '\n';
            */
            cout << ans << '\n';
        }
    }
    return 0;
}
