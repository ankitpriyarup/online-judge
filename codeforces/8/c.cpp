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

constexpr int MAXN = 24;
constexpr int INF = 1e9 + 7;
int xs, ys;
int n;
int x[MAXN], y[MAXN];
int dist[MAXN][MAXN];
int dp[1 << MAXN];
int previous[1 << MAXN][2];

int solve(int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != -1) return dp[mask];

    int res = INF;
    int last = n - 1;
    while ((mask & (1 << last)) == 0)
        --last;

    res = dist[last][last] + solve(mask ^ (1 << last));
    previous[mask][0] = previous[mask][1] = last;

    for (int j = 0; j < last; ++j) {
        if (mask & (1 << j)) {
            int score = dist[last][j] + solve(mask ^ (1 << last) ^ (1 << j));
            if (score < res) {
                res = score;
                previous[mask][1] = j;
            }
        }
    }

    return dp[mask] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &xs, &ys);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, y + i);
        int xd = x[i] - xs;
        int yd = y[i] - ys;
        dist[i][i] = (xd * xd + yd * yd) << 1;

        for (int j = 0; j < i; ++j) {
            int between = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            dist[i][j] = dist[j][i] = ((dist[i][i] + dist[j][j]) >> 1) + between;
        }
    }

    memset(dp, -1, sizeof(dp));

    int mask = (1 << n) - 1;
    printf("%d\n", solve(mask));
    vector<int> stk;
    stk.push_back(0);
    int x, y;
    while (mask) {
        x = previous[mask][0];
        y = previous[mask][1];
        mask ^= (1 << x);
        stk.push_back(x + 1);
        if (x != y) {
            mask ^= (1 << y);
            stk.push_back(y + 1);
        }

        stk.push_back(0);
    }

    while (!stk.empty()) {
        printf("%d ", stk.back());
        stk.pop_back();
    }
    printf("\n");

    return 0;
}
