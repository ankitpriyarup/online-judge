#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

namespace flow {
    typedef long long ll;

    const int MAXV = 300005;
    const int MAXE = 300005;
    const ll oo = 1e18;

    int V, E;
    int last[MAXV], dist[MAXV], curr[MAXV];
    int next[MAXE], adj[MAXE]; ll cap[MAXE];

    void init(int n) {
        V = n;
        E = 0;
        memset(last, -1, sizeof(last));
    }

    void edge(int x, int y, ll c1, ll c2) {
        adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
        adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
    }

    ll push(int x, int sink, ll flow) {
        if (x == sink) return flow;

        for (int &e = curr[x]; e != -1; e = next[e]) {
            int y = adj[e];

            if (cap[e] && dist[x] + 1 == dist[y]) {
                if (ll f = push(y, sink, min(flow, cap[e]))) {
                    return cap[e] -= f, cap[e ^ 1] += f, f;
                }
            }
        }

        return 0;
    }

    ll run(int src, int sink) {
        ll ret = 0;
        while (true) {
            for (int i = 0; i < V; ++i) {
                curr[i] = last[i];
                dist[i] = -1;
            }

            queue<int> q;
            q.push(src);
            dist[src] = 0;
            while (!q.empty()) {
                int x = q.front();
                q.pop();

                for (int e = last[x]; e != -1; e = next[e]) {
                    int y = adj[e];
                    if (cap[e] && dist[y] == -1) {
                        q.push(y);
                        dist[y] = dist[x] + 1;
                    }
                }
            }

            if (dist[sink] == -1) break;

            while (ll f = push(src, sink, oo)) ret += f;
        }

        return ret;
    }
}

int sensor_to_queue[102];

long long queue_size[33];

long long link_cap[33];

// link, queue
long long data_sizes[33][33];
int nodes[33][33];
int sink_nodes[33];

int main() {
    int n, q, s;
    scanf("%d %d %d", &n, &q, &s);
    for (int i = 1; i <= s; ++i) {
        scanf("%d", sensor_to_queue + i);
    }

    for (int i = 1; i <= q; ++i) {
        scanf("%lld", queue_size + i);
    }

    memset(data_sizes, 0, sizeof(data_sizes));
    int node = 0;
    long long target = 0LL;
    int x;

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", link_cap + i);
        for (int j = 1; j <= s; ++j) {
            scanf("%d", &x);

            data_sizes[i][sensor_to_queue[j]] += x;
            target += x;
        }

        for (int j = 1; j <= q; ++j) {
            nodes[i][j] = node++;

            ++node;
        }
    }

    for (int i = 1; i <= n; ++i) {
        sink_nodes[i] = node++;
    }

    int src = node++;
    int sink = node++;
    flow::init(node);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= q; ++j) {
            // edge from the source
            flow::edge(src, nodes[i][j], data_sizes[i][j], 0);

            // vertex capacity
            flow::edge(nodes[i][j], nodes[i][j] | 1, queue_size[j], 0);

            // edge to this uplink
            flow::edge(nodes[i][j] | 1, sink_nodes[i], flow::oo, 0);

            // edge to the next queue
            if (i < n) {
                flow::edge(nodes[i][j] | 1, nodes[i + 1][j], flow::oo, 0);
            }
        }

        // uplink to sink
        flow::edge(sink_nodes[i], sink, link_cap[i], 0);
    }

    long long ret = flow::run(src, sink);
    printf("%s\n", (ret == target) ? "possible" : "impossible");

    return 0;
}
