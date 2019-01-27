#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void dfs(const vector<vi>& graph, vector<char>& vis, int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : graph[u]) {
        dfs(graph, vis, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[v].push_back(u);
    }

    // a wizard can get the wand if there's a path from 1
    vector<char> vis(n, 0);
    dfs(graph, vis, 0);
    // only ways to get 1 the wand - cycle or no outgoing edges
    vis[0] = 0;
    if (graph[0].empty())
        vis[0] = true;

    for (int u = 1; !vis[0] and u < n; ++u) {
        if (!vis[u]) continue;

        for (int v : graph[u]) {
            if (v == 0) {
                vis[0] = true;
                break;
            }
        }
    }

    string s(n, '0');
    for (int i = 0; i < n; ++i)
        s[i] = '0' + vis[i];


    cout << s << '\n';

    return 0;
}
