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

constexpr int MAXN = 100005;

int n;
int p[MAXN];
int edges[MAXN][2];
int expiry[MAXN];
vector<pii> tree[MAXN];
int par[MAXN];
int pid[MAXN];
int sz[MAXN];
int depth[MAXN];
int chain[MAXN];
int home[MAXN];

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto& e : tree[u]) {
        int v = e.first;
        if (v == p) continue;

        par[v] = u;
        pid[v] = e.second;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void heli(int u, int p, int c, int h) {
    chain[u] = c;
    home[u] = h++;
    int big = -1;
    for (auto& e : tree[u]) {
        int v = e.first;
        if (v == p) continue;
        if (big == -1 or sz[v] > sz[big]) big = v;
    }
    if (big == -1) return;

    heli(big, u, c, h);
    h += sz[big];
    for (auto& e : tree[u]) {
        int v = e.first;
        if (v == p or v == big) continue;
        heli(v, u, v, h);
        h += sz[v];
    }
}

int lca(int u, int v) {
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] > depth[chain[v]]) {
            swap(u, v);
        }
        v = par[chain[v]];
    }

    return depth[u] < depth[v] ? u : v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, r;
    cin >> n >> q >> r;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        expiry[i] = 1e9 + 7;
    }

    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        --u; --v;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    int x, y;
    for (int i = 0; i < r; ++i) {
        cin >> x >> y;
        --x;
        expiry[y] = x;
    }

    for (int i = 1; i < n; ++i) {
        u = edges[i][0];
        v = edges[i][1];
        tree[u].emplace_back(v, i);
        tree[v].emplace_back(u, i);
    }

    par[0] = -1;
    dfs(0, -1);
    heli(0, -1, 0, 0);

    int k;
    for (int qq = 0; qq < q; ++qq) {
        cin >> u >> v >> k;
        --u; --v;
        int l = lca(u, v);
        int node = u;
        int ans = -1;
        bool broken = false;
        // cout << "*** NEW QUERY ***\n";
        while (!broken and node != l) {
            // cout << "At node " << node << '\n';
            if (ans == -1 and p[node] >= k) {
                ans = node;
            }
            broken |= expiry[pid[node]] < qq;
            node = par[node];
        }
        if (ans == -1 and p[l] >= k) {
            ans = l;
        }
        // cout << "At node " << l << '\n';
        node = v;
        bool set = ans == -1;
        while (!broken and node != l) {
            // cout << "At node (rev) " << node << '\n';
            if (set and p[node] >= k) {
                ans = node;
            }

            broken |= expiry[pid[node]] < qq;
            node = par[node];
        }
        if (broken)
            ans = -1;

        cout << (ans < 0 ? -1 : ans + 1) << '\n';
    }

    return 0;
}
