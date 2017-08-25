#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXM = 102;
const int MAXK = 11;
const int INF = 1e8;

int dp[MAXK][MAXM][MAXM];

int main() {
    for (int i = 1; i < MAXM; ++i) {
        int sum = 0;
        for (int j = i; j < MAXM; ++j) {
            sum += j;
            dp[1][i][j] = sum;
        }
    }

    for (int k = 2; k < MAXK; ++k) {
        for (int i = MAXM - 1; i >= 0; --i) {
            for (int j = i; j < MAXM; ++j) {
                dp[k][i][j] = INF;
                for (int l = i; l <= j; ++l) {
                    dp[k][i][j] = min(dp[k][i][j], l + max(dp[k - 1][i][l - 1], dp[k][l + 1][j]));
                }
            }
        }
    }

    int q;
    scanf("%d", &q);

    int k, x;
    while (q-- > 0) {
        scanf("%d %d\n", &k, &x);
        printf("%d\n", dp[k][1][x]);
    }

    return 0;
}
