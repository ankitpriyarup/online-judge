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

constexpr int MAXN = 5003;
constexpr int MOD = 1e9 + 7;
int n;
char prog[MAXN][5];
int dp[MAXN][MAXN];
int p[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", prog[i]);
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    p[0][0] = 1;

    int row = 1;
    for (int i = 1; i < n; ++i) {
        if (prog[i - 1][0] == 'f') {
            for (int d = 0; d < MAXN; ++d) {
                dp[i][d] = (dp[i][d] + dp[i - 1][d - 1]) % MOD;
            }
        } else {
            for (int d = 0; d < MAXN; ++d) {
                dp[i][d] = (dp[i][d] + p[i - 1][d]) % MOD;
            }
        }

        p[i][MAXN - 1] = dp[i][MAXN - 1];
        for (int j = MAXN - 2; j >= 0; --j) {
            p[i][j] = (p[i][j + 1] + dp[i][j]) % MOD;
        }

        /*
        for (int j = 0; j < 5; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
        */
    }

    printf("%d\n", p[n - 1][0]);

    return 0;
}
