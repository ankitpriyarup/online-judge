#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAXN = 502;
const int INF = 1e9;

namespace maxflow {
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
};

int n, m;
int inspection[MAXN];
int direct[MAXN][MAXN];
int fast[MAXN][MAXN];

int indegree[MAXN];
int outdegree[MAXN];
typedef tuple<int, int, int> flight;

void floyd_warshall() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Either stay as is or use k as an intermediary
                fast[i][j] = min(fast[i][j], 
                                 fast[i][k] + inspection[k] + fast[k][j]);
            }
        }
    }
}

bool can_make(flight a, flight b) {
    int s1 = get<0>(a);
    int f1 = get<1>(a);
    int t1 = get<2>(a);

    int s2 = get<0>(b);
    int t2 = get<2>(b);

    int time = t1 + direct[s1][f1] + inspection[f1] + fast[f1][s2] + (f1 == s2 ? 0 : inspection[s2]);

    return time <= t2;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", inspection + i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &direct[i][j]);
            fast[i][j] = direct[i][j];
        }
    }

    floyd_warshall();

    vector<flight> flights(m);
    int s, f, t;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &s, &f, &t);
        flights[i] = make_tuple(s, f, t);
    }

    int source = 2 * m + 1;
    int sink = 2 * m + 2;

    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));

    maxflow::init(sink + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i != j and can_make(flights[i], flights[j])) {
                maxflow::edge(2 * i + 1, 2 * j + 2, 1, 0);
                ++outdegree[i];
                ++indegree[j];
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (outdegree[i] > 0)
            maxflow::edge(source, 2 * i + 1, 1, 0);

        if (indegree[i] > 0)
            maxflow::edge(2 * i + 2, sink, 1, 0);
    }

    printf("%lld\n", m - maxflow::run(source, sink));

    return 0;
}
