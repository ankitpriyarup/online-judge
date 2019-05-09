#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
int n;
vector<pii> tree[MAXN];
// both of these only go down
// dp[u][0] number of paths with 0 or more 0s, followed by 1s
// dp[u][1] only paths with 1s
int dp[MAXN][2];

void dfs1(int u, int p) {
    for (auto& e : tree[u]) {
        int v, w;
        tie(v, w) = e;
        if (v == p) continue;

        dfs1(v, u);
        if (w == 0) {
            dp[u][0] += dp[v][0] + 1;
        } else {
            dp[u][0] += dp[v][1] + 1;
            dp[u][1] += dp[v][1] + 1;
        }
    }
}

ll ans;
void dfs2(int u, int p, ll v0, ll v1) {
    ans += v0;
    for (auto& e : tree[u]) {
        int v, w;
        tie(v, w) = e;
        if (v == p) continue;

        if (w == 0) {
            dfs2(v, u, v0 + dp[u][0] - dp[v][0], 0);
        } else {
            ll nv1 = v1 + dp[u][1] - dp[v][1];
            dfs2(v, u, nv1, nv1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    dfs1(0, -1);
    ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[i][0];
    }

    dfs2(0, -1, 0, 0);

    cout << ans << '\n';

    return 0;
}
