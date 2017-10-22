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

constexpr int LOGN = 15;
constexpr int MAXN = 10004;

int k, n, m;
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d %d", &k, &m, &n);
        for (int i = 0; i <= n; ++i) {
            dp[i] = 1;
        }

        int val = m;
        int ans = 1;
        for (int j = 1; j < LOGN; ++j, val *= m) {
            if (val > n) break;

            for (int i = 0; i <= n; ++i) {
                if (i + val <= n) {
                    dp[i + val] += dp[i];
                }
            }

            ans = dp[n];
        }

        printf("%d %d\n", k, ans);
    }

    return 0;
}
