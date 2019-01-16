#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct DSU {
    int n;
    // uf[x] = parent of x or negative size of component
    vector<int> uf;
    DSU(int n): n(n) {
        uf.assign(n, -1);
    }

    int find(int x) {
        return uf[x] < 0 ? x : (uf[x] = find(uf[x]));
    }

    int merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return 0;

        if (uf[yr] < uf[xr]) {
            uf[yr] += uf[xr];
            uf[xr] = yr;
        } else {
            uf[xr] += uf[yr];
            uf[yr] = xr;
        }

        return 1;
    }

    vector<vi> get_comps() {
        vector<vi> comps;

        vi comp_id(n, -1);
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            if (comp_id[root] == -1) {
                comp_id[root] = comps.size();
                comps.push_back(vi());
            }

            comps[comp_id[root]].push_back(i);
        }

        return comps;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    using edge = tuple<int, int, int, int>;
    vector<edge> edges;
    for (int i = 0; i < p; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.emplace_back(w, u, v, 0);
    }
    
    for (int i = 0; i < q; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.emplace_back(w, u, v, 1);
    }
    sort(all(edges));

    ll tot_cost = 0LL;
    ll mst_cost = 0LL;

    DSU planet_dsu(m);
    DSU city_dsu(n);

    int planets = n;
    int cities = m;
    for (auto& e : edges) {
        int w, u, v, k;
        tie(w, u, v, k) = e;

        // cout << "Considering edge " << (u + 1) << " " << (v + 1) << " " << w << " " << k << '\n';
        if (k == 0) {
            // connects (e, u) and (e, v)
            tot_cost += 1LL * n * w;
            if (planet_dsu.merge(u, v)) {
                // cout << "Taking " << planets << " copies" << '\n';
                mst_cost += 1LL * planets * w;
                --cities;
            }
        } else {
            tot_cost += 1LL * m * w;
            if (city_dsu.merge(u, v)) {
                // cout << "Taking " << cities << " copies" << '\n';
                mst_cost += 1LL * cities * w;
                --planets;
            }
        }
    }

    // cout << "tot: " << tot_cost << '\n';
    // cout << "mst: " << mst_cost << '\n';
    cout << (tot_cost - mst_cost) << '\n';

    return 0;
}
