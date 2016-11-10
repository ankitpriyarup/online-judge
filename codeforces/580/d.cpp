#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int n, m, k;
long long satisfaction[20];
long long dp[(1 << 18)][20];
long long combo[20][20];

int main() {
    memset(dp, 0, sizeof(dp));
    memset(combo, 0, sizeof(combo));
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> satisfaction[i];
    }

    int x, y, c;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y >> c;
        --x; --y;
        combo[x][y] = c;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[(1 << i)][i] = satisfaction[i];
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int last_dish = 0; last_dish < n; ++last_dish) {
            if (!(mask & (1 << last_dish))) {
                continue;
            }

            for (int next_dish = 0; next_dish < n; ++next_dish) {
                int new_mask = mask | (1 << next_dish);
                if (new_mask != mask) {
                    dp[new_mask][next_dish] = max(
                            dp[new_mask][next_dish],
                            dp[mask][last_dish] + satisfaction[next_dish] + combo[last_dish][next_dish]);
                }
            }

            if (__builtin_popcount(mask) == m) {
                ans = max(ans, dp[mask][last_dish]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
