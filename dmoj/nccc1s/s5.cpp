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

constexpr int MAXN = 50;
constexpr int INF = 1e9;
int n;
char s[MAXN];
int dp[MAXN][2][2];

// l, r 
int solve(int l, bool left_make, bool right_get) {
    int r = n - l - 1;
    if (l == r) {
        int x = s[l] - '0' + right_get;
        if (left_make) {
            return 10 - x;
        } else {
            return x == 10 ? INF : 0;
        }
    }

    if (l > r) {
        return (left_make == right_get) ? 0 : INF;
    }

    if (dp[l][left_make][right_get] != -1)
        return dp[l][left_make][right_get];

    int res = INF;
    for (int left_rot = 0; left_rot <= 10; ++left_rot) {
        for (int right_rot = 0; right_rot <= 10; ++right_rot) {
            int left_dig = (s[l] - '0' + left_rot) % 10;
            bool did_left = (s[l] - '0' + left_rot) >= 10;

            int right_dig = (s[r] - '0' + right_get + right_rot) % 10;
            bool did_right = (s[r] - '0' + right_get + right_rot) >= 10;

            if ((left_dig == right_dig) and (left_make == did_left)) {
                res = min(res, left_rot + right_rot + solve(l + 1, false, did_right));

                if (left_rot > 0)
                    res = min(res, left_rot - 1 + right_rot + solve(l + 1, true, did_right));
            }
        }
    }

    return dp[l][left_make][right_get] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", min(solve(0, false, false), solve(0, true, false)));

    return 0;
}
