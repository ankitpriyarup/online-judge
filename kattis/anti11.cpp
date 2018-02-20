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

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 11111;
ll dp[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = dp[i - 1][0];
    }

    int T;
    scanf("%d", &T);

    int n;
    while (T-- > 0) {
        scanf("%d", &n);
        printf("%lld\n", (dp[n][0] + dp[n][1]) % MOD);
    }

    return 0;
}
