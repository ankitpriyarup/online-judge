#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 100005;
vector<int> dag[MAXN];
ll vis[MAXN];
ll dp_ans[MAXN];
ll dp_goal[MAXN];
ll in_deg[MAXN];

void dfs(ll u) {
    if (vis[u]) return;
    vis[u] = true;

    if (dag[u].empty()) {
        dp_goal[u] = 1;
        return;
    }

    for (int v : dag[u]) {
        dfs(v);
    }

    for (int v : dag[u]) {
        dp_goal[u] += dp_goal[v];
        while (dp_goal[u] >= MOD) {
            dp_goal[u] -= MOD;
        }

        dp_ans[u] += dp_goal[v] + dp_ans[v];
        while (dp_ans[u] >= MOD) {
            dp_ans[u] -= MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        dag[u].push_back(v);
        ++in_deg[v];
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            dfs(i);
            ans += dp_ans[i];
            while (ans >= MOD)
                ans -= MOD;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
