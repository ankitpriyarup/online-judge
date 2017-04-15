#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n;
int a[MAXN];

int dp[2][MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int ans = 1;
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[0][i] = a[i] > a[i - 1] ? dp[0][i - 1] + 1 : 1;
        ans = max(ans, dp[0][i]);
    }

    dp[1][n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        dp[1][i] = a[i] < a[i + 1] ? dp[1][i + 1] + 1 : 1;
        ans = max(ans, dp[1][i]);
    }

    ans = max(ans, 1 + dp[0][n - 2]);
    ans = max(ans, 1 + dp[1][1]);

    for (int i = 1; i < n - 1; ++i) {
        ans = max(ans, 1 + dp[1][i + 1]);
        ans = max(ans, 1 + dp[0][i - 1]);
        if (a[i - 1] + 2 <= a[i + 1]) {
            ans = max(ans, 1 + dp[1][i + 1] + dp[0][i - 1]);
        }
    }

    printf("%d\n", ans);
    return 0;
}
