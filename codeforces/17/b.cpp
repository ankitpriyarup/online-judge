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

    int n;
    cin >> n;
    vi q(n);
    for (int i = 0; i < n; ++i)
        cin >> q[i];
    int m;
    cin >> m;

    vector<vector<pii>> pars(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        pars[v].emplace_back(u, w);
    }

    // this is directed MST.
    // For each node, choose the cheapest parent
    // Proof that graph is connected if possible
    // every node has a parent if possible
    int solo = 0;
    int ans = 0;
    constexpr int INF = 1e9 + 7;
    for (int u = 0; u < n; ++u) {
        int v, w;
        int cost = INF;
        for (auto& p : pars[u]) {
            tie(v, w) = p;
            cost = min(cost, w);
        }

        if (cost == INF)
            ++solo;
        else
            ans += cost;
    }

    cout << (solo == 1 ? ans : -1);

    return 0;
}
