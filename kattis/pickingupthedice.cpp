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

using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

vector<ull> ways;
vector<vector<ull>> dp;

ld best_prob = 0.0;
int ans = 0;

void dfs(int cur, int goal, vector<int>& freq, int die, int rerolled) {
    if (die == 7) {
        int want = goal - cur;
        if (want < rerolled or 6 * rerolled < want) {
            return;
        }

        ull num = dp[rerolled][want];
        ld prob = static_cast<ld>(num) / ways[rerolled];
        if (prob > best_prob) {
            best_prob = prob;
            ans = rerolled;
        }

        return;
    }

    for (int drop = 0; drop <= freq[die]; ++drop) {
        dfs(cur - drop * die, goal, freq, die + 1, rerolled + drop);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, t;
    scanf(" %d %d", &k, &t);
    ways.resize(k + 1);
    ways[0] = 1;
    for (int i = 1; i <= k; ++i) {
        ways[i] = ways[i - 1] * 6ULL;
    }
    // dp[i][j] / ways[i] = prob of rolling sum j using i dice
    dp.assign(k + 1, vector<ull>(6 * k + 1, 0ULL));
    for (int j = 1; j <= 6; ++j) {
        dp[1][j] = 1ULL;
    }

    for (int i = 2; i <= k; ++i) {
        for (int j = 1; j <= 6 * k; ++j) {
            for (int d = 1; d <= min(j, 6); ++d) {
                dp[i][j] += dp[i - 1][j - d];
            }
        }
    }

    vector<int> freq(7, 0);
    int x;
    int tot = 0;
    for (int i = 0; i < k; ++i) {
        scanf(" %d", &x);
        ++freq[x];
        tot += x;
    }

    if (t == tot) {
        printf("%d\n", 0);
        return 0;
    }

    dfs(tot, t, freq, 1, 0);

    printf("%d\n", ans);
    
    return 0;
}
