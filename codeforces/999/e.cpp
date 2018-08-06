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

// from KACTL
vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F>
int dfs(int j, G& g, F f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto& e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);

		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}

template<class G, class F> 
void scc(G& g, F f) {
	int n = static_cast<int>(g.size());
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	for (int i = 0; i < n; ++i)
        if (comp[i] < 0)
            dfs(i, g, f);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, src;
    cin >> n >> m >> src;

    --src;
    vector<vector<int>> graph(n);
    vector<vector<int>> rev(n);

    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        rev[v].push_back(u);
    }

    // answer is number of SCCs without any in degrees
    int res = 0;
    scc(graph, [](vi& comp) {});

    vector<char> vis(ncomps, false);
    vis[comp[src]] = true;
    for (int u = 0; u < n; ++u) {
        if (vis[comp[u]]) continue;

        int in_deg = 0;
        for (int v = 0; v < n; ++v) {
            if (comp[u] == comp[v]) {
                for (int x : rev[v]) {
                    if (comp[x] != comp[v]) {
                        ++in_deg;
                    }
                }
            }
        }

        vis[comp[u]] = true;
        res += in_deg == 0;
    }

    cout << res << '\n';

    return 0;
}
