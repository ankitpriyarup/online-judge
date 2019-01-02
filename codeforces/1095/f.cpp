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
using edge = tuple<ll, int, int>;

constexpr int MAXN = 200005;
int n, m;
ll a[MAXN];
edge edges[MAXN];

multiset<pair<ll, int>> ms;
int uf[MAXN];

int find(int x) {
    return uf[x] = (x == uf[x] ? x : find(uf[x]));
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return 0;

    if (a[xr] < a[yr]) {
        uf[yr] = xr;
        auto it = ms.find({a[yr], yr});
        ms.erase(it);
    } else {
        uf[xr] = yr;
        auto it = ms.find({a[xr], xr});
        ms.erase(it);
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        uf[i] = i;
        ms.emplace(a[i], i);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        edges[i] = make_tuple(w, u, v);
    }
    sort(edges, edges + m);

    ll ans = 0LL;
    int cc = n;
    int ptr = 0;
    while (cc > 1) {
        ll ax, ay;
        int comp_a, comp_b;
        // find the two minimum as
        tie(ax, comp_a) = *ms.begin();
        tie(ay, comp_b) = *next(ms.begin());
        
        ll tot_comp = ax + ay;
        while (ptr < m and get<0>(edges[ptr]) <= tot_comp) {
            ll w;
            int u, v;
            tie(w, u, v) = edges[ptr];
            if (merge(u, v)) {
                --cc;
                ans += w;
            }

            ++ptr;
        }

        if (merge(comp_a, comp_b)) {
            --cc;
            ans += tot_comp;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
