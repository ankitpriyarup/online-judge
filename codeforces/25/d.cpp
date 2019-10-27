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

    int get_size(int x) {
        return -uf[find(x)];
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

    DSU dsu(n);

    vector<pii> dead;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (!dsu.merge(u, v)) {
            dead.emplace_back(u, v);
        }
    }

    vi reps;
    for (int i = 0; i < n; ++i) {
        if (dsu.uf[i] < 0) {
            reps.push_back(i);
        }
    }

    cout << reps.size() - 1 << '\n';
    for (int i = 1; i < reps.size(); ++i) {
        cout << dead[i - 1].first + 1 << ' ' << dead[i - 1].second + 1 << ' '
             << reps[i - 1] + 1 << ' ' << reps[i] + 1 << '\n';
    }
    
    return 0;
}
