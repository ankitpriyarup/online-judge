#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

const ll oo = 1e18;

namespace dinic {
    const int MAXV = 1000100;
    const int MAXE = 1000100;

    int V, E;
    int last[MAXV], dist[MAXV], curr[MAXV];
    int next[MAXE], adj[MAXE];
    ll cap[MAXE];

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

            if (cap[e] && dist[x] + 1 == dist[y])
                if (ll f = push(y, sink, min(flow, cap[e])))
                    return cap[e] -= f, cap[e^1] += f, f;
        }

        return 0;
    }

    ll run(int src, int sink) {
        ll ret = 0;
        for (;;) {
            for (int i = 0; i < V; ++i) {
                curr[i] = last[i];
            }
            memset(dist, -1, sizeof(dist));

            queue<int> Q;
            Q.push(src), dist[src] = 0;

            while (!Q.empty()) {
                int x = Q.front();
                Q.pop();

                for (int e = last[x]; e != -1; e = next[e]) {
                    int y = adj[e];
                    if (cap[e] && dist[y] == -1) {
                        Q.push(y), dist[y] = dist[x] + 1;
                    }
                }
            }

            if (dist[sink] == -1) {
                break;
            }

            while (ll f = push(src, sink, oo)) ret += f;
        }

        return ret;
    }
}

constexpr int MAXN = 303;
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int get_node(int i, int j) {
    return (m * i + j) << 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);

    // node is incoming
    // node^1 is outgoing
    int last_node = get_node(n - 1, m - 1);

    int src = last_node + 2;
    int sink = src + 1;

    dinic::init(sink + 1);

    int cap;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int node = get_node(i, j);

            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                    int dst = get_node(nx, ny);
                    dinic::edge(node|1, dst, oo, 0);
                }
            }

            scanf("%d", &cap);
            dinic::edge(node, node|1, cap, 0);

            if (i == 0 || j == 0) {
                dinic::edge(src, node, oo, 0);
            }
        }
    }

    int x, y;
    scanf("%d %d", &x, &y);
    dinic::edge(get_node(x, y) | 1, sink, oo, 0);

    ll ret = dinic::run(src, sink);

    printf("%lld\n", ret);

    return 0;
}
