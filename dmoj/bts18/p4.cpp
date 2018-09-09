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

bool valid(ll y) {
    // x = -1 +- sqrt(1 + 4y) / 2
    // 1 + 4y has to be a square of an odd
    ll v = 1LL + 4LL * y;
    ll s = sqrt(v);
    for (ll d = -200; d <= 200; ++d) {
        ll x = s + d;
        if (x % 2 == 1 and x * x == v) {
            return true;
        }
    }

    return false;
}

template <typename T>
pair<int, int> dfs(const T& tree, vector<bool>& vis, int u) {
    assert(!vis[u]);
    vis[u] = true;
    // max_height, diam
    vector<int> depths = {0, 0};
    int max_diam = 1;

    int dep, diam;
    for (int v : tree[u]) {
        if (vis[v]) continue;
        tie(dep, diam) = dfs(tree, vis, v);
        depths.push_back(dep);
        max_diam = max(max_diam, diam);
    }
    sort(begin(depths), end(depths));
    int b = depths.back();
    depths.pop_back();
    int a = depths.back();
    depths.pop_back();

    max_diam = max(max_diam, 1 + a + b);
    return {b + 1, max_diam};
}

template <typename T>
int diam(const T& tree, vector<bool>& vis, int src) {
    return dfs(tree, vis, src).second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<bool> good(n);
    ll y;
    for (int i = 0; i < n; ++i) {
        cin >> y;
        good[i] = valid(y);
    }

    int u, v;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        --u; --v;
        if (good[u] and good[v]) {
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (good[i] and !vis[i]) {
            ans = max(ans, diam(tree, vis, i));
        }
    }

    cout << ans << '\n';

    return 0;
}
