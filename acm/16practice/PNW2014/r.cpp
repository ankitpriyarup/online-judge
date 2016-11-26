#include <iostream>

using namespace std;

// number of ramp numbers of length i ending with digit j
// if k, you have to stay under s[i], otherwise you're free
int dp[88][10][2];

int solve(string s) {
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 10; ++i) {
        dp[0][i][0] = 1;
        dp[0][i][1] = (i < (s[0] - '0'));
    }

    for (int i = 1; i < n, ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int p = 0; p <= j; ++p) {
                    dp[i][j][k] += dp[i - 1][p][k];
                }
            }
        }
    }
}

int main() {
    int T, n;
    cin >> T;

    string s;
    while (T-- > 0) {
        cin >> s;
        n = s.size();
        bool is_ramp = true;
        for (int i = 1; i < n; ++i) {
            is_ramp &= s[i] >= s[i - 1];
        }

        if (!is_ramp) {
            cout << -1 << '\n';
        } else {
            cout << solve(s) << '\n';
        }
    }
    return 0;
}
