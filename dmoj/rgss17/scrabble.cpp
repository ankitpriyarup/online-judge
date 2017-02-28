#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 10004;
int n, m;
char a[MAXN];
char b[MAXN];

int dp[MAXN];
int lastdp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> a;
    cin >> b;

    for (int i = 0; i <= m; ++i) {
        lastdp[i] = i;
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        dp[0] = i;
        for (int j = 1; j <= m; ++j) {
            dp[j] = lastdp[j - 1];
            if (a[i - 1] != b[j - 1]) {
                ++dp[j];
            }

            dp[j] = min(dp[j], lastdp[j] + 1);
            dp[j] = min(dp[j], dp[j - 1] + 1);
        }

        memcpy(lastdp, dp, sizeof(dp));
        memset(dp, 0, sizeof(dp));
    }

    long long ans = 0LL;
    for (int i = 1; i < m; ++i) {
        ans += lastdp[i];
    }

    cout << ans << '\n';

    return 0;
}
