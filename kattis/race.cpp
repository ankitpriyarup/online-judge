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

constexpr int MAXN = 23;
int n, T;
int dp[1 << (MAXN - 2)][MAXN];
int p[MAXN], t[MAXN], d[MAXN];
int a[MAXN][MAXN];

int score(int mask) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i))
            ans += p[i];
    }

    return ans;
}

int cmp_mask(int a, int b) {
    for (int i = 0; i < n; ++i) {
        bool a_has = (a & (1 << i)) > 0;
        bool b_has = (b & (1 << i)) > 0;
        if (a_has and !b_has)
            return true;
        if (b_has and !a_has)
            return false;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &T);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d %d", &p[i], &t[i], &d[i]);
    }

    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < n + 2; ++j) {
            scanf(" %d", &a[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][n] = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i <= n; ++i) {
            if (dp[mask][i] == -1) continue;
            for (int j = 0; j < n; ++j) {
                if ((mask & (1 << j)) > 0) continue;

                // ensure you can get to j
                int fin_time = dp[mask][i] + a[i][j] + t[j];
                if (d[j] != -1 and fin_time > d[j])
                    continue;

                int new_mask = mask | (1 << j);
                dp[new_mask][j] = dp[new_mask][j] == -1 ? fin_time : min(dp[new_mask][j], fin_time);
            }
        }
    }

    int best = 0;
    int ans_mask = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int pts = score(mask);
        int time = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            if (dp[mask][i] == -1) continue;
            if ((mask & (1 << i)) == 0) continue;
            time = min(time, dp[mask][i] + a[i][n + 1]);
        }
        if (time > T) continue;

        if (pts < best) continue;
        else if (pts > best) {
            best = pts;
            ans_mask = mask;
        } else {
            ans_mask = cmp_mask(ans_mask, mask) ? ans_mask : mask;
        }
    }

    printf("%d\n", best);
    for (int i = 0; i < n; ++i) {
        if (ans_mask & (1 << i)) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}
