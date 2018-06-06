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

constexpr int MAXN = 10004;
constexpr int MAXB = 12;
constexpr int MOD = 1e9 + 7;
int n;
char b[MAXB];
int bits;
int dp[2][1 << MAXB];

int solve(int bad) {
    if (n < bits) {
        return 1 << n;
    }

    int cap = (1 << bits);
    for (int mask = 0; mask < cap; ++mask) {
        dp[0][mask] = 1;
    }
    dp[0][bad] = 0;

    for (int i = bits; i < n; ++i) {
        for (int mask = 0; mask < cap; ++mask) {
            int newmask = (mask << 1) & (cap - 1);
            for (int k = 0; k < 2; ++k) {
                dp[1][newmask | k] += dp[0][mask];
                if (dp[1][newmask | k] >= MOD)
                    dp[1][newmask | k] -= MOD;
            }
        }

        for (int mask = 0; mask < cap; ++mask) {
            dp[0][mask] = dp[1][mask];
            dp[1][mask] = 0;
        }

        dp[0][bad] = 0;
    }

    int res = 0;
    for (int mask = 0; mask < cap; ++mask) {
        res += dp[0][mask];
        if (res >= MOD)
            res -= MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %s", &n, b);
        bits = strlen(b);
        int x = 0;
        for (int i = 0; i < bits; ++i) {
            x <<= 1;
            x |= (b[i] == '1');
        }

        printf("%d\n", solve(x));
    }

    return 0;
}
