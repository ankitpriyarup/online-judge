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

constexpr int MAXN = 503;
constexpr int INF = 1e9 + 7;
int n, m;
char grid[MAXN][MAXN];
vector<int> pos[MAXN];

// best time for row i if you can delete at most c things
int trans[MAXN][MAXN];

int dp[MAXN][MAXN];

void build_trans(int i) {
    int c = pos[i].size();
    for (int a = 0; a < MAXN; ++a) {
        trans[i][a] = INF;
    }

    for (int a = 0; a < c; ++a) {
        for (int b = a; b < c; ++b) {
            int time = pos[i][b] + 1 - pos[i][a];
            int del = a + (c - 1 - b);
            trans[i][del] = min(trans[i][del], time);
        }
    }
}

int solve(int i, int k) {
    if (i >= n) return 0;

    int& res = dp[i][k];
    if (res != -1)
        return res;

    if (pos[i].empty()) {
        res = solve(i + 1, k);
        return res;
    }

    res = INF;
    int c = pos[i].size();
    if (c <= k) {
        res = solve(i + 1, k - c);
    }

    for (int d = 0; d < min(k + 1, c); ++d) {
        res = min(res, trans[i][d] + solve(i + 1, k - d));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1')
                pos[i].push_back(j);
        }

        build_trans(i);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, k));

    return 0;
}
