#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

constexpr int MAXN = 52;
constexpr int MAXM = 502;
constexpr int INF = 1e9;
int n, m, p;
int x[MAXN], y[MAXN];
int u[MAXM], v[MAXM], w[MAXM];

vector<pair<int, int> > graph[MAXM];
int dist[MAXM][MAXM];

void dijkstra(int src) {
    for (int i = 1; i <= m; ++i) 
        dist[src][i] = INF;
    dist[src][src] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, src});
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if (dist[src][cur.second] != cur.first)
            continue;

        for (pii edge : graph[cur.second]) {
            int new_dist = cur.first + edge.second;
            if (dist[src][edge.first] == -1 or new_dist < dist[src][edge.first]) {
                dist[src][edge.first] = new_dist;
                pq.push({new_dist, edge.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", x + i, y + i);
    }

    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", u + i, v + i, w + i);
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i] != u[j]) continue;

            // see if you can turn from edge i to edge j
            // that means dot product has to be >= 0
            int x1d = x[v[i]] - x[u[i]];
            int y1d = y[v[i]] - y[u[i]];

            int x2d = x[v[j]] - x[u[j]];
            int y2d = y[v[j]] - y[u[j]];

            if (x1d * x2d + y1d * y2d >= 0) {
                graph[i].push_back({j, w[i] + w[j]});
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        dijkstra(i);
    }

    for (int i = 1; i <= m; ++i) {
        dist[i][i] = INF;
        for (int j = 1; j <= m; ++j) {
            if (j != i and dist[i][j] != INF and dist[j][i] != INF) {
                dist[i][i] = min(dist[i][i], dist[i][j] + dist[j][i]);
            }
        }
    }

    ll ans = 0;
    int pos, nxt;
    scanf("%d", &pos);
    for (int i = 2; i <= p; ++i) {
        scanf("%d", &nxt);
        if (dist[pos][nxt] == INF) {
            printf("NIE\n");
            return 0;
        }
        ans += dist[pos][nxt];
        pos = nxt;

        printf("%lld\n", ans);
    }

    return 0;
}
