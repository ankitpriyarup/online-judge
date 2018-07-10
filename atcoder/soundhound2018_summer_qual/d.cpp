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

constexpr int MAXN = 100005;
constexpr ll INF = 1e18;
struct dijkstra {
    using edge = pair<ll, int>;

    int n;
    vector<vector<edge>> graph;

    dijkstra(int n): n(n) {
        graph.assign(n, vector<edge>());
    }

    void add_edge(int u, int v, ll w) {
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    // dists, previous. change return type if you only need one.
    vector<ll> run(int src) {
        vector<ll> dist(n, INF);
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
            for (auto& e : graph[u]) {
                ll w = e.first;
                int v = e.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, s, t;
    scanf(" %d %d %d %d", &n, &m, &s, &t);

    --s; --t;
    dijkstra d1(n), d2(n);

    int u, v, a, b;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d %d", &u, &v, &a, &b);
        --u; --v;
        d1.add_edge(u, v, a);
        d2.add_edge(u, v, b);
    }

    vector<ll> dist0 = d1.run(s);
    vector<ll> dist1 = d2.run(t);

    vector<ll> ans(n);
    ll base = 1e15;
    for (int i = 0; i < n; ++i) {
        ans[i] = base - dist0[i] - dist1[i];
    }

    for (int i = n - 2; i >= 0; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (ll x : ans) {
        printf("%lld\n", x);
    }

    return 0;
}
