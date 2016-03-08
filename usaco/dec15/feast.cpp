#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[2][5000005];
int main() {
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    int T, A, B;
    fin >> T >> A >> B;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[1][0] = 1;

    int ans = 0;
    for (int i = 0; i <= T; ++i) {
        if (i >= A) {
            dp[0][i] |= dp[0][i - A];
        }

        if (i >= B) {
            dp[0][i] |= dp[0][i - B];
        }

        dp[1][i] |= dp[0][i];
        dp[1][i / 2] |= dp[0][i];
    }

    for (int i = 0; i <= T; ++i) {
        if (i >= A) {
            dp[1][i] |= dp[1][i - A];
        }

        if (i >= B) {
            dp[1][i] |= dp[1][i - B];
        }

        if (dp[1][i])
            ans = max(ans, i);
    }

    fout << ans << '\n';
    return 0;
}
