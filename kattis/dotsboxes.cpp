#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

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
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    --n;

    vector<string> grid(2 * n + 1);
    for (int i = 0; i < 2 * n + 1; ++i) {
        cin >> grid[i];
    }

    auto node = [&](int x, int y) {
        return n * x + y;
    };

    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    int dummy0 = n * n;
    int dummy1 = dummy0 + 1;
    int src = dummy1 + 1;
    int sink = src + 1;
    Dinic dinic(sink + 1);
    dinic.addEdge(src, dummy0, 1e18);
    dinic.addEdge(dummy1, sink, 1e18);

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            int cx = 2 * x + 1;
            int cy = 2 * y + 1;

            int p = (x ^ y) % 2;

            int free = 3;
            int off_edge = 0;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (grid[cx + dx[d]][cy + dy[d]] != '.') {
                    --free;
                } else {
                    if (0 <= nx and nx < n and 0 <= ny and ny < n) {
                        if (d >= 2) continue;

                        if (p) {
                            // cout << "Edge from " << nx << ", " << ny << " to " << x << ", " << y << '\n';
                            dinic.addEdge(node(nx, ny), node(x, y), 1);
                        } else {
                            // cout << "Edge from " << x << ", " << y << " to " << nx << ", " << ny << '\n';
                            dinic.addEdge(node(x, y), node(nx, ny), 1);
                        }
                    } else {
                        ++off_edge;
                    }
                }
            }

            /*
            cout << "Free " << x << ' ' << y << " is " << free << '\n';
            cout << "OffEdge " << x << ' ' << y << " is " << off_edge << '\n';
            */
            if (p) {
                dinic.addEdge(node(x, y), sink, free);
                if (off_edge) {
                    dinic.addEdge(dummy0, node(x, y), off_edge);
                }
            } else {
                dinic.addEdge(src, node(x, y), free);
                if (off_edge) {
                    dinic.addEdge(node(x, y), dummy1, off_edge);
                }
            }
        }
    }

    cout << dinic.calc(src, sink) + 1 << '\n';

    return 0;
}
