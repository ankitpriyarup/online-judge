#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)x.size()

constexpr ll INF = 1e16;

// from benq
template<class T, int SZ> 
struct LazySegTree {
    T mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];
        
        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }
    
    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

constexpr int MAXN = 5e5 + 5;
vector<pair<int, ll>> tree[MAXN];
ll dist[MAXN];
int clocker = 0;
int tin[MAXN], tout[MAXN];
ll ans[MAXN];
LazySegTree<ll, 1<<19> lst;
vector<tuple<int, int, int>> queries[MAXN];

void dfs_dist(int u, ll w = 0) {
    tin[u] = clocker++;
    dist[u] = w;
    for (auto& e : tree[u]) {
        dfs_dist(e.first, w + e.second);
    }

    tout[u] = clocker;
}

void dfs_ans(int u, ll w = 0) {
    for (auto& query : queries[u]) {
        int l, r, idx;
        tie(l, r, idx) = query;
        ans[idx] = w + lst.qmin(l, r);
    }

    for (auto& e : tree[u]) {
        int v = e.first;
        lst.upd(tin[v], tout[v] - 1, -2LL * e.second);
        dfs_ans(v, w + e.second);
        lst.upd(tin[v], tout[v] - 1, 2LL * e.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	int n, q;
    scanf(" %d %d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int par, w;
        scanf(" %d %d", &par, &w);
        --par;
        tree[par].emplace_back(i, w);
    }
    dfs_dist(0);
    for (int i = 0; i < n; ++i) {
        lst.mn[(1 << 19) + i] = (tree[i].empty() ? dist[i] : INF);
    }

    lst.build();

    for (int i = 0; i < q; ++i) {
        int u, l, r;
        scanf(" %d %d %d", &u,&l, &r);
        --u; --l; --r;
        queries[u].emplace_back(l, r, i);
    }

    dfs_ans(0);

    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }
    
    return 0;
}
