#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <memory.h>
#include <tuple>

using namespace std;

using ll = long long;

// Adapted from https://github.com/stjepang/snippets/ by arknave
namespace mcmf {
    const int MAXV = 1133;
    const int MAXE = 4444;
    const ll oo = 1e18;

    int V, E;
    int last[MAXV], curr[MAXV], bio[MAXV]; ll pi[MAXV];
    int next[MAXE], adj[MAXE]; ll cap[MAXE], cost[MAXE];

    void init(int n) {
        V = n;
        E = 0;
        memset(last, -1, sizeof(last));
    }

    void edge(int x, int y, ll c, ll w) {
        adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
        adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
    }

    ll push(int x, int sink, ll flow) {
        if (x == sink) return flow;
        if (bio[x]) return 0;
        bio[x] = true;

        for (int &e = curr[x]; e != -1; e = next[e]) {
            int y = adj[e];

            if (cap[e] && pi[x] == pi[y] + cost[e])
                if (ll f = push(y, sink, min(flow, cap[e])))
                    return cap[e] -= f, cap[e^1] += f, f;
        }

        return 0;
    }

    pair<ll, ll> run(int src, int sink) {
        ll total = 0;
        ll flow = 0;

        for (int i = 0; i < V; ++i) {
            pi[i] = oo;
        }
        pi[sink] = 0;

        for (;;) {
            bool done = true;
            for (int x = 0; x < V; ++x)
                for (int e = last[x]; e != -1; e = next[e])
                    if (cap[e] && pi[x] > pi[adj[e]] + cost[e])
                        pi[x] = pi[adj[e]] + cost[e], done = false;
            if (done) break;
        }

        for (;;) {
            for (int i = 0; i < V; ++i)
                bio[i] = false;
            for (int i = 0; i < V; ++i)
                curr[i] = last[i];

            while (ll f = push(src, sink, oo)) {
                total += pi[src] * f;
                flow += f;
                memset(bio, false, sizeof(bio));
            }

            ll inc = oo;
            for (int x = 0; x < V; ++x) if (bio[x]) {
                for (int e = last[x]; e != -1; e = next[e]) {
                    int y = adj[e];
                    if (cap[e] && !bio[y]) inc = min(inc, pi[y] + cost[e] - pi[x]);
                }
            }
            if (inc == oo) break;

            for (int i = 0; i < V; ++i) if (bio[i]) pi[i] += inc;
        }

        return make_pair(total, flow);
    }
}

const int MAXN = 1003;
int p, r, l;

int main() {
    scanf(" %d %d %d", &p, &r, &l);
    r += 2;

    mcmf::init(r + 1);
    mcmf::edge(r, 0, p, 0);
    int u, v;
    for (int i = 0; i < l; ++i) {
        scanf(" %d %d", &u, &v);
        u += 2;
        v += 2;
        mcmf::edge(u, v, 1, 1);
        mcmf::edge(v, u, 1, 1);
    }

    ll cost, flow;
    tie(cost, flow) = mcmf::run(r, 1);

    if (flow < p) {
        int dead = p - flow;
        printf("%d people left behind\n", dead);
    } else {
        printf("%lld\n", cost);
    }

    return 0;
}
