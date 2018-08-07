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
constexpr int MAXM = 1000006;
int n;
int c[MAXM];
vector<int> tree[MAXN];
int timer = 0;
int tin[MAXN], rtin[MAXN], tout[MAXN];
int par[MAXN], depth[MAXN];
int price[MAXN];

// contains node!!! l r are times
int seg[4 * MAXN];

void pull(int node) {
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

void build_tree(int node, int l, int r) {
    if (l == r) {
        seg[node] = rtin[l];
        return;
    }

    int mid = (l + r) >> 1;
    build_tree(2 * node, l, mid);
    build_tree(2 * node + 1, mid + 1, r);
    pull(node);
}

int query(int node, int l, int r, int ql, int qr) {
    if (r < ql or l > qr) {
        return 0;
    }

    if (ql <= l and r <= qr) {
        return seg[node];
    }

    int mid = (l + r) >> 1;
    return max(query(2 * node, l, mid, ql, qr),
               query(2 * node + 1, mid + 1, r, ql, qr));
}

void update(int node, int l, int r, int idx, int v) {
    if (idx < l or idx > r) {
        return;
    }

    if (l == r) {
        seg[node] = v;
        return;
    }

    int mid = (l + r) >> 1;
    update(2 * node, l, mid, idx, v);
    update(2 * node + 1, mid + 1, r, idx, v);
    pull(node);
}

void dfs(int u) {
    tin[u] = timer++;
    rtin[tin[u]] = u;

    for (int v : tree[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
    }

    tout[u] = timer;
}

void solve() {
    int m, a, b;
    scanf(" %d %d %d %d", &n, &m, &a, &b);

    c[0] = b % n;
    for (int i = 1; i < m; ++i) {
        c[i] = c[i - 1] + a;
        if (c[i] >= n) {
            c[i] -= n;
        }
    }

    for (int i = 0; i < n; ++i) {
        tree[i].clear();
        price[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        scanf(" %d", &par[i]);
        tree[par[i]].push_back(i);
    }

    timer = 0;
    depth[0] = 0;
    dfs(0);

    sort(c, c + m, [](const int& u, const int& v) {
        return tin[u] < tin[v];
    });

    ll ans = 0LL;
    build_tree(1, 0, n - 1);
    for (int i = m - 1; i >= 0; --i) {
        int subtree = c[i];
        int idx = query(1, 0, n - 1, tin[subtree], tout[subtree] - 1);
        // cout << "Taking node " << idx << "\n";
        ans += idx;
        update(1, 0, n - 1, tin[idx], 0);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cerr << tc << '\n';
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}
