#include <iostream>
#include <cstring>

using namespace std;

int S, N;
int dp[2002][2002];
int w[2002];
int v[2002];
int main() {
    cin >> S >> N;
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }

    memset(dp, 0, sizeof(dp));
    for (int cap = 1; cap <= S; ++cap) {
        if (w[0] <= cap) {
            dp[0][cap] = v[0];
        }
        for (int i = 1; i < N; ++i) {
            dp[i][cap] = dp[i - 1][cap];

            int remaining = cap - w[i];
            if (remaining >= 0) {
                dp[i][cap] = max(dp[i][cap], v[i] + dp[i - 1][remaining]);
            }
        }
    }

    cout << dp[N - 1][S] << '\n';

    return 0;
}
