#include <cstdio>

using namespace std;

const int MAXN = 32;

// valid pieces are
// flat
// bottom sticking out
// top sticking out

long long dp[MAXN][3];

int main() {
    dp[0][0] = 1LL;
    dp[0][1] = 0LL;
    dp[0][2] = 0LL;

    for (int col = 0; col < MAXN; ++col) {
        // from a flat piece, you can go to a flat place two over
        // or go to a top or bottom 1 over
        if (col + 2 < MAXN) {
            dp[col + 2][0] += dp[col][0];
        }
        if (col + 1 < MAXN) {
            dp[col + 1][1] += dp[col][0];
            dp[col + 1][2] += dp[col][0];
        }

        for (int j = 1; j < 3; ++j) {
            // from a non flat piece you can go to a flat piece one over
            // or a non flat piece two over
            if (col + 2 < MAXN) {
                dp[col + 2][j] += dp[col][j];
            }

            if (col + 1 < MAXN) {
                dp[col + 1][0] += dp[col][j];
            }
        }
    }

    int x;
    while (scanf("%d", &x) == 1) {
        if (x == -1) {
            break;
        }

        printf("%lld\n", dp[x][0]);
    }
    return 0;
}
