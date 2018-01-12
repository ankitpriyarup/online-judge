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

// ONLY 80% CREDIT

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 1003;
int n, k, pos;

// prob of winning game of i people in position j
ld dp[MAXN][MAXN];

ld prob_dies(int len, int pos) {
    ld num = (len + k) / len;
    num *= (pos - 1);
    num += min(pos - 1, k % len);
    /*
    for (int i = 1; i < pos; ++i) {
        num += (len + k) / len;
        num += (i - 1) < (k % len);
    }
    */

    return 1.0 * num / (len + k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &k, &pos);
    dp[1][1] = 1.0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            // someone before you dies
            dp[i][j] += (prob_dies(i, j)) * dp[i - 1][j - 1];
            // someone after you dies
            dp[i][j] += (1.0 - prob_dies(i, j + 1)) * dp[i - 1][j];
        }
    }

    printf("%.12Lf\n", dp[n][pos]);
    return 0;
}
