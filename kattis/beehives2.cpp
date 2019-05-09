#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pii> edges;
    vector<vi> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // find the length of the shortest cycle in the graph
    // delete each edge, bfs from u to v
    // only do this for non-bridge edges. Maybe break into BCCs first?
    // fuck that, not an optimization in worst case
    // oh but if we combine that with pruning dead ends, maybe...
    // whatever this is a reasonably fast O(m^2)
    int ans = n + n;
    for (auto& e : edges) {
        int s, t;
        tie(s, t) = e;
        vi dist(n, -1);
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (dist[v] == -1 and !(u == s and v == t)) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (dist[t] > 1) {
            ans = min(ans, dist[t] + 1);
        }
    }

    if (ans == n + n) {
        cout << "impossible" << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}
