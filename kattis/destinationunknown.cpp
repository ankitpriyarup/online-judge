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

constexpr int MAXN = 2003;
constexpr ll INF = 1e12;
int n, m, t;
int dests[MAXN];
vector<pii> graph[MAXN];
ll dist[3][MAXN];

void dijkstra(int layer, int src) {
    for (int u = 1; u <= n; ++u)
        dist[layer][u] = INF;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.emplace(0LL, src);
    dist[layer][src] = 0LL;

    ll cur_dist;
    int u;
    while (!pq.empty()) {
        tie(cur_dist, u) = pq.top();
        pq.pop();

        if (cur_dist != dist[layer][u])
            continue;

        for (auto& e : graph[u]) {
            int v = e.first;
            ll new_dist = cur_dist + e.second;
            if (new_dist < dist[layer][v]) {
                dist[layer][v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d %d %d", &n, &m, &t);
        int s, g, h;
        scanf(" %d %d %d", &s, &g, &h);

        for (int i = 1; i <= n; ++i)
            graph[i].clear();

        int u, v, w, ww;
        for (int i = 0; i < m; ++i) {
            scanf(" %d %d %d", &u, &v, &w);
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
            if ((u == g and v == h) or (u == h and v == g))
                ww = w;
        }

        for (int i = 0; i < t; ++i) {
            scanf(" %d", &dests[i]);
        }
        sort(dests, dests + t);

        dijkstra(0, s);
        dijkstra(1, g);
        dijkstra(2, h);

        for (int i = 0; i < t; ++i) {
            if (dist[0][g] + ww + dist[2][dests[i]] == dist[0][dests[i]]
             or dist[0][h] + ww + dist[1][dests[i]] == dist[0][dests[i]]) {
                printf("%d ", dests[i]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
