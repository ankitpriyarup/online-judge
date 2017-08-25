#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAXN = 2003;
const int INF = 1e9;
const int MAXD = 22;

int n, d;
int a[MAXN];
int pref[MAXN];
int dp[MAXD][MAXN];

int cost(const int& x) {
    int ones = x % 10;
    if (ones < 5) {
        return x - ones;
    } else {
        return x - ones + 10;
    }
}

int main() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    pref[0] = 0;
    dp[0][0] = INF;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
        dp[0][i] = cost(pref[i]);
    }

    for (int i = 1; i <= d; ++i) {
        dp[i][0] = INF;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = INF;
            for (int k = 0; k <= n; ++k) {
                int sum = pref[j] - pref[k];
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost(sum)); 
            }
        }
    }

    printf("%d\n", dp[d][n]);

    return 0;
}
