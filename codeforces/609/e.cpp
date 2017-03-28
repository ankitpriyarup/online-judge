#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 200005;
const int LOGN = 19;
int n, m;

struct edge {
    int u, v, w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};

vector<edge> edges;

int uf[MAXN];

void init() {
    for (int i = 1; i <= n; ++i)
        uf[i] = i;
}

int find(int x) {
    int p = uf[x];
    if (uf[p] != p)
        p = find(p);

    return uf[x] = p;
}

void join(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return;

    uf[xr] = yr;
}

vector<pair<int, int> > tree[MAXN];
int parent[MAXN][LOGN];
int big[MAXN][LOGN];
int depth[MAXN];

long long find_mst() {
    vector<edge> sorted(edges.begin(), edges.end());
    sort(sorted.begin(), sorted.end());

    init();
    long long mst_cost = 0LL;
    for (const edge& edg : sorted) {
        if (find(edg.u) != find(edg.v)) {
            tree[edg.u].push_back({edg.v, edg.w});
            tree[edg.v].push_back({edg.u, edg.w});
            join(edg.u, edg.v);
            mst_cost += edg.w;
        }
    }

    return mst_cost;
}

void dfs(int node, int par, int dep) {
    parent[node][0] = par;
    depth[node] = dep;
    for (pair<int, int> child : tree[node]) {
        if (child.first != par) {
            dfs(child.first, node, dep + 1);
            big[child.first][0] = child.second;
        }
    }
}

void gen_parents() {
    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
                big[i][j] = max(big[i][j - 1], big[parent[i][j - 1]][j - 1]);
            }
        }
    }
}

int walk_up(int node, int move) {
    int par = node;
    for (int j = 0, p = 1; par != -1 and p <= move; ++j, p <<= 1) {
        if (move & p) {
            par = parent[par][j];
        }
    }

    return par;
}

int find_max(int node, int move) {
    int loc = node;
    int val = 0;

    for (int j = 0, p = 1; loc != -1 and p <= move; ++j, p <<= 1) {
        if (move & p) {
            val = max(val, big[loc][j]);
            loc = parent[loc][j];
        }
    }

    return val;
}

int lca(int x, int y) {
    if (depth[x] > depth[y])
        return lca(y, x);
    if (depth[x] < depth[y])
        y = walk_up(y, depth[y] - depth[x]);

    if (x == y) return x;

    int lo = 0;
    int hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (walk_up(x, mid) == walk_up(y, mid))
            hi = mid;
        else
            lo = mid;
    }

    return walk_up(x, hi);
}

int main() {
    scanf("%d %d", &n, &m);

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);

        edges.push_back({u, v, w});
    }

    long long cost = find_mst();
    memset(parent, -1, sizeof(parent));
    dfs(1, -1, 0);
    gen_parents();

    for (int i = 0; i < m; ++i) {
        u = edges[i].u;
        v = edges[i].v;

        int l = lca(u, v);
        // printf("%d %d %d\n", u, v, l);
        if ((l == u or l == v) and (depth[u] - depth[v] == 1 or depth[v] - depth[u] == 1)) {
            printf("%lld\n", cost);
        } else {
            long long m1 = find_max(u, depth[u] - depth[l]);
            long long m2 = find_max(v, depth[v] - depth[l]);

            printf("%lld\n", cost - max(m1, m2) + edges[i].w);
        }
    }

    return 0;
}
