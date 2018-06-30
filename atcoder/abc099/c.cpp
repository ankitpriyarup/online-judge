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

constexpr int MAXN = 1e6 + 6;
constexpr int INF = 1e9 + 7;
int n;
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i <= n; ++i) {
        dp[i] = INF;
    }

    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; i + j <= n; j *= 6) {
            dp[i + j] = min(dp[i + j], 1 + dp[i]);
        }

        for (int j = 1; i + j <= n; j *= 9) {
            dp[i + j] = min(dp[i + j], 1 + dp[i]);
        }
    }

    printf("%d\n", dp[n]);
    
    return 0;
}
