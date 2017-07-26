#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long double ld;

const ld EPS = 1e-12L;

const int MAXN = 502;
int n, s, t;
long long q;
int x[MAXN], y[MAXN], h[MAXN];
int springs[MAXN];
int towns[MAXN];

inline bool ldeq(const ld& x, const ld& y) {
    return fabs(x - y) < EPS;
}

namespace mcmf {
    const int MAXV = 1000100;
    const int MAXE = 1000100;
    const long long oo = 1e18;

    int V, E;
    int last[MAXV], curr[MAXV], bio[MAXV];
    ld pi[MAXV];
    int next[MAXE], adj[MAXE];
    long long cap[MAXE];
    ld cost[MAXE];

    void init(int n) {
        V = n;
        E = 0;
        memset(last, -1, sizeof(last));
    }

    void edge(int x, int y, long long c, ld w) {
        adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
        adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
    }

    long long push(int x, int sink, long long flow) {
        if (x == sink) return flow;
        if (bio[x]) return 0;
        bio[x] = true;

        for (int &e = curr[x]; e != -1; e = next[e]) {
            int y = adj[e];

            if (cap[e] && ldeq(pi[x], pi[y] + cost[e]))
                if (long long f = push(y, sink, min(flow, cap[e])))
                    return cap[e] -= f, cap[e^1] += f, f;
        }
        return 0;
    }

    pair<ld, long long> run(int src, int sink) {
        ld total = 0;
        long long flow = 0;

        for (int i = 0; i < V; ++i) {
            pi[i] = oo;
        }
        pi[sink] = 0.0L;

        for (;;) {
            bool done = true;
            for (int x = 0; x < V; ++x)
                for (int e = last[x]; e != -1; e = next[e])
                    if (cap[e] && pi[x] - EPS > pi[adj[e]] + cost[e])
                        pi[x] = pi[adj[e]] + cost[e], done = false;

            if (done) break;
        }

        for (;;) {
            memset(bio, 0, sizeof(bio));
            for (int i = 0; i < V; ++i) {
                curr[i] = last[i];
            }

            while (long long f = push(src, sink, oo)) {
                total += pi[src] * f;
                flow += f;
                memset(bio, 0, sizeof(bio));
            }

            ld inc = oo;
            for (int x = 0; x < V; ++x) {
                if (bio[x]) {
                    for (int e = last[x]; e != -1; e = next[e]) {
                        int y = adj[e];
                        if (cap[e] && !bio[y]) {
                            inc = min(inc, pi[y] + cost[e] - pi[x]);
                        }
                    }
                }
            }

            if (inc == oo) {
                break;
            }

            for (int i = 0; i < V; ++i) {
                if (bio[i]) {
                    pi[i] += inc;
                }
            }
        }

        return {total, flow};
    }
}

ld get_cost(int a, int b) {
    if (h[a] <= h[b]) {
        return 100.0L * q;
    }

    long long xd = x[a] - x[b];
    long long yd = y[a] - y[b];
    long long hd = h[a] - h[b];

    long long d2 = xd * xd + yd * yd + hd * hd;
    if (d2 <= q * q) {
        return sqrt(0.0L + d2);
    } else {
        return 100.0L * q;
    }
}

int main() {
    scanf("%d %d %d %lld", &n, &s, &t, &q);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", x + i, y + i, h + i);
    }

    for (int i = 0; i < s; ++i) {
        scanf("%d", &springs[i]);
    }

    sort(springs, springs + s);

    for (int i = 0; i < t; ++i) {
        scanf("%d", &towns[i]);
    }
    sort(towns, towns + t);

    int src = n + 1;
    int sink = n + 2;
    mcmf::init(sink + 1);

    for (int i = 0; i < s; ++i) {
        mcmf::edge(src, springs[i], 1, 0);
    }

    for (int i = 0; i < t; ++i) {
        mcmf::edge(towns[i], sink, 1, 0);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) 
                continue;

            ld edge_cost = get_cost(i, j);
            if (edge_cost < q) {
                mcmf::edge(i, j, n, edge_cost);
            }
        }
    }

    pair<ld, long long> ans = mcmf::run(src, sink);

    if (ans.second != t) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%.12Lf\n", ans.first);
    }

    return 0;
}
