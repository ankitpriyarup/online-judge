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

constexpr int MAXN = 2003;
constexpr int MOD = 1e9 + 7;

// stressfree
int a, b;
bool done[2][MAXN][MAXN];
int dp[2][MAXN][MAXN];

inline int sum(const int& a, const int& b) {
    int c = a + b;
    while (c >= MOD)
        c -= MOD;
    return c;
}

int solve1(int x, int y) {
    if (x == a and y == b) {
        return 1;
    }

    if (done[0][x][y])
        return dp[0][x][y];

    int res = 0;
    if (x < a) {
        res = sum(res, solve1(x + 1, y));
    }
    if (y < b and y + 1 < x) {
        res = sum(res, solve1(x, y + 1));
    }

    done[0][x][y] = true;
    return dp[0][x][y] = res;
}

int solve2(int x, int y) {
    if (x == a and y == b) {
        return 1;
    }

    if (done[1][x][y])
        return dp[1][x][y];

    int res = 0;
    if (x < a and (x + 1 <= y or y == b)) {
        res = sum(res, solve2(x + 1, y));
    }
    if (y < b)
        res = sum(res, solve2(x, y + 1));

    done[1][x][y] = true;
    return dp[1][x][y] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int tc = 1;
    while (T-- > 0) {
        scanf("%d-%d\n", &a, &b);
        memset(done, false, sizeof(done));
        memset(dp, 0, sizeof(dp));

        int r1 = solve1(1, 0);
        int r2 = solve2(0, 0);

        printf("Case #%d: %d %d\n", tc++, r1, r2);
    }

    return 0;
}
