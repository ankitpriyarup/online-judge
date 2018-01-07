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
constexpr int MAXM = 20;
constexpr int MOD = 10000;

constexpr char pattern[] = "welcome to code jam";
const int m = strlen(pattern);

int n;
char s[MAXN];
int dp[MAXN][MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d\n", &T);
    int tc = 1;

    while (T-- > 0) {
        gets(s);
        n = strlen(s);

        memset(dp, 0, sizeof(dp));
        if (s[0] == 'w')
            dp[0][0] = 1;

        /*
        for (int j = 0; j < m; ++j) {
            printf("%d ", dp[0][j]);
        }
        printf("\n");
        */

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i] == pattern[j]) {
                    dp[i][j] += j ? dp[i - 1][j - 1] : 1;
                    dp[i][j] %= MOD;
                }

                // printf("%d ", dp[i][j]);
            }
            // printf("\n");
        }

        int ans = dp[n - 1][m - 1];
        printf("Case #%d: %04d\n", tc++, ans);
    }
    
    return 0;
}
