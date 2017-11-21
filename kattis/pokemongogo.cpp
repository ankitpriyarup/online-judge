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

constexpr int MAXN = 21;
int n;

vector<string> by_loc[MAXN];
vector<string> all_pkmn;
int x[MAXN], y[MAXN];
int dp[1 << MAXN][MAXN];
int pkmn_masks[MAXN];
int locs = 0;

inline int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    string name;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> name;

        by_loc[i].push_back(name);
        all_pkmn.push_back(name);

        dp[1 << i][i] = dist(0, 0, x[i], y[i]);
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (dp[mask][i] == -1) continue;

            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue;

                int new_mask = mask | (1 << j);
                int new_cost = dp[mask][i] + dist(x[i], y[i], x[j], y[j]);

                dp[new_mask][j] = dp[new_mask][j] == -1 ? new_cost : min(dp[new_mask][j], new_cost);
            }
        }
    }

    sort(begin(all_pkmn), end(all_pkmn));
    all_pkmn.erase(unique(begin(all_pkmn), end(all_pkmn)), end(all_pkmn));

    for (int i = 0; i < n; ++i) {
        for (string name : by_loc[i]) {
            int ind = lower_bound(begin(all_pkmn), end(all_pkmn), name) - begin(all_pkmn);
            pkmn_masks[i] |= (1 << ind);
        }
    }

    int ans = 1e9;
    int target_pkmn = (1 << (all_pkmn.size())) - 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int group_mask = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i))
                group_mask |= pkmn_masks[i];
        }

        if (group_mask != target_pkmn)
            continue;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i))
                ans = min(ans, dp[mask][i] + dp[1 << i][i]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
