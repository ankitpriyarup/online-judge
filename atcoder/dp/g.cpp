#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int dfs(const vector<vi>& dag, vi& dp, int u) {
    if (dp[u] != -1) {
        return dp[u];
    }

    dp[u] = 0;
    for (int v : dag[u]) {
        dp[u] = max(dp[u], 1 + dfs(dag, dp, v));
    }

    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vi> dag(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        dag[u].push_back(v);
    }

    vi dp(n, -1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dfs(dag, dp, i));
    }

    cout << ans << '\n';
    
    return 0;
}
