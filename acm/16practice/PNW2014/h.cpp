#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#define P(x) cout << #x << ": " << (x) << '\n';

using namespace std;

int n, m;
int s[25];

// dp[i][j] is true iff you can hit score i doing j pushups
bool dp[6000][6000];

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            cin >> s[i];
        }

        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j]) {
                    for (int k = 0; k < m; ++k) {
                        int score = i + s[k];
                        int pushups = j + score;
                        if (pushups <= n)
                            dp[score][pushups] = true;
                    }
                }
            }
        }

        int ans = -1;
        for (int i = 0; i <= 5100; ++i) {
            if (dp[i][n]) {
                ans = i;
            }
        }

        cout << ans << '\n';
    }
}
