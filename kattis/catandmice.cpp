#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 20;
constexpr ld INF = 1e18;
constexpr ld EPS = 1e-8;
constexpr int ITER = 200;

int n;
int x[MAXN], y[MAXN], die[MAXN];

// dp(mask, i) = min time to eat all of mask ending at i
ld dp[1 << MAXN][MAXN];

ld sp_factor[MAXN];

ld dist(int x1, int y1, int m_ind, ld time, ld speed) {
    ld xd = x1 - x[m_ind];
    ld yd = y1 - y[m_ind];

    ld d = sqrt(xd * xd + yd * yd);
    ld end_time = time + d / speed;

    if (end_time <= die[m_ind] + EPS) {
        return end_time;
    } else {
        return INF;
    }
}

bool solve(ld init_speed) {
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            dp[mask][i] = INF;
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = dist(0, 0, i, 0.0L, init_speed);
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        int bits = __builtin_popcount(mask);
        ld speed = init_speed * sp_factor[bits];

        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }

            for (int j = 0; j < n; ++j) {
                if ((mask & (1 << j)) != 0) {
                    continue;
                }

                // consider going from i to j
                int new_mask = mask | (1 << j);

                dp[new_mask][j] = min(dp[new_mask][j], dist(x[i], y[i], j, dp[mask][i], speed));
            }
        }
    }

    int end_mask = (1 << n) - 1;
    ld ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[end_mask][i]);
    }

    return ans + EPS < INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", x + i, y + i, die + i);
    }

    scanf("%Lf", &sp_factor[1]);
    for (int i = 2; i < MAXN; ++i) {
        sp_factor[i] = sp_factor[i - 1] * sp_factor[1];
    }

    ld lo = 0.0L;
    ld hi = INF;
    for (int iter = 0; iter < ITER; ++iter) {
        ld mid = (lo + hi) / 2.0L;
        if (solve(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%.12Lf\n", (lo + hi) / 2.0L);

    return 0;
}
