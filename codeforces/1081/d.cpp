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
using edge = tuple<int, int, int>;

constexpr int MAXN = 100005;
int n, m, k;
bool special[MAXN];
int uf[MAXN];
int ct[MAXN];

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return 0;
    uf[xr] = yr;
    ct[yr] += ct[xr];
    ct[xr] = 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        --x;
        special[x] = true;
    }

    for (int i = 0; i < n; ++i) {
        uf[i] = i;
        ct[i] = special[i];
    }

    vector<edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.emplace_back(w, u, v);
    }

    sort(begin(edges), end(edges));
    int ans = 0;
    for (auto& e : edges) {
        int u, v, w;
        tie(w, u, v) = e;
        if (merge(u, v)) {
            if (ct[find(u)] == k or ct[find(v)] == k) {
                ans = w;
                break;
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << ans << ' ';
    }
    
    return 0;
}
