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

constexpr int MAXN = 505;
int n, b, mod;
int a[MAXN];
int dp[2][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    scanf(" %d %d %d %d", &n, &m, &b, &mod);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
    }

    dp[0][0][0] = 1;
    int idx = 0;
    for (int i = 0; i < n; ++i, idx ^= 1) {
        memset(dp[idx ^ 1], 0, sizeof(dp[idx ^ 1]));

        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= b; ++k) {
                // move to next guy
                dp[idx ^ 1][j][k] += dp[idx][j][k];
                dp[idx ^ 1][j][k] %= mod;

                // give new line
                if (j + 1 <= m and k + a[i] <= b) {
                    dp[idx][j + 1][k + a[i]] += dp[idx][j][k];
                    dp[idx][j + 1][k + a[i]] %= mod;
                }
            }
        }
    }

    int ans = 0;
    for (int k = 0; k <= b; ++k) {
        ans += dp[idx][m][k];
        ans %= mod;
    }
    cout << ans << '\n';
    
    return 0;
}
