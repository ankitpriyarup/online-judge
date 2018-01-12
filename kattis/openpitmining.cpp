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

constexpr int MAXN = 203;
int n;
int v[MAXN], c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int m, c;
    int k;

    dinic::init(n + 3);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", v + i, &c, &m);
        v[i] -= c;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &k);
            dinic::edge(k, i, oo, 0);
        }
    }

    int src = n + 1;
    int sink = n + 2;
    ll pos = 0LL;
    for (int i = 1; i <= n; ++i) {
        if (v[i] >= 0) {
            pos += v[i];
            dinic::edge(src, i, v[i], 0);
        } else {
            dinic::edge(i, sink, -v[i], 0);
        }
    }

    ll res = dinic::run(src, sink);

    printf("%lld\n", pos - res);

    return 0;
}
