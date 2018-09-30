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

namespace dinic {
    const int MAXV = 4002;
    const int MAXE = MAXV * MAXV;
    const ll oo = 1e18;

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

bool can_reach(int dx, int dy, ll s) {
    double d2 = sqrt(1.0 * dx * dx + 1.0 * dy * dy);
    return d2 + 10.0 <= s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    ll s;
    cin >> n >> m >> s;

    dinic::init(n + m + 2);

    vector<pair<ll, ll>> pts(n);
    for (int i = 0; i < n; ++i) {
        dinic::edge(n + m, i, 1, 0);
        cin >> pts[i].first >> pts[i].second;
    }

    int x, y, w;
    for (int j = 0; j < m; ++j) {
        cin >> x >> y >> w;
        dinic::edge(n + j, n + m + 1, w, 0);

        for (int i = 0; i < n; ++i) {
            if (can_reach(x - pts[i].first, y - pts[i].second, s)) {
                dinic::edge(i, n + j, 1, 0);
            }
        }
    }

    bool poss = dinic::run(n + m, n + m + 1) == n;
    cout << (poss ? "YES" : "NO") << '\n';

    return 0;
}
