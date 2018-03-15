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

constexpr int MAXT = 102;
int k, t, p, q;
int a[MAXT][4];
int pred[MAXT];
ld dp[MAXT][MAXT];

ld wins(int person, int rd) {
    ld rd1 = a[rd][person] / static_cast<ld>(a[rd][person] + a[rd][person ^ 1]);
    ld ans = 0.0;
    for (int x = 0; x <= 1; ++x) {
        int opp = person ^ 2 ^ x;
        ld oppwin = a[rd][opp] / static_cast<ld>(a[rd][opp] + a[rd][opp ^ 1]);
        ld iwin = a[rd][person] / static_cast<ld>(a[rd][opp] + a[rd][person]);
        ans += rd1 * oppwin * iwin;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x1;
    scanf("%d %d %d %d %d", &k, &t, &p, &q, &x1);
    pred[1] = x1;
    for (int i = 2; i <= t; ++i) {
        pred[i] = (pred[i - 1] * p) % q;
    }

    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &a[i][j]);
        }

        pred[i] %= 4;
    }

    dp[0][0] = 1.0;

    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = 0.0;
            dp[i][j] += (1.0 - wins(pred[i], i)) * dp[i - 1][j];
            if (j) {
                dp[i][j] += wins(pred[i], i) * dp[i - 1][j - 1];
            }
        }
    }

    ld ans = 0.0L;
    for (int j = k; j <= t; ++j) {
        ans += dp[t][j];
    }

    printf("%.17Lf\n", ans);

    return 0;
}
