#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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

constexpr int MAXN = 2003;
int n;
int v[MAXN], w[MAXN];
int dp[MAXN][MAXN];

// 0 means don't take (i - 1, cap), 1 means take (i - 1, cap - w[i])
bool path[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double real_cap;
    while (scanf("%lf %d", &real_cap, &n) == 2) {
        int cap = real_cap;
        memset(dp, 0, sizeof(dp));
        memset(path, false, sizeof(path));

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", v + i, w + i);
            for (int j = 0; j <= cap; ++j) {
                dp[i][j] = dp[i - 1][j];

                if (w[i] <= j and v[i] + dp[i - 1][j - w[i]] > dp[i][j]) {
                    dp[i][j] = v[i] + dp[i - 1][j - w[i]];
                    path[i][j] = true;
                }
            }
        }

        int pos = cap;
        vector<int> stk;
        for (int row = n; row; --row) {
            if (path[row][pos]) {
                stk.push_back(row);
                pos -= w[row];
            }
        }

        printf("%lu\n", stk.size());
        for (int x : stk) {
            printf("%d ", x - 1);
        }
        printf("\n");
    }

    return 0;
}
