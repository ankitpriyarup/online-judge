#include <iostream>
#include <cstring>

using namespace std;

int L;
int dp[1001][101];
int strategies[1001][10][2];
int S[1001];

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cin >> L;
        for (int i = 0; i < L; ++i) {
            cin >> S[i];
            for (int j = 0; j < S[i]; ++j) {
                for (int k = 0; k < 2; ++k) {
                    cin >> strategies[i][j][k];
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        for (int j = 1; j <= 100; ++j) {
            dp[L - 1][j] = dp[L - 1][j - 1];
            for (int s = 0; s < S[L - 1]; ++s) {
                int time = strategies[L - 1][s][0];
                int cost = strategies[L - 1][s][1];
                if (cost < j) {
                    dp[L - 1][j] = dp[L - 1][j] == -1 ? time : min(dp[L - 1][j], time);
                }
            }
        }
        for (int i = L - 2; i >= 0; --i) {
            for (int j = 1; j <= 100; ++j) {
                dp[i][j] = dp[i][j - 1];
                for (int s = 0; s < S[i]; ++s) {
                    int time = strategies[i][s][0];
                    int cost = strategies[i][s][1];
                    int new_health = min(100, j - cost);
                    if (new_health > 0 && dp[i + 1][new_health] != -1) {
                        int new_dp = dp[i + 1][new_health] + time;
                        dp[i][j] = dp[i][j] == -1 ? new_dp : min(dp[i][j], new_dp);
                    }
                }
            }
        }

        /*
        for (int i = 0; i < L; ++i) {
            for (int j = 1; j <= 100; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }
        */

        if (dp[0][100] == -1) {
            cout << "Case " << case_num << ": IMPOSSIBLE\n";
        } else {
            cout << "Case " << case_num << ": " << dp[0][100] << '\n';
        }
    }
    return 0;
}
