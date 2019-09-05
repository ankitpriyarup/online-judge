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
};

inline ll nC2(int x) {
    return 1LL * x * (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    int q;
    cin >> n >> q;

    using edge = tuple<int, int, int>;
    vector<edge> edges;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.emplace_back(w, u, v);
    }

    DSU uf(n);

    sort(all(edges));
    vector<pair<int, ll>> ans;
    ans.emplace_back(0, 0);

    for (int i = 0; i < edges.size();) {
        ll cur = ans.back().second;
        int j = i + 1;
        while (j < edges.size() and get<0>(edges[j]) == get<0>(edges[i]))
            ++j;

        for (int k = i; k < j; ++k) {
            int w, u, v;
            tie(w, u, v) = edges[k];

            cur -= nC2(uf.get_size(u));
            cur -= nC2(uf.get_size(v));
            int res = uf.merge(u, v);
            assert(res == 1);
            cur += nC2(uf.get_size(u));
        }

        ans.emplace_back(get<0>(edges[i]), cur);

        i = j;
    }

    while (q-- > 0) {
        int w;
        cin >> w;
        auto it = lower_bound(all(ans), pair<int, ll>{w + 1, -1LL});
        assert(it != begin(ans));
        it = prev(it);
        cout << it->second << ' ';
    }
    
    return 0;
}
