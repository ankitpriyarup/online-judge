#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, m;
int counts[55];
long long dp[55][300];

int x[55], y[55];

int ZERO = 150;

int main() {
    int T;
    cin >> T;

    while (T-- > 0) {
        memset(counts, 0, sizeof(counts));

        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }

        int px, py, pc;
        for (int i = 0; i < m; ++i) {
            cin >> px >> py >> pc;
            if (pc == 0) {
                pc = -1;
            }

            for (int j = 0; j < n; ++j) {
                if (px == x[j] and py == y[j]) {
                    counts[j] += pc;
                    break;
                }
            }
        }

        /*
        for (int i = 0; i < n; ++i) {
            cout << counts[i] << ' ';
        }
        cout << '\n';
        */

        memset(dp, 0, sizeof(dp));
        // dp[i][j], number of ways to use the first i elements such that they sum to j
        dp[0][ZERO] = 1LL;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 300; ++j) {
                int new_count = j + counts[i];
                if (0 <= new_count and new_count < 300) {
                    // use i
                    dp[i + 1][j + counts[i]] += dp[i][j];
                }

                // don't use i
                dp[i + 1][j] += dp[i][j];
            }
        }

        /*
        for (int j = -2; j <= 2; ++j) {
            for (int i = 0; i <= n; ++i) {
                cout << dp[i][j + ZERO] << ' ';
            }
            cout << '\n';
        }
        */

        long long ans = dp[n][ZERO] - 1;
        for (int i = 0; i < n; ++i) {
            if (counts[i] == 0) {
                --ans;
            }

            for (int j = i + 1; j < n; ++j) {
                if (counts[i] + counts[j] == 0) {
                    --ans;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
