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
using vi = vector<int>;

const ll oo = 1e12;

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
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

constexpr int MAXN = 303;
int n, m, k;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char grid[MAXN][MAXN];
int costs[MAXN];

int get_node(int i, int j) {
    assert(0 <= i and i < n);
    assert(0 <= j and j < m);
    return (m * i + j) << 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &m, &n, &k);

    // node is incoming
    // node^1 is outgoing
    int last_node = get_node(n - 1, m - 1);

    int src = last_node + 2;
    int sink = src + 1;

    PushRelabel pr(sink + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &grid[i][j]);
        }
    }

    for (int i = 0; i < k; ++i) {
        scanf(" %d", &costs[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int node = get_node(i, j);

            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                    int dst = get_node(nx, ny);
                    pr.add_edge(node | 1, dst, oo);
                }
            }

            if (grid[i][j] == 'B') {
                pr.add_edge(node | 1, sink, oo);
                grid[i][j] = '.';
            }

            ll cap = grid[i][j] == '.' ? oo : costs[grid[i][j] - 'a'];
            pr.add_edge(node, node | 1, cap);

            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                pr.add_edge(src, node, oo);
            }
        }
    }

    ll ret = pr.maxflow(src, sink);

    printf("%lld\n", ret == oo ? -1 : ret);

    return 0;
}
