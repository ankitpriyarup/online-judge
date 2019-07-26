#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 100005;
constexpr int INF = 1e9 + 7;
int n;
vector<int> tree[MAXN];
int par[MAXN], depth[MAXN], sz[MAXN];
int timer = 0;
int tin[MAXN], tout[MAXN], nxt[MAXN];


int seg_tree[4 * MAXN], lazy[4 * MAXN];

void push(int node) {
    seg_tree[node] += lazy[node];
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

int query(int node, int l, int r, int ql, int qr) {
    if (r < ql or qr < l) {
        return -INF;
    } else if (ql <= l and r <= qr) {
        return seg_tree[node] + lazy[node];
    }

    push(node);
    int mid = (l + r) / 2;
    return max(
        query(2 * node, l, mid, ql, qr),
        query(2 * node + 1, mid + 1, r, ql, qr)
    );
}

int update(int node, int l, int r, int ql, int qr, int v) {
    if (r < ql or qr < l) {
        return seg_tree[node] + lazy[node];
    } else if (ql <= l and r <= qr) {
        lazy[node] += v;
        return seg_tree[node] + lazy[node];
    }

    push(node);
    int mid = (l + r) / 2;
    return seg_tree[node] = max(
        update(2 * node, l, mid, ql, qr, v),
        update(2 * node + 1, mid + 1, r, ql, qr, v)
    );
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

int solve(int u, int v) {
    int ans = -INF;
    while (nxt[u] != nxt[v]) {
        if (depth[nxt[u]] > depth[nxt[v]]) {
            swap(u, v);
        }
        ans = max(ans, query(1, 0, n - 1, tin[nxt[v]], tin[v]));
        v = par[nxt[v]];
    }

    if (u < 0 or v < 0) return ans;

    if (tin[u] > tin[v]) {
        swap(u, v);
    }
    assert(tin[u] <= tin[v] and tin[v] < tout[u]);
    ans = max(ans, query(1, 0, n - 1, tin[u], tin[v]));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
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
    int q;
    cin >> q;
    while (q-- > 0) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "add") {
            --a;
            update(tin[a], tout[a] - 1, b);
        } else {
            --a; --b;
            int ans = solve(a, b);

            cout << ans << '\n';
        }
    }

    return 0;
}
