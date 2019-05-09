#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

constexpr int INF = 1e9 + 7;

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
	}
	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};

int r, s, l;
int source, sink;
vector<pii> lawsuits;

PushRelabel build(int mid) {
    PushRelabel pr(sink + 1);
    for (int i = 0; i < l; ++i) {
        pr.add_edge(source, i, 1);
    }
    for (int i = 0; i < r + s; ++i) {
        pr.add_edge(l + i, sink, mid);
    }

    for (int i = 0; i < l; ++i) {
        int u, v;
        tie(u, v) = lawsuits[i];
        pr.add_edge(i, l + u, INF);
        pr.add_edge(i, l + r + v, INF);
    }

    return pr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> s >> l;

    for (int i = 0; i < l; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        lawsuits.emplace_back(u, v);
    }

    source = l + r + s;
    sink = source + 1;

    int lo = 0;
    int hi = l + l;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        // source, sink, lawsuits, plaintiffs, defendants
        Flow res = build(mid).maxflow(source, sink);
        if (res == l) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    auto pr = build(hi);
    pr.maxflow(source, sink);
    for (int i = 0; i < l; ++i) {
        int goal = -1;
        for (auto& e : pr.g[i]) {
            if (e.f == 1) {
                goal = e.dest - l;
                break;
            }
        }

        assert(goal >= 0);
        if (goal >= r) {
            cout << "CORP " << (goal - r + 1) << '\n';
        } else {
            cout << "INDV " << (goal + 1) << '\n';
        }
    }

    return 0;
}
