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
using edge = tuple<int, int, int>;

constexpr int MAXN = 16;
int n, m, k;
int adj[MAXN][MAXN];
int uf[MAXN];

void init(int cap) {
    for (int i = 0; i < cap; ++i)
        uf[i] = i;
}

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return false;
    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d %d %d", &n, &m, &k);
        memset(adj, -1, sizeof(adj));

        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf(" %d %d %d", &u, &v, &w);
            --u; --v;
            adj[u][v] = w;
            adj[v][u] = w;
        }

        int imp_mask = 0;
        for (int i = 0; i < k; ++i) {
            scanf(" %d", &u);
            --u;
            imp_mask |= (1 << u);
        }

        ll ans = 1e18;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if ((imp_mask & mask) != imp_mask) continue;

            vector<edge> edges;
            int comps = 0;
            for (int u = 0; u < n; ++u) {
                if ((mask & (1 << u)) == 0) continue;

                ++comps;
                for (int v = u + 1; v < n; ++v) {
                    if (adj[u][v] == -1 or ((mask & (1 << v)) == 0)) continue;

                    edges.emplace_back(adj[u][v], u, v);
                }
            }

            sort(begin(edges), end(edges));
            init(n);
            ll cost = 0LL;
            for (auto& e : edges) {
                tie(w, u, v) = e;
                if (merge(u, v)) {
                    cost += w;
                    --comps;
                }
            }

            if (comps == 1)
                ans = min(ans, cost);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
