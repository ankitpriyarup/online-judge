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
constexpr int LOGN = 20;

int n;
vector<int> tree[MAXN];
int st[LOGN][MAXN];
int depth[MAXN];

void dfs(int u, int par) {
    for (int v : tree[u]) {
        if (v == par) continue;
        depth[v] = depth[u] + 1;
        st[0][v] = u;
        dfs(v, u);
    }
}

void gen_st() {
    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (st[j][i] != -1) {
                st[j + 1][i] = st[j][st[j][i]];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    if (depth[v] > depth[u]) {
        for (int j = LOGN - 1; j >= 0; --j) {
            if (depth[v] - (1 << j) >= depth[u]) {
                v = st[j][v];
            }
        }
    }

    if (u == v) return u;
    for (int j = LOGN - 1; j >= 0; --j) {
        if (st[j][u] != st[j][v]) {
            u = st[j][u];
            v = st[j][v];
        }
    }

    return st[0][u];
}

int dist(int u, int v) {
    int ans = depth[u] + depth[v] - 2 * depth[lca(u, v)] + 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(st, -1, sizeof(st));
    depth[1] = 0;
    dfs(1, -1);
    gen_st();

    ll ans = 0LL;
    for (int u = 1; u <= n; ++u) {
        for (int v = 2 * u; v <= n; v += u) {
            ans += dist(u, v);
        }
    }

    printf("%lld\n", ans);
    
    return 0;
}
