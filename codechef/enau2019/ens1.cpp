#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e6 + 6;
int f_tree[MAXN];

int query(int x) {
    int res = 0;
    for (; x; x -= (x & -x)) {
        res += f_tree[x];
    }

    return res;
}

inline int query(int l, int r) {
    return query(r) - query(l - 1);
}

void update(int x, int v) {
    for (; x < MAXN; x += (x & -x)) {
        f_tree[x] += v;
    }
}

int n;
int a[MAXN];
vi tree[MAXN];
int tin[MAXN], tout[MAXN];

void dfs(int u, int p, int& timer) {
    tin[u] = timer++;

    for (int v : tree[u]) {
        if (v == p) continue;
        dfs(v, u, timer);
    }

    tout[u] = timer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            tree[i].clear();
        }

        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int timer = 1;
        dfs(0, -1, timer);

        for (int i = 0; i < n; ++i) {
            // cout << i << ' ' << tin[i] << ' ' << tout[i] << '\n';
            if (a[i]) {
                update(tin[i], 1);
            }
        }

        int q;
        cin >> q;
        while (q-- > 0) {
            int op, u;
            cin >> op >> u;
            --u;
            if (op == 1) {
                if (a[u]) {
                    update(tin[u], -1);
                } else {
                    update(tin[u], 1);
                }

                a[u] = 1 - a[u];
            } else {
                int ans = query(tin[u], tout[u] - 1) - a[u];
                cout << ans << '\n';
            }
        }

        for (int i = 0; i < n; ++i) {
            if (a[i])
                update(tin[i], -1);
        }
    }
    
    return 0;
}
