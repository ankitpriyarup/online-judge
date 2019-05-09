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

    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < i; ++j) {
            int cost = 0;
            for (int l = 0; l < k; ++l) {
                cost += s[i][l] != s[j][l];
            }

            edges.emplace_back(cost, i, j);
        }
    }

    DSU dsu(n);
    sort(all(edges));

    int cost = 0;
    vector<pii> ans;
    for (auto& e : edges) {
        int w, u, v;
        tie(w, u, v) = e;
        if (dsu.merge(u, v)) {
            cost += w;
            ans.emplace_back(u, v);
        }
    }

    cout << cost << '\n';
    for (auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
    
    return 0;
}
