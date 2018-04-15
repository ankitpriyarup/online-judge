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

constexpr int MAXN = 2002;
constexpr int MOD = 1e9 + 7;
int n;
char s[MAXN];
int dp[MAXN][MAXN][2];

int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

int solve(int a, int b, bool taken) {
    if (a == b) {
        return 1 + taken;
    }

    if (a > b)
        return taken;

    int& res = dp[a][b][taken];
    if (res != -1)
        return res;

    res = 0;
    if (s[a] == s[b]) {
        res = sum(res, solve(a + 1, b - 1, 1));
    }

    res = sum(res, solve(a + 1, b, taken));
    res = sum(res, solve(a, b - 1, taken));
    res = sum(res, MOD - solve(a + 1, b - 1, taken));

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%s", s);
        n = strlen(s);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, n - 1, 0));
    }
    
    return 0;
}
