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

constexpr int MAXN = 200005;
constexpr int MAXM = 1003;
constexpr int MOD = 1e9 + 7;

int n, m;

int dp[MAXN][MAXM];
int is_red[MAXN];
vector<int> tree[MAXN];
int timer = 0;
int tin[MAXN], tout[MAXN], rtin[MAXN];

void dfs(int u) {
    tin[u] = timer++;
    rtin[tin[u]] = u;
    for (int v : tree[u])
        dfs(v);
    tout[u] = timer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    int par;
    for (int i = 1; i < n; ++i) {
        scanf(" %d", &par);
        --par;
        tree[par].push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        scanf(" %d", &par);
        is_red[par - 1] = true;
    }

    dfs(0);
    // dp[i][j] number of subsets of nodes [i..] that have exactly j red nodes
    // where no chosen node is an ancestor of another node
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        int u = rtin[i];
        for (int j = 0; j <= m; ++j) {
            // don't choose this node
            dp[i][j] = dp[i + 1][j];
            if (is_red[u]) {
                if (j)
                    dp[i][j] += dp[tout[u]][j - 1];
            } else {
                dp[i][j] += dp[tout[u]][j];
            }

            if (dp[i][j] >= MOD)
                dp[i][j] -= MOD;
        }
    }

    for (int j = 0; j <= m; ++j) {
        printf("%d\n", dp[0][j]);
    }
    return 0;
}
