#include <cstdio>

using namespace std;
using ll = long long;

constexpr int MAXN = 20;
int n, m;
int a[MAXN][MAXN];
int good_col[MAXN];
int inc_mask[MAXN][MAXN];
int source[1 << MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &a[i][j]);
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int k = j + 1; k < m; ++k) {
            for (int i = 0; i < n; ++i) {
                if (a[i][j] < a[i][k]) {
                    inc_mask[j][k] |= (1 << i);
                }
            }
        }
    }

    ll ans = 0;
    for (int row_mask = 1; row_mask < (1 << n); ++row_mask) {
        for (int j = 0; j < m; ++j) {
            int x = -1;
            int y = -1;
            good_col[j] = 1;
            for (int i = 0; good_col[j] and i < n; ++i) {
                if ((row_mask & (1 << i))  == 0)
                    continue;

                if (x == -1) {
                    x = a[i][j];
                } else if (y == -1) {
                    y = a[i][j];
                } else {
                    good_col[j] &= (x > y) == (y > a[i][j]);
                    y = a[i][j];
                }
            }

            ans += good_col[j];
        }

        for (int j = 0; j < m; ++j) {
            if (!good_col[j]) continue;
            for (int k = j + 1; k < m; ++k) {
                if (!good_col[k]) continue;
                int cur = row_mask & inc_mask[j][k];
                if (source[cur][j] != row_mask) {
                    source[cur][j] = row_mask;
                    dp[cur][j] = 0;
                }
                if (source[cur][k] != row_mask) {
                    source[cur][k] = row_mask;
                    dp[cur][k] = 0;
                }
                dp[cur][k] += dp[cur][j] + 1;
                ans += dp[cur][j] + 1;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
