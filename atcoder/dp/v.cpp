#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int n;
int mod;
int dp[2][MAXN];
vi tree[MAXN];

int sum(int a, int b) {
    int c = a + b;
    if (c >= mod)
        c -= mod;
    return c;
}

int prod(int a, int b) {
    return 1LL * a * b % mod;
}

void dfs_down(int u, int p = -1) {
    dp[0][u] = 1;
    for (int v : tree[u]) {
        if (v == p)
            continue;

        dfs_down(v, u);
        dp[0][u] = prod(dp[0][u], sum(1, dp[0][v]));
    }
}

void dfs_up(int u, int p = -1) {
    vi children;
    for (int v : tree[u]) {
        if (v == p) continue;
        children.push_back(v);
    }

    // dp[1][u] = 1 + dp[1][p[u]] * (1 + dp[0][v]) where v is a sibling of u
    int deg = children.size();
    vi prefs(deg), suffs(deg);
    for (int i = 0; i < deg; ++i) {
        int v = children[i];
        suffs[i] = prefs[i] = sum(1, dp[0][v]);
    }

    for (int i = 1; i < deg; ++i) {
        prefs[i] = prod(prefs[i - 1], prefs[i]);
    }
    for (int i = deg - 2; i >= 0; --i) {
        suffs[i] = prod(suffs[i + 1], suffs[i]);
    }

    for (int i = 0; i < deg; ++i) {
        int v = children[i];
        dp[1][v] = 1;
        if (i > 0) {
            dp[1][v] = prod(dp[1][v], prefs[i - 1]);
        }
        if (i + 1 < deg) {
            dp[1][v] = prod(dp[1][v], suffs[i + 1]);
        }

        dp[1][v] = prod(dp[1][v], dp[1][u]);
        dp[1][v] = sum(dp[1][v], 1);
        dfs_up(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> mod;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // dp[0][u] = ways to make tree rooted at u, only going down
    // dp[1][u] = ways to make tree with u as leaf
    //
    // dp[u] = dp[0][u] * dp[1][u] - 1
    dfs_down(0);
    dp[1][0] = 1;
    dfs_up(0);

    for (int u = 0; u < n; ++u) {
        int ans = prod(dp[0][u], dp[1][u]);
        cout << ans << '\n';
    }

    return 0;
}


/*
 * dp[0][1] = {{1}, {1, 2}, {1, 2, 3}}
 * dp[0][2] = {{2}, {2, 3}}
 * dp[0][3] = {{3}}
 * dp[1][1] = {{1}}
 * dp[1][2] = {{2}, {1, 2}}
 * dp[1][3] = {{3}, {2, 3}, {1, 2, 3}}
 */
