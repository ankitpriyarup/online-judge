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

constexpr int MAXN = 2003;
constexpr int INF = 1e9 + 7;
int n;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
vector<pii> tree[MAXN];
bool vis[MAXN];
int uf[MAXN];

void dfs(int src, int u, int dist) {
    if (vis[u]) return;

    vis[u] = true;
    b[src][u] = dist;
    for (pii e : tree[u]) {
        dfs(src, e.first, dist + e.second);
    }
}

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

bool merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;

    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    vector<pair<int, pii> > edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);

            if (i < j)
                edges.push_back({a[i][j], {i, j}});
        }

        uf[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                printf("NO\n");
                return 0;
            }
        }
    }

    sort(begin(edges), end(edges));

    for (auto& edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        if (merge(u, v)) {
            tree[u].push_back({v, edge.first});
            tree[v].push_back({u, edge.first});
        }
    }

    for (int i = 0; i < n; ++i) {
        memset(vis, 0, sizeof(vis));
        dfs(i, i, 0);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[i][j]) {
                printf("NO\n");
                return 0;
            }

            if (i != j and b[i][j] <= 0) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    return 0;
}
