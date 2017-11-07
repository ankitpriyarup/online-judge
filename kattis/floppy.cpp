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

constexpr int MAXT = 10004;
constexpr int MAXN = 102;
int t, n;
int a[MAXN], b[MAXN];
bool dp[2][MAXT];

bool solve() {
    scanf("%d %d", &t, &n);
    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= t; ++i) {
        dp[0][i] = true;
    }

    int row = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", a + i, b + i);
        int dur = b[i] - a[i];
        memset(dp[1 - row], false, sizeof(dp[1 - row]));

        for (int j = 0; j <= t; ++j) {
            if (j - dur >= 0)
                dp[1 - row][j - dur] |= dp[row][j];

            if (j + dur <= t)
                dp[1 - row][j + dur] |= dp[row][j];
        }


        row = 1 - row;
    }

    for (int j = 0; j <= t; ++j) {
        if (dp[row][j]) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);

    bool safe = true;
    while (T-- > 0) {
        safe &= solve();
    }

    printf("%s\n", safe ? "possible" : "impossible");
    
    return 0;
}
