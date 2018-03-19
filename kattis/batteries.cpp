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

constexpr int MAXN = 4800;
constexpr int INF = 1e9 + 7;
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    dp[0] = dp[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        dp[i] = INF;
        for (int j = 1; j < i; ++j)
            dp[i] = min(dp[i], 1 + max(j - 1, dp[i - j]));
    }

    int n;
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        printf("%d\n", dp[n]);
    }
    
    return 0;
}
