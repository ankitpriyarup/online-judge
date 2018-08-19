/*
USER: rednano1
PROG: tour
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <complex>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;
using ll = long long;

constexpr int MAXN = 103;
constexpr int INF = 1e8;
int n, m;
string names[MAXN];
map<string, int> inv;
vector<int> graph[MAXN];

/*
 * Idea: Min cost flow
 * Say edges have infinite capacity and vertices have capacity 1 (except start
 * and end, which have capacity 2). Then max flow through the graph is 2, and
 * cost gives us how many nodes we used
 */
// https://github.com/stjepang/snippets/blob/master/mcmf_dijkstra.cpp

namespace mcmf {
	const int MAXV = 2 * MAXN;
	const int MAXE = MAXV * MAXV;
	const ll oo = 1e18;

	int V, E;
	int last[MAXV], how[MAXV]; ll dist[MAXV], pi[MAXV];
	int next[MAXE], from[MAXE], adj[MAXE]; ll cap[MAXE], cost[MAXE];

	struct cmpf {
		bool operator () (int a, int b) {
			if (dist[a] != dist[b]) return dist[a] < dist[b];
			return a < b;
		}
	};
	set<int, cmpf> S;

	void init(int n) {
		V = n;
		E = 0;
		memset(last, -1, sizeof(last));
	}

	void edge(int x, int y, ll c, ll w) {
        // cout << "Edge from " << x << " to " << y << " with cap, cost " << c << ", " << w << '\n';
		from[E] = x; adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
		from[E] = y; adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
	}

	pair<ll, ll> run(int src, int sink) {
		ll total = 0;
		ll flow = 0;

        fill(pi, pi + V, oo);
		pi[src] = 0;

		for (;;) {
			bool done = true;
			for (int x = 0; x < V; ++x) 
                for (int e = last[x]; e != -1; e = next[e])
                    if (cap[e] && pi[adj[e]] > pi[x] + cost[e])
                        pi[adj[e]] = pi[x] + cost[e], done = false;

			if (done) break;
		}

		for (;;) {
            fill(dist, dist + V, oo);
			S.clear();

			dist[src] = 0;
			S.insert(src);

			while (!S.empty()) {
				int x = *S.begin();
				S.erase(S.begin());
				if (x == sink) break;

				for (int e = last[x]; e != -1; e = next[e]) {
					if (cap[e] == 0) continue;

					int y = adj[e];
					ll val = dist[x] + pi[x] + cost[e] - pi[y];

					if (val < dist[y]) {
						S.erase(y);
						dist[y] = val;
						how[y] = e;
						S.insert(y);
					}
				}
			}
			if (dist[sink] >= oo / 2) break;

			ll aug = cap[how[sink]];
			for (int i = sink; i != src; i = from[how[i]]) {
                // cout << "goes through node " << names[i >> 1] << endl;
				aug = min(aug, cap[how[i]]);
            }

            // cout << "Flow of cap " << aug << " found" << endl;

			for (int i = sink; i != src; i = from[how[i]]) {
				cap[how[i]] -= aug;
				cap[how[i]^1] += aug;
				total += cost[how[i]] * aug;
			}
			flow += aug;

            for (int i = 0; i < V; ++i)
                pi[i] = min(pi[i] + dist[i], oo);
		}

		return {total, flow};
	}
}

int main() {
    freopen("tour.in", "r", stdin);
    freopen("tour.out", "w", stdout);

    cin >> n >> m;

    mcmf::init(2 * n + 2);
    int src = 0;
    int sink = 2 * (n - 1) + 1;

    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        inv[names[i]] = i;

        if (i == 0 or i == n - 1) {
            mcmf::edge(2 * i, 2 * i + 1, 2, 0);
        } else {
            mcmf::edge(2 * i, 2 * i + 1, 1, -1);
        }
    }

    string a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (inv[a] < inv[b]) {
            mcmf::edge(2 * inv[a] + 1, 2 * inv[b], 1, 0);
        } else {
            mcmf::edge(2 * inv[b] + 1, 2 * inv[a], 1, 0);
        }
    }

    auto res = mcmf::run(src, sink);
    if (res.second == 2) {
        cout << (-res.first + 2) << '\n';
    } else {
        cout << 1 << '\n';
    }
    // cout << res.first << ' ' << res.second << endl;

    return 0;
}
