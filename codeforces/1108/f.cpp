#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define DEBUG 0

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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    using edge = tuple<int, int, int>;

    vector<edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.emplace_back(w, u, v);
    }

    sort(all(edges));

    DSU dsu(n);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int j = i + 1;
        while (j < m and get<0>(edges[j]) == get<0>(edges[i]))
            ++j;

        if (DEBUG)
            cout << "Edges with weight " << get<0>(edges[i]) << '\n';
        set<int> verts;
        set<pii> e;
        for (int k = i; k < j; ++k) {
            int w, u, v;
            tie(w, u, v) = edges[k];
            if (DEBUG)
                cout << w << " " << u << " " << v << '\n';
            int xr = dsu.find(u);
            int yr = dsu.find(v);

            if (xr > yr)
                swap(xr, yr);

            if (DEBUG)
                cout << xr << " " << yr << '\n';
            if (xr == yr) continue;

            verts.insert(xr);
            verts.insert(yr);
            if (e.find({xr, yr}) != end(e))
                ++ans;
            e.emplace(xr, yr);
        }

        if (!verts.empty() and e.size() >= verts.size()) {
            int extra = (int)e.size() - ((int)verts.size() - 1);
            ans += extra;
        }

        for (auto& p : e) {
            int x, y;
            tie(x, y) = p;
            dsu.merge(x, y);
        }

        i = j - 1;
    }

    cout << ans << '\n';

    return 0;
}
