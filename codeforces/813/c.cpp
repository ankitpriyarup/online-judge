#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
int n;
vi tree[MAXN];
int par[MAXN];
int depth[MAXN];

void dfs(int u) {
    for (int v : tree[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

int search(int u) {
    int res = depth[u];
    for (int v : tree[u]) {
        if (v == par[u]) continue;
        res = max(res, search(v));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x;
    cin >> n >> x;
    --x;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // bob goes up as far as he can until alice is 1 behind him, then he goes to the deepest leaf he can.
    par[0] = -1;
    dfs(0);

    vi stk = {x};
    while (stk.back() != 0) {
        stk.push_back(par[stk.back()]);
    }

    int l = 0;
    int r = stk.size() - 1;

    while (l + 1 < r - 1) {
        l += 1;
        r -= 1;
    }

    int ans = search(stk[l]);
    cout << (2 * ans) << '\n';

    return 0;
}
