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
using vi = vector<int>;

constexpr int MAXN = 202;
int n;
char grid[MAXN][MAXN];
const char* target = "CALI";

bool in_bounds(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < n;
}

namespace dinic {
	using llint = ll;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

	const int MAXV = 1000100;
	const int MAXE = 1000100;
	const llint oo = 1e18;

	int V, E;
	int last[MAXV], dist[MAXV], curr[MAXV];
	int next[MAXE], adj[MAXE]; llint cap[MAXE];

	void init(int n) {
		V = n;
		E = 0;
		REP(i, V) last[i] = -1;
	}

	void edge(int x, int y, llint c1, llint c2) {
		adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
		adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
	}

	llint push(int x, int sink, llint flow) {
		if (x == sink) return flow;

		for (int &e = curr[x]; e != -1; e = next[e]) {
			int y = adj[e];

			if (cap[e] && dist[x] + 1 == dist[y])
				if (llint f = push(y, sink, min(flow, cap[e])))
					return cap[e] -= f, cap[e^1] += f, f;
		}
		return 0;
	}

	llint run(int src, int sink) {
		llint ret = 0;
		for (;;) {
			REP(i, V) curr[i] = last[i];
			REP(i, V) dist[i] = -1;

			queue<int> Q;
			Q.push(src), dist[src] = 0;

			while (!Q.empty()) {
				int x = Q.front(); Q.pop();

				for (int e = last[x]; e != -1; e = next[e]) {
					int y = adj[e];
					if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
				}
			}
			if (dist[sink] == -1) break;

			while (llint f = push(src, sink, oo)) ret += f;
		}
		return ret;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    int src = 2 * n * n + 1;
    int sink = src + 1;
	dinic::init(sink + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int id = n * i + j;

            int val = 0;
            while (grid[i][j] != target[val])
                ++val;

			dinic::edge(2 * id, 2 * id + 1, 1, 0);
            if (val == 0) {
				dinic::edge(src, 2 * id, 1, 0);
            } else if (val == 3) {
				dinic::edge(2 * id + 1, sink, 1, 0);
                continue;
            }

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = i + dx;
                    int ny = j + dy;
                    if (in_bounds(nx, ny)) {
                        int nid = n * nx + ny;
                        if (grid[nx][ny] == target[val + 1]) {
							dinic::edge(2 * id + 1, 2 * nid, 1, 0);
                        }
                    }
                }
            }
        }
    }

    printf("%lld\n", dinic::run(src, sink));

    return 0;
}
