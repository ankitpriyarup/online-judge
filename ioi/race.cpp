#include "race.h"
#include <bits/stdc++.h>

#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void dfs_sz(const vector<vector<pii>>& tree, vi& vis, vi& size, int u, int p = -1) {
    size[u] = 1;
    for (auto& e : tree[u]) {
        int v = e.first;
        if (v == p or vis[v])
            continue;
        dfs_sz(tree, vis, size, v, u);
        size[u] += size[v];
    }
}

int find_center(const vector<vector<pii>>& tree, vi& vis, vi& size, int tot, int u, int p = -1) {
    for (auto& e : tree[u]) {
        int v = e.first;
        if (v == p or vis[v]) 
            continue;
        if (2 * size[v] >= tot)
            return find_center(tree, vis, size, tot, v, u);
    }

    return u;
}

template <typename F>
void centroid(F& f, const vector<vector<pii>>& tree, vi& vis, vi& size, int u, int p = -1) {
    dfs_sz(tree, vis, size, u, p);
    int c = find_center(tree, vis, size, size[u], u, p);
    // do some shit here
    f(c);

    vis[c] = true;
    for (auto& e : tree[c]) {
        int v = e.first;
        if (v != p and !vis[v]) {
            centroid(f, tree, vis, size, v, c);
        }
    }
}

void dfs_path(const vector<vector<pii>>& tree, const vi& vis, int u, int p, ll path_len, int edges, map<ll, int>& m) {
    auto it = m.find(path_len);
    if (it == end(m) or it->second > edges) {
        m[path_len] = edges;
    }

    for (auto& e : tree[u]) {
        int v, w;
        tie(v, w) = e;
        if (vis[v] or v == p)
            continue;
        dfs_path(tree, vis, v, u, path_len + w, edges + 1, m);
    }
}

int solve(const vector<vector<pii>>& tree, int k) {
    int n = tree.size();
    vi vis(n, 0);

    constexpr int INF = 1e9 + 7;
    int ans = INF;
    auto f = [&](int u) {
        // one more dfs
        // path length -> shortest leg with that length
        // add then merge maps
        map<ll, int> left, right;
        left[0] = 0;
        for (auto& e : tree[u]) {
            int v, w;
            tie(v, w) = e;
            if (vis[v]) {
                continue;
            }

            right.clear();
            // cout << "Starting path at node " << v << " weight " << w << '\n';
            dfs_path(tree, vis, v, u, w, 1, right);

            for (auto& p : right) {
                // cout << "Considering w " << p.first << " e " << p.second << '\n';
                ll path_len = p.first;
                int edges = p.second;
                auto it = left.find(k - path_len);
                if (it != end(left)) {
                    ans = min(ans, edges + it->second);
                }
            }

            for (auto& p : right) {
                if (left.find(p.first) == end(left) or left[p.first] > p.second) {
                    left[p.first] = p.second;
                }
            }
        }
    };

    vi size(n, 0);
    centroid(f, tree, vis, size, 0, -1);

    return ans == INF ? -1 : ans;
}

int best_path(int n, int k, int h[][2], int l[]) {
    // create the tree
    vector<vector<pii>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u = h[i][0];
        int v = h[i][1];
        int w = l[i];

        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    return solve(tree, k);
}

int main() {
    constexpr int MAXN = 200000;
    int n, k;
    cin >> n >> k;
    int h[MAXN][2], l[MAXN];
    for (int i = 0; i + 1 < n; ++i) {
        cin >> h[i][0] >> h[i][1] >> l[i];
    }

    int res = best_path(n, k, h, l);
    cout << res << '\n';
    int goal;
    cin >> goal;
    if (res == goal) {
        cout << "Correct.\n";
    }
    return 0;
}
