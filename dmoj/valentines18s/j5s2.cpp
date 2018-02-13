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

constexpr int MAXN = 15;
constexpr int INF = 1e9;
int n, m;
int cost[MAXN];
int deal_cost[MAXN];
int deals[MAXN][MAXN];

map<pair<int, vector<int> >, int> memo;

int solve(int deal, const vector<int>& state) {
    auto key = make_pair(deal, state);
    if (memo.find(key) != end(memo))
        return memo[key];

    int res = INF;
    if (deal >= 0) {
        // try applying the deal
        int with_deal = deal_cost[deal];
        bool can_make = true;
        vector<int> next_state(begin(state), end(state));

        for (int i = 0; i < n; ++i) {
            next_state[i] -= deals[deal][i];
            if (next_state[i] < 0)
                can_make = false;
        }

        if (can_make) {
            res = min(res, deal_cost[deal] + solve(deal - 1, next_state));
        }

        res = min(res, solve(deal - 1, state));
    } else {
        // Just buy everything straight up
        int score = 0;
        for (int i = 0; i < n; ++i) {
            // printf("Flower %d cost %d state %d\n", i, cost[i], state[i]);
            score += cost[i] * state[i];
        }

        res = min(res, score);
    }

    /*
    printf("At deal: %d, state: ", deal);
    for (int x : state) {
        printf("%d ", x);
    }
    printf("; res: %d\n", res);
    */

    return memo[key] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cost[i]);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d", &deal_cost[i]);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &deals[i][j]);
        }
    }

    vector<int> state(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &state[i]);
    }

    int ans = solve(m - 1, state);

    printf("%d\n", ans);

    return 0;
}
