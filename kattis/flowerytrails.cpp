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

constexpr int MAXN = 10004;
constexpr int INF = 1e9 + 7;
int n, m;
vector<pii> graph[MAXN];
int dist[2][MAXN];

void dijkstra(int layer, int src) {
    for (int i = 0; i < n; ++i)
        dist[layer][i] = INF;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, src});
    dist[layer][src] = 0;

    int node, cur_dist;
    int next_node, next_dist;
    while (!pq.empty()) {
        tie(cur_dist, node) = pq.top();
        pq.pop();

        if (dist[layer][node] < cur_dist)
            continue;

        for (const pii& e : graph[node]) {
            next_node = e.first;
            next_dist = e.second + cur_dist;
            if (next_dist < dist[layer][next_node]) {
                dist[layer][next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(0, 0);
    dijkstra(1, n - 1);

    /*
    for (int layer = 0; layer < 2; ++layer) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", dist[layer][i]);
        }
        printf("\n");
    }
    */

    ll ans = 0LL;
    for (int u = 0; u < n; ++u) {
        for (const pii& e : graph[u]) {
            tie(v, w) = e;

            if (dist[0][u] + w == dist[0][v] and dist[0][u] + w + dist[1][v] == dist[0][n - 1]) {
                ans += w;
            }
        }
    }

    ans *= 2LL;

    printf("%lld\n", ans);

    return 0;
}
