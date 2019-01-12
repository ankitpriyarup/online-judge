#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

// 0 black, 1 white
int dfs(const vector<vi>& tree, vector<array<int, 2>>& dp, int u, int k, int p = -1) {
    int& res = dp[u][k];
    if (res != -1)
        return res;

    res = 1;
    for (int v : tree[u]) {
        if (v == p) continue;

        int child = 0;
        if (k) {
            child = dfs(tree, dp, v, 0, u);
        }

        child += dfs(tree, dp, v, 1, u);
        if (child >= MOD)
            child -= MOD;

        res = 1LL * res * child % MOD;
    }

    // cout << "dfs(" << u << ", " << k << ") = " << res << '\n';
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<vi> tree(n);
    vector<array<int, 2>> dp(n);
    dp[0][0] = dp[0][1] = -1;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);

        dp[i][0] = dp[i][1] = -1;
    }

    int ans = dfs(tree, dp, 0, 0) + dfs(tree, dp, 0, 1);
    if (ans >= MOD)
        ans -= MOD;

    cout << ans << '\n';
    
    return 0;
}
