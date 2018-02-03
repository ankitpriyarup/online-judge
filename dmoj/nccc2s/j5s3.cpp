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

constexpr int MAXN = 40;
int n, m;
char grid[MAXN][MAXN];
int bot_blue[MAXN], top_red[MAXN];
ll dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    for (int j = 0; j < m; ++j) {
        bot_blue[j] = -1;
        top_red[j] = n;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == 'B')
                bot_blue[j] = i;

            if (grid[i][j] == 'R')
                top_red[j] = min(top_red[j], i);
        }

        if (bot_blue[j] >= top_red[j]) {
            printf("%d\n", 0);
            return 0;
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = bot_blue[0] < i and i <= top_red[0] ? 1LL : 0LL;
    }

    for (int j = 1; j < m; ++j) {
        for (int i = 0; i <= n; ++i) {
            dp[j][i] = 0;

            if (bot_blue[j] < i and i <= top_red[j]) {
                for (int k = i; k <= n; ++k) {
                    dp[j][i] += dp[j - 1][k];
                }
            }
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%lld ", dp[j][i]);
        }
        printf("\n");
    }
    */

    ll res = 0LL;
    for (int i = 0; i <= n; ++i)
        res += dp[m - 1][i];

    printf("%lld\n", res);

    return 0;
}
