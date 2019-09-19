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
};

void solve() {
    int n, m, l, s;
    cin >> n >> m >> l >> s;

    ll ans = 1LL * (n - s) * l;

    DSU dsu(n);
    vi inits(s);
    for (auto& x : inits) {
        cin >> x;
        --x;
    }
    for (int i = 1; i < s; ++i) {
        dsu.merge(inits[i - 1], inits[i]);
    }

    vector<pair<int, pii>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.emplace_back(w, pii{u, v});
    }

    sort(all(edges));
    for (auto& e : edges) {
        int u, v;
        tie(u, v) = e.second;
        if (dsu.merge(u, v))
            ans += e.first;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
