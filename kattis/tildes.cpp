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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q-- > 0) {
        char op;
        int u, v;
        cin >> op >> u;
        if (op == 't')  {
            cin >> v;
            --u; --v;
            dsu.merge(u, v);
        } else {
            cout << dsu.get_size(--u) << '\n';
        }
    }
    
    return 0;
}
