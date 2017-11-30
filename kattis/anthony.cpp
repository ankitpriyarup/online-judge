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

constexpr int MAXN = 1003;
ld p[2 * MAXN];
ld dp[MAXN][2 * MAXN];

ld solve(int n, int m, int round) {
    // printf("Solve(%d, %d, %d)\n", n, m, round);
    if (n == 0) return 0.0;
    if (m == 0) return 1.0;

    if (dp[n][round] > -0.5) {
        return dp[n][round];
    }

    return dp[n][round] = p[round] * solve(n, m - 1, round + 1) 
                        + (1 - p[round]) * solve(n - 1, m, round + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m - 1; ++i) {
        scanf("%Lf", p + i);
        for (int j = 0; j <= n; ++j)
            dp[j][i] = -1.0;
    }

    ld ret = solve(n, m, 0);
    printf("%.12Lf\n", ret);

    return 0;
}
