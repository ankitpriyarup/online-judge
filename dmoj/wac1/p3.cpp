#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
int n, m, k;
vi tree[MAXN];
int depth[MAXN];
int deep_child[MAXN];
vi scores;

int dfs1(int u) {
    deep_child[u] = depth[u];
    for (int v : tree[u]) {
        deep_child[u] = max(deep_child[u], dfs1(v));
    }

    return deep_child[u];
}

void dfs2(int u, int a) {
    if (tree[u].empty()) {
        scores.push_back(a + 1);
        return;
    }

    int big_child = tree[u][0];
    for (int v : tree[u]) {
        if (deep_child[v] > deep_child[big_child]) {
            big_child = v;
        }
    }

    for (int v : tree[u]) {
        if (v == big_child) {
            dfs2(v, a + 1);
        } else {
            dfs2(v, 0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // note: just compute the first k values and repeat m times
    // solution: compute the HLD by depth instead of size the tree

    cin >> n >> m >>k;

    depth[0] = 0;
    for (int i = 1; i < n; ++i) {
        int par;
        cin >> par;
        --par;
        tree[par].push_back(i);
        depth[i] = 1 + depth[par];
    }

    dfs1(0);
    dfs2(0, 0);

    sort(all(scores));
    reverse(all(scores));
    while (scores.size() < k) {
        scores.push_back(0);
    }

    for (int i = 0; i < m; ++i) {
        cout << scores[i % k] << " \n"[i == m - 1];
    }
    
    return 0;
}
