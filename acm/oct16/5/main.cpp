#include <iostream>

#define MAX_N 1005

using namespace std;

int T, N, A[MAX_N];

int dp[(1 << 10) + 5][MAX_N];
int digits[MAX_N];

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];

            int amt = A[i];
            digits[i] = 0;

            // Convert the number into a bitmask
            while (amt > 0) {
                int cur = amt % 10;
                digits[i] |= (1 << cur);
                amt /= 10;
            }
        }

        // dp[S][j] = max sum using digits S and last number j
        for (int j = 1; j <= N; j++) {
            for (int s = 0; s < (1 << 10); s++) {
                dp[s][j] = dp[s][j - 1];

                if ((s & digits[j]) == digits[j]) {
                    // digits of j are in s, so we can also remove them
                    dp[s][j] = max(dp[s][j], dp[s - digits[j]][j - 1] + A[j]);
                }
            }
        }

        int best = 0;
        for (int s = 0; s < (1 << 10); s++) {
            best = max(best, dp[s][N]);
        }

        cout << best << endl;
    }

    return 0;
}
