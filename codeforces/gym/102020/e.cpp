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

constexpr int MAXN = 200005;
constexpr int MOD = 1e9 + 7;

int modpow(int b, int e) {
    if (e == 0) return 1;
    if (e & 1) return 1LL * b * modpow(b, e ^ 1) % MOD;
    return modpow(1LL * b * b % MOD, e >> 1);
}

int n;
vector<int> tree[MAXN];
int sz[MAXN];

void dfs_sz(int u, int p = -1) {
    sz[u] = 1;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int u, v;
    vector<pii> edges;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        edges.emplace_back(u, v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs_sz(1);
    int ans = 0;
    for (auto& e : edges) {
        tie(u, v) = e;
        int x = min(sz[u], sz[v]);
        int cur = 1LL * x * (n - x) % MOD;
        ans += cur;
        if (ans >= MOD)
            ans -= MOD;
    }

    int tot_paths = 1LL * n * (n + 1) % MOD;
    tot_paths = 1LL * tot_paths * ((MOD + 1) >> 1) % MOD;

    ans = 1LL * ans * modpow(tot_paths, MOD - 2) % MOD;

    cout << ans << '\n';

    return 0;
}
