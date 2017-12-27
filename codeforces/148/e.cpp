#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 105;
constexpr int MAXM = 10004;
int dp[2][MAXM];
int cur[MAXM];
int a[MAXN];
int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);
    int k;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j) {
            scanf("%d", &a[j]);
            p[j] = p[j - 1] + a[j];
        }

        memset(cur, 0, sizeof(cur));
        cur[k] = p[k];
        for (int j1 = 0; j1 <= k; ++j1) {
            for (int j2 = k; j2 >= j1; --j2) {
                int val = p[j1] + (p[k] - p[j2]);
                int cost = j1 + (k - j2);

                cur[cost] = max(cur[cost], val);
            }
        }

        for (int c = 0; c <= m; ++c) {
            if (cur[c] > 0) {
                for (int j = c; j <= m; ++j) {
                    dp[1][j] = max(dp[1][j], dp[0][j - c] + cur[c]);
                }
            }
        }

        memcpy(dp[0], dp[1], sizeof(dp[1]));
    }

    printf("%d\n", dp[1][m]);

    return 0;
}
