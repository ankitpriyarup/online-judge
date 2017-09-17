#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vpii = vector<pii>;

constexpr int MAXN = 102;
int n, m;
int pickup[MAXN];

vpii graph[MAXN];
int dist[MAXN];
int items[MAXN];

void dijkstra() {
    priority_queue<pii, vpii, greater<pii> > pq;
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    items[1] = pickup[1];
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] != cur_dist) {
            continue;
        }

        for (auto edge : graph[node]) {
            int child = edge.first;
            int new_dist = cur_dist + edge.second;

            if (dist[child] == -1 or (new_dist < dist[child])) {
                dist[child] = new_dist;
                items[child] = items[node] + pickup[child];

                pq.push({new_dist, child});
            }

            if (dist[child] == new_dist) {
                items[child] = max(items[child], items[node] + pickup[child]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", pickup + i);
    }

    scanf("%d", &m);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra();

    if (dist[n] == -1) {
        printf("%s\n", "impossible");
    } else {
        printf("%d %d\n", dist[n], items[n]);
    }

    return 0;
}
