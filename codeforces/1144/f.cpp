#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void dfs(const vector<vi>& graph, vi& color, int u, int c) {
    if (color[u] == c) {
        return;
    }
    color[u] |= c;
    if (color[u] != c) {
        return;
    }
    for (int v : graph[u]) {
        dfs(graph, color, v, c ^ 3);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> graph(n);
    vector<pii> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.emplace_back(u, v);
    }

    vi color(n, 0);
    dfs(graph, color, 0, 1);
    bool poss = true;
    for (int u = 0; u < n; ++u) {
        if (color[u] == 3) {
            poss = false;
            break;
        }
    }

    if (!poss) {
        cout << "NO\n";
        return 0;
    } else {
        string s(m, '0');
        for (int i = 0; i < m; ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            assert(color[u] != color[v]);
            if (color[u] == 2) {
                s[i] = '1';
            }
        }

        cout << "YES\n" << s << '\n';
    }

    return 0;
}
