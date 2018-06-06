#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

struct dijkstra {
    constexpr static ll INF = 1e18;
    using edge = pair<ll, int>;

    int n;
    vector<vector<edge>> graph;

    dijkstra(int n): n(n) {
        graph.assign(n, vector<edge>());
    }

    void add_edge(int u, int v, ll w) {
        graph[u].emplace_back(w, v);
    }

    pair<vector<ll>, vector<int>> run(int src) {
        vector<ll> dist(n, INF);
        vector<int> before(n, -1);
        priority_queue<edge, vector<edge>, greater<edge>> pq;

        dist[src] = 0LL;
        pq.emplace(0LL, src);

        ll cur_dist;
        int u;
        while (!pq.empty()) {
            tie(cur_dist, u) = pq.top();
            pq.pop();
            if (dist[u] != cur_dist)
                continue;

            // printf("dist[%d] = %lld\n", u, cur_dist);
            for (auto&& [w, v] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    before[v] = u;
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return {dist, before};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf(" %d %d", &n, &m);
    dijkstra sssp(n);

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        --u; --v;
        sssp.add_edge(u, v, w);
        sssp.add_edge(v, u, w);
    }

    auto res = sssp.run(0);

    if (res.first[n - 1] == dijkstra::INF) {
        printf("-1\n");
        return 0;
    }

    vector<int> path = {n - 1};
    while (path.back() != 0) {
        path.push_back(res.second[path.back()]);
    }

    while (!path.empty()) {
        printf("%d ", path.back() + 1);
        path.pop_back();
    }

    return 0;
}
