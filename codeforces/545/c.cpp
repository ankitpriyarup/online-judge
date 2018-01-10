#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAXN = 100005;
int n;
int x[MAXN];
int h[MAXN];
// dp[i][flag] = max number we can fall if the last one falls flag way
// 0 - fall left, 1 - stay up, 2 - fall right
int dp[MAXN][3];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, h + i);
    }

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = (n == 1 or x[0] + h[0] < x[1]);

    for (int i = 1; i < n; ++i) {
        // fall left
        if (x[i] - h[i] > x[i - 1])
            dp[i][0] = 1 + max(dp[i - 1][0], dp[i - 1][1]);
        if (x[i] - h[i] > x[i - 1] + h[i - 1])
            dp[i][0] = max(dp[i][0], 1 + dp[i - 1][2]);

        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        if (x[i - 1] + h[i - 1] < x[i])
            dp[i][1] = max(dp[i][1], dp[i - 1][2]);

        if (i == n - 1 or x[i] + h[i] < x[i + 1])
            dp[i][2] = 1 + dp[i][1];
    }

    printf("%d\n", dp[n - 1][2]);

    return 0;
}
