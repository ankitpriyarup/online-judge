#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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
constexpr int INF = 1e9 + 7;

int n, r;
vector<int> tree[MAXN];
int val[MAXN];
int depth[MAXN];
int tin[MAXN], rtin[MAXN], tout[MAXN];
int timer = 0;

void dfs(int u, int par = -1) {
    tin[u] = timer++;
    rtin[tin[u]] = u;
    for (int v : tree[u]) {
        if (v == par) continue;

        depth[v] = depth[u] + 1;
        dfs(v, u);
    }

    tout[u] = timer;
}

// First a list of nodes, then processed into a list of prefix minimums by depth.
vector<int> seg[4 * MAXN];

// unique list of all depths for a node.
vector<int> inds[4 * MAXN];

bool cmp(const int& a, const int& b) {
    return depth[a] < depth[b] or (depth[a] == depth[b] and a < b);
}

void build(int node, int l, int r) {
    if (l == r) {
        seg[node].push_back(rtin[l]);
    } else {
        int mid = (l + r) >> 1;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        // Merge two sorted lists.
        merge(begin(seg[2 * node]), end(seg[2 * node]),
              begin(seg[2 * node + 1]), end(seg[2 * node + 1]),
              back_inserter(seg[node]), cmp);
    }
}

// Convert a list of nodes into a prefix minimum list.
void process(int node) {
    // Make sure we get all the children
    if (seg[node].size() > 1) {
        process(2 * node);
        process(2 * node + 1);
    }

    // inds stores a list of all the unique depths in this segment
    // in sorted order. We use this to coordinate compress the prefix minimums.
    for (int u : seg[node]) {
        inds[node].push_back(depth[u]);
    }

    // seg[node] already sorted by depth, so don't need to resort
    inds[node].erase(unique(begin(inds[node]), end(inds[node])), end(inds[node]));

    // Store prefix minimums.
    vector<int> pref_mins(inds[node].size(), INF);
    for (int u : seg[node]) {
        int i = lower_bound(begin(inds[node]), end(inds[node]), depth[u]) - begin(inds[node]);
        pref_mins[i] = min(pref_mins[i], val[u]);
    }

    // Actually make these prefix minimums.
    for (int i = 1; i < pref_mins.size(); ++i) {
        pref_mins[i] = min(pref_mins[i], pref_mins[i - 1]);
    }

    seg[node] = pref_mins;
}

int query(int node, int l, int r, int ql, int qr, int k) {
    if (l == ql and r == qr) {
        // Only want to query up to depth k. Find the largest i such that
        // inds[node][i] <= k.
        int i = lower_bound(begin(inds[node]), end(inds[node]), k) - begin(inds[node]);
        while (i >= 0 and i >= inds[node].size() or inds[node][i] > k) --i;
        if (i < 0) return INF;

        return seg[node][i];
    }

    int res = INF;
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        res = min(res, query(2 * node, l, mid, ql, min(mid, qr), k));
    }
    if (mid + 1 <= qr) {
        res = min(res, query(2 * node + 1, mid + 1, r, max(mid + 1, ql), qr, k));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &r);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", val + i);
    }

    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Get the nodes in DFS order. [tin(u), tout(u)) (inclusive start, exclusive end)
    // gives the subtree rooted at u.
    depth[r] = 0;
    dfs(r);

    // Build a segment tree on the nodes in DFS order. Each segment of the tree
    // just contains the nodes in that segment.
    build(1, 0, n - 1);
    
    // Now, convert each segment to prefix minimums. More comments in this function.
    process(1);

    int m;
    scanf("%d", &m);
    int last = 0;
    int p, q;
    while (m-- > 0) {
        scanf("%d %d", &p, &q);
        int x = ((p + last) % n) + 1;
        int k = (q + last) % n;

        // Query all nodes in the subtree rooted at x up to a fixed depth.
        last = query(1, 0, n - 1, tin[x], tout[x] - 1, depth[x] + k);
        printf("%d\n", last);
    }

    return 0;
}
