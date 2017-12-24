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

constexpr int MAXN = 42;
constexpr int MAXH = 1003;
int n;
int a[MAXN];
int dp[MAXN][MAXH];
int f[MAXN][MAXH];
char out[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d\n", a + i);
        }

        memset(dp, -1, sizeof(dp));
        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int h = 0; h < MAXH; ++h) {
                if (h + a[i] < MAXH and dp[i + 1][h + a[i]] != -1) {
                    dp[i][h] = max(h, dp[i + 1][h + a[i]]);
                    f[i][h] = 1;
                }

                if (h - a[i] >= 0 and dp[i + 1][h - a[i]] != -1 and (dp[i][h] == -1 or dp[i][h] > dp[i + 1][h - a[i]])) {
                    dp[i][h] = max(h, dp[i + 1][h - a[i]]);
                    f[i][h] = -1;
                }
            }
        }

        if (dp[0][0] == -1) {
            printf("%s\n", "IMPOSSIBLE");
        } else {
            int x = 0;
            for (int i = 0; i < n; ++i) {
                out[i] = f[i][x] == 1 ? 'U' : 'D';
                x += f[i][x] * a[i];
            }
            out[n] = '\0';
            printf("%s\n", out);
        }
    }

    return 0;
}
