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

/**
 * from kactl
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
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<string>> teams(n, vector<string>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> teams[i][j];
        }
    }

    int k;
    cin >> k;

    int src = n + 26;
    int sink = src + 1;
    Dinic mf(sink + 1);
    for (int i = 0; i < n; ++i) {
        mf.addEdge(src, i, 1);
        vi freq(26, 0);
        int max_freq = 0;
        for (int j = 0; j < 3; ++j) {
            for (char c : teams[i][j]) {
                max_freq = max(max_freq, ++freq[c - 'A']);
            }
        }

        for (int j = 0; j < 26; ++j) {
            if (freq[j] == max_freq) {
                mf.addEdge(i, n + j, 1);
            }
        }
    }

    for (int j = 0; j < 26; ++j) {
        mf.addEdge(n + j, sink, k);
    }

    cout << mf.calc(src, sink) << '\n';

    return 0;
}
