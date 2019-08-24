#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
vi tree[MAXN];
ll dp[MAXN];

void dfs(int u, int p) {
    for (int v : tree[u]) {
        if (v == p) continue;

        dp[v] += dp[u];
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    while (q-- > 0) {
        int u, x;
        cin >> u >> x;
        --u;
        dp[u] += x;
    }

    dfs(0, -1);

    for (int i = 0; i < n; ++i) {
        cout << dp[i] << ' ';
    }
    
    return 0;
}
