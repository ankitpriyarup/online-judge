#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://cp-algorithms.com/graph/dinic.html
 * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
 * $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
 * To obtain the actual flow, look at positive values only.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING
 */
struct Dinic {
	struct Edge {
		int to, rev;
		ll c, f;
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, int rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, 0});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, 0});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c - e.f))) {
					e.f += p, adj[e.to][e.rev].f -= p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				trav(e, adj[v])
					if (!lvl[e.to] && (e.c - e.f) >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<string> grid(n);
    for (auto& row : grid) {
        cin >> row;
    }

    int src = n * m;
    int sink = src + 1;
    Dinic mf(n * m + 2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int v = m * i + j;
            if (grid[i][j] == '.') {
                mf.addEdge(src, v, b);
            } else {
                mf.addEdge(v, sink, b);
            }

            if (i + 1 < n) {
                int u = m * (i + 1) + j;
                mf.addEdge(v, u, a, a);
            }
            if (j + 1 < m) {
                int u = m * i + j + 1;
                mf.addEdge(v, u, a, a);
            }
        }
    }

    cout << mf.calc(src, sink) << '\n';

    return 0;
}
