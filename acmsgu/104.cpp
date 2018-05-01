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

constexpr int MAXN = 111;
constexpr int INF = 1e9;
int n, m;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
bool take[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %d", &a[i][j]);
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = -INF;
        }
    }

    for (int j = 0; j <= m; ++j)
        dp[0][j] = 0;
    

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j - 1] > dp[i][j]) {
                take[i][j] = 0;
                dp[i][j] = dp[i][j - 1];
            }
            if (a[i][j] + dp[i - 1][j - 1] > dp[i][j]) {
                take[i][j] = 1;
                dp[i][j] = a[i][j] + dp[i - 1][j - 1];
            }
        }
    }

    printf("%d\n", dp[n][m]);
    int i = n;
    int j = m;
    vector<int> res;
    while (i > 0 and j > 0) {
        if (take[i][j] == 1) {
            res.push_back(j);
            --i; --j;
        } else {
            --j;
        }
    }

    reverse(begin(res), end(res));
    for (int x : res)
        printf("%d ", x);

    return 0;
}
