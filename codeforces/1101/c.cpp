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

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;

        vector<pii> events;
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            events.emplace_back(l, i + 1);
            events.emplace_back(r + 1, -(i + 1));
        }

        sort(all(events));
        set<int> s;
        DSU dsu(n);
        for (auto& e : events) {
            int d = e.second;
            int id = abs(d) - 1;
            if (d < 0) {
                s.erase(id);
            } else {
                if (!s.empty()) {
                    int id2 = *begin(s);
                    dsu.merge(id, id2);
                }
                s.insert(id);
            }
        }

        vector<vi> comps = dsu.get_comps();
        if (comps.size() == 1) {
            cout << -1 << '\n';
        } else {
            vi ans(n, 0);
            int k = 1;
            for (const vi& v : comps) {
                for (int x : v)
                    ans[x] = k;
                k ^= 3;
            }

            for (int x : ans) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
