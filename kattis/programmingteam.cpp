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
using ld = double;
using pii = pair<int, int>;

constexpr int MAXN = 2505;
constexpr ld INF = 1e16;
int n, k;
vector<int> tree[MAXN];
int sz[MAXN];
int s[MAXN], p[MAXN];

// best sum from root i including u
ld dp[MAXN][MAXN];

void dfs_sz(int u) {
    sz[u] = 1;
    for (int v : tree[u]) {
        dfs_sz(v);
        sz[u] += sz[v];
    }
}

void compute(int u) {
    for (int i = 2; i <= min(sz[u], k + 1); ++i)
        dp[u][i] = -INF;

    int cur = 1;
    for (int v : tree[u]) {
        compute(v);

        for (int i = min(cur, min(sz[u], k + 1)); i > 0; --i) {
            for (int j = min(k + 1 - i, min(sz[v], k + 1)); j > 0; --j) {
                dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j]);
            }
        }

        cur += min(k + 1, sz[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &k, &n);
    int r;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &s[i], &p[i], &r);
        tree[r].push_back(i);
    }

    dfs_sz(0);

    ld lo = 0.0;
    ld hi = 100000.0;
    constexpr ld EPS = 1e-5;

    for (int iter = 0; hi - lo > EPS and iter < 40; ++iter) {
        ld mid = (lo + hi) / 2.0;

        for (int i = 1; i <= n; ++i) {
            dp[i][1] = p[i] - mid * s[i];
        }

        compute(0);

        if (dp[0][k + 1] > EPS) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%.3lf\n", (lo + hi) / 2.0);

    return 0;
}
