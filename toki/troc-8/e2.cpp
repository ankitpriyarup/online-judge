#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 100005;
int n;
vector<int> tree[MAXN];
int par[MAXN], depth[MAXN], sz[MAXN];
int timer = 0;
int tin[MAXN], tout[MAXN], nxt[MAXN];
int a[MAXN];

constexpr int SZ = 1<<18;
struct LazySegTree {
    using T = ll;
    T sum[2*SZ], lazy[2*SZ]; 
    LazySegTree() {
        memset(sum,0,sizeof sum);
        memset(lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind]; // modify values for current node
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind]; // push lazy to children
        lazy[ind] = 0;
    }

    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1]; // recalc values for current node
    }

    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc; 
            push(ind,L,R); return;
        }
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
    
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
    }
} lst;

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

void update_path(int u, int v, int x) {
    while (u >= 0 and v >= 0 and nxt[u] != nxt[v]) {
        if (depth[nxt[u]] > depth[nxt[v]]) {
            swap(u, v);
        }
        lst.upd(tin[nxt[v]], tin[v], x);
        v = par[nxt[v]];
    }

    if (u < 0 or v < 0) return;

    if (tin[u] > tin[v]) {
        swap(u, v);
    }
    assert(tin[u] <= tin[v] and tin[v] < tout[u]);
    lst.upd(tin[u], tin[v], x);
}

ll solve(int u, int v) {
    ll ans = 0LL;
    while (u >= 0 and v >= 0 and nxt[u] != nxt[v]) {
        if (depth[nxt[u]] > depth[nxt[v]]) {
            swap(u, v);
        }
        ans += lst.qsum(tin[nxt[v]], tin[v]);
        v = par[nxt[v]];
    }

    if (u < 0 or v < 0) return ans;

    if (tin[u] > tin[v]) {
        swap(u, v);
    }
    assert(tin[u] <= tin[v] and tin[v] < tout[u]);
    ans += lst.qsum(tin[u], tin[v]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        cin >> par[i];
        --par[i];
        tree[par[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    par[0] = -1;
    dfs_sz(0);
    dfs_time(0);

    for (int i = 0; i < n; ++i) {
        lst.upd(tin[i], tin[i], a[i]);
    }

    while (q-- > 0) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v, x;
            cin >> u >> v >> x;
            --u; --v;

            update_path(u, v, x);
        } else if (op == 2) {
            int u, x;
            cin >> u >> x;
            --u;

            lst.upd(tin[u], tout[u] - 1, x);
        } else if (op == 3) {
            int u, v;
            cin >> u >> v;
            --u; --v;

            cout << solve(u, v) << '\n';
        } else {
            int u;
            cin >> u;
            --u;

            cout << lst.qsum(tin[u], tout[u] - 1) << '\n';
        }

        /*
        cout << "wtf ";
        for (int i = 0; i < n; ++i) {
            cout << lst.qsum(tin[i], tin[i]) << " ";
        }
        cout << endl;
        */
    }

    return 0;
}
