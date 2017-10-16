#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 100005;
int n, k;
int a[MAXN];
int dp[2][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int max_val = a[0];
    int min_val = a[0];
    dp[0][0] = a[0];

    for (int i = 1; i < n; ++i) {
        max_val = max(max_val, a[i]);
        min_val = min(min_val, a[i]);

        dp[0][i] = min(dp[0][i - 1], a[i]);
    }

    dp[1][n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        dp[1][i] = min(dp[1][i + 1], a[i]);
    }

    /*
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", dp[k][i]);
        }
        printf("\n");
    }
    */

    if (k > 2) {
        printf("%d\n", max_val);
    } else if (k == 2) {
        int ans = max(a[0], a[n - 1]);
        for (int i = 1; i < n - 1; ++i) {
            ans = max(ans, max(dp[0][i], dp[1][i + 1]));
        }

        printf("%d\n", ans);
    } else {
        printf("%d\n", min_val);
    }

    return 0;
}
