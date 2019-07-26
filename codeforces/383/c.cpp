#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 200005;
int n;
vector<int> tree[MAXN];
int a[MAXN];
int par[MAXN], depth[MAXN], sz[MAXN];
int timer = 0;
int tin[MAXN], tout[MAXN], nxt[MAXN];
int f_tree[2][MAXN];

int query(int k, int x) {
    int res = 0;
    for (x += 1; x > 0; x -= (x & -x)) {
        res += f_tree[k][x];
    }

    return res;
}

inline int query(int k, int l, int r) {
    return query(k, r) - query(k, l - 1);
}

void update(int k, int x, int v) {
    for (x += 1; x < MAXN; x += (x & -x)) {
        f_tree[k][x] += v;
    }
}

void dfs_sz(int u) {
    sz[u] = 1;
    for (int& v : tree[u]) {
        if (v == par[u]) continue;
        depth[v] = depth[u] + 1;
        par[v] = u;
        dfs_sz(v);
        sz[u] += sz[v];
        if (sz[v] > sz[tree[u][0]]) {
            swap(v, tree[u][0]);
        }
    }
}

void dfs_time(int u) {
    tin[u] = timer++;
    for (int v : tree[u]) {
        if (v == par[u]) continue;
        nxt[v] = (v == tree[u][0] ? nxt[u] : v);
        dfs_time(v);
    }
    tout[u] = timer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    par[0] = -1;
    dfs_sz(0);
    dfs_time(0);

    while (q-- > 0) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, val;
            cin >> u >> val;
            --u;

            update(depth[u] % 2, tin[u], val);
        } else {
            int u;
            cin >> u;
            --u;

            int ans = a[u];
            int k = depth[u] % 2;
            while (u >= 0) {
                ans += query(k, tin[nxt[u]], tin[u]) - query(1 - k, tin[nxt[u]], tin[u]);
                u = par[nxt[u]];
            }
            cout << ans << '\n';
        }
    }

    return 0;
}

