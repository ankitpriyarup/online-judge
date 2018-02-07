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


constexpr int MAXN = 1003;
constexpr int MAXC = 10004;
int n;
ll w, b, x;
int c[MAXN];
ll cost[MAXN];

// max mana to end at tree i and have j birds
ll dp[MAXN][MAXC];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> w >> b >> x;
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    for (int i = 0; i < n; ++i)
        cin >> cost[i];

    memset(dp, -1, sizeof(dp));
    dp[0][0] = w;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MAXC and dp[i][j] > -1; ++j) {
            for (ll k = 0; k <= c[i] and dp[i][j] - cost[i] * k >= 0; ++k) {
                dp[i + 1][j + k] = max(dp[i + 1][j + k], min(w + (j + k) * b, dp[i][j] + x - cost[i] * k));
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < MAXC; ++j) {
        if (dp[n][j] != -1)
            ans = max(ans, j);
    }

    cout << ans << '\n';

    return 0;
}
