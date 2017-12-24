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

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 103;
int dp[2][MAXN][MAXN];

/*
BWBW
WBWB
BWBW
*/

int score(int height, bool white_top) {
    if (height & 1) {
        return white_top ? -1 : 1;
    } else {
        return 0;
    }
}

int get_flip(int height, int cur_white) {
    if (height & 1) {
        return cur_white;
    } else {
        return !cur_white;
    }
}

int solve(int white_tl, int height, int width) {
    if (width == 0) return 0;

    int& ret = dp[white_tl][height][width];
    if (ret != -1) return ret;

    ret = -100;
    int cur_white = white_tl;
    int cur_score = 0;
    for (int i = 0; i < width; ++i) {
        cur_score += score(height, cur_white);
        cur_white = !cur_white;

        ret = max(ret, cur_score - solve(get_flip(height, cur_white), width - i - 1, height));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, n, m));

    return 0;
}
