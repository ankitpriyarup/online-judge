#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 102;
const long long INF = 1e18;
int n, m;
int c[MAXN];

int p[MAXN][MAXN];

// dp[i][j][k] = min cost to color first i trees such that last color is j and total k segments
long long dp[MAXN][MAXN][MAXN];

int main() {
    int kk;
    scanf("%d %d %d", &n, &m, &kk);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", c + i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &p[i][j]);
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= n; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    for (int j = 1; j <= m; ++j) {
        if (c[1] == 0)
            dp[1][j][1] = p[1][j];
        else if (c[1] == j)
            dp[1][j][1] = 0LL;
    }

    for (int i = 2; i <= n; ++i) {
        for (int k = 1; k <= n; ++k) {
            for (int j = 1; j <= m; ++j) {
                if (c[i] != 0 and c[i] != j) {
                    dp[i][j][k] = INF;
                    continue;
                }

                long long cost = (c[i] == j) ? 0 : p[i][j];
                dp[i][j][k] = INF;

                for (int l = 1; l <= m; ++l) {
                    if (j == l) {
                        if (dp[i - 1][l][k] == INF) continue;

                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k] + cost);
                    } else {
                        if (dp[i - 1][l][k - 1] == INF) continue;

                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k - 1] + cost);
                    }
                }
            }
        }
    }

    /*
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                printf("%lld ", dp[i][j][k]);
            }
            puts("");
        }
        puts("");
    }
    */

    long long ans = INF;
    for (int j = 1; j <= m; ++j) {
        ans = min(ans, dp[n][j][kk]);
    }
    printf("%lld\n", ans == INF ? -1 : ans);
    return 0;
}
