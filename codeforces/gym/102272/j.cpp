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

    // time, cost, pos
    using edge = tuple<int, int, int, int, int>;
    using state = tuple<int, int, int>;
    priority_queue<state, vector<state>, greater<state>> pq;

    int n, m;
    cin >> n >> m;

    vector<vector<edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, t, c, f, s;
        cin >> u >> v >> t >> c >> f >> s;
        --u; --v;
        graph[u].emplace_back(v, t, c, f, s);
    }

    constexpr int INF = 1e9 + 7;
    vector<pii> dist(n, {INF, INF});
    pq.emplace(0, 0, 0);
    dist[0] = {0, 0};

    while (!pq.empty()) {
        int cur_dist, cost, u;
        tie(cur_dist, cost, u) = pq.top();
        pq.pop();

        // cout << cur_dist << ' ' << cost << ' ' << (u + 1) << '\n';
        if (u == n - 1) {
            cout << cur_dist << ' ' << cost << '\n';
            return 0;
        }

        if (pii{cur_dist, cost} > dist[u]) continue;

        for (auto& e : graph[u]) {
            int v, t, c, f, s;
            tie(v, t, c, f, s) = e;

            // cout << "considering edge from " << (u + 1) << " to " << (v + 1) << " at cost " << c << '\n';

            // s + k f > cur_dist
            // k f > cur_dist - s
            // k > (cur_dist -  s) / f
            int k = (cur_dist - s) / f;
            int next_train = s + k * f;
            while (next_train <= cur_dist)
                next_train += f;
            pii new_dist = {next_train + t, cost + c};
            // cout << "old dist: " << dist[v].first << ' ' << dist[v].second << '\n';
            // cout << "new dist: " << new_dist.first << ' ' << new_dist.second << '\n';
            if (dist[v] > new_dist) {
                // cout << "taking edge from " << (u + 1) << " to " << (v + 1) << " at cost " << c << '\n';
                dist[v] = new_dist;
                pq.emplace(new_dist.first, new_dist.second, v);
            }
        }
    }
    
    return 0;
}
