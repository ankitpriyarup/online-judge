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

constexpr int MAXN = 100005;
int n;
vector<pii> tree[MAXN];
ll depth[MAXN];

void dfs(int u, int par = -1) {
    for (pii& e : tree[u]) {
        if (e.first == par) continue;
        depth[e.first] = depth[u] + e.second;
        dfs(e.first, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int u, v, w;
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
        ans += w;
    }

    ans *= 2LL;

    depth[1] = 0;
    dfs(1);

    ll deep = 0;
    for (int u = 1; u <= n; ++u)
        deep = max(deep, depth[u]);
    
    cout << (ans - deep) << '\n';
    return 0;
}
