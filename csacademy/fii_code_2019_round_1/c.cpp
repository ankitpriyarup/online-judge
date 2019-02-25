#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void dfs(const vector<vi>& graph, vector<vi>& vis, int u, int k) {
    if (vis[u][k] == 1) return;
    vis[u][k] = 1;
    for (int v : graph[u]) {
        dfs(graph, vis, v, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    --s; --t;
    assert(s != t);

    vector<vi> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[v].push_back(u);
    }

    vector<vi> vis(n, vi(2, 0));
    dfs(graph, vis, s, 0);
    dfs(graph, vis, t, 1);

    bool common = false;
    for (int i = 0; i < n; ++i) {
        common |= vis[i][0] and vis[i][1];
    }

    for (int i = 0; i < n; ++i) {
        int ans = 2 - vis[i][0] - vis[i][1];
        if (ans == 2) {
            if (common)
                ans = 1;
        }
        cout << ans << " \n"[i == n - 1];
    }
    
    return 0;
}
