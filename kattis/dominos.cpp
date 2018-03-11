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

constexpr int MAXN = 100005;

vi val, comp, z, cont, in_deg;
int Time, ncomps;
template<class G, class F> 
int dfs(int j, G& g, F f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto& e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e, g, f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);

		f(cont, ncomps); cont.clear();
		ncomps++;
	}

	return val[j] = low;
}

template <typename F, typename G>
void scc(G& g, F f) {
    int n = g.size();
    val.assign(n, 0);
    comp.assign(n, -1);
    z.clear();
    Time = ncomps = 0;
    for (int i = 0; i < n; ++i) {
        if (comp[i] < 0) {
            dfs(i, g, f);
        }
    }

    in_deg.assign(ncomps, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<vector<int> > graph(n, vector<int>());
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            --u; --v;
            graph[u].push_back(v);
        }

        scc(graph, [](const vi& comp, int id) {});

        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                if (comp[u] != comp[v]) {
                    ++in_deg[comp[v]];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < ncomps; ++i)
            if (in_deg[i] == 0)
                ++ans;

        printf("%d\n", ans);
    }
    
    return 0;
}
