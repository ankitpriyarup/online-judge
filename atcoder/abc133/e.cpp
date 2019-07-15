#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5;
int n, k;
vi tree[MAXN];

int dfs(int u, int p, int depth = 0, int siblings = 0) {
    // node cares about colors of: parent, grandparent, siblings
    int ans = max(0, k - min(depth, 2) - siblings);
    // cout << u << ' ' << ans << '\n';

    int children = 0;
    for (int v : tree[u]) {
        if (v == p) continue;

        ans = 1LL * ans * dfs(v, u, depth + 1, children) % MOD;
       // cout << u << ' ' << ans << '\n';
        ++children;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int ans = dfs(0, -1);
    cout << ans << '\n';
    
    return 0;
}
