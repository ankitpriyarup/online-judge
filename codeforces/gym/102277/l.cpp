#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int n;
vi tree[MAXN];
int tin[MAXN], tout[MAXN];

int m[MAXN];
ll bonuses[4 * MAXN];
ll lazy[4 * MAXN];

void push(int node) {
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];

    lazy[node] = 0;
}

void add_bonus(int node, int l, int r, int ql, int qr, int b) {
    if (qr < l or r < ql) {
        return;
    }

    if (ql <= l and r <= qr) {
        lazy[node] += b;
        return;
    }

    int mid = (l + r) / 2;
    push(node);
    add_bonus(2 * node, l, mid, ql, qr, b);
    add_bonus(2 * node + 1, mid + 1, r, ql, qr, b);
}

void solve(int node, int l, int r, int idx) {
    assert(l <= idx and idx <= r);

    if (l == r) {
        bonuses[idx] += lazy[node] * m[idx];
        lazy[node] = 0;

        return;
    }

    int mid = (l + r) / 2;
    push(node);
    if (idx <= mid) {
        return solve(2 * node, l, mid, idx);
    } else {
        return solve(2 * node + 1, mid + 1, r, idx);
    }
}

void dfs(int u, int& timer) {
    tin[u] = timer++;
    for (int v : tree[u]) {
        dfs(v, timer);
    }
    tout[u] = timer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, s;
    cin >> q >> s;
    // op, i, (M/B/-1)
    using query = tuple<int, int, int>;
    vector<query> queries;

    n = 1;
    while (q-- > 0) {
        int op, u;
        cin >> op >> u;
        --u;

        int x = -1;
        if (2 <= op and op <= 3)
            cin >> x;

        if (op == 1) {
            tree[u].push_back(n);
            x = n;
            ++n;
        }

        queries.emplace_back(op, u, x);
    }

    int timer = 0;
    dfs(0, timer);
    for (int i = 0; i < n; ++i) {
        m[i] = s;
        // cout << "node tin tout " << i << ' ' << tin[i] << ' ' << tout[i] << '\n';
    }

    for (auto& query : queries) {
        int op, u, x;
        tie(op, u, x) = query;

        // cout << op << ' ' << u << ' ' << x << '\n';

        if (op == 1) {
            solve(1, 0, n - 1, tin[x]);
            bonuses[tin[x]] = 0;
        } else if (op == 2) {
            solve(1, 0, n - 1, tin[u]);
            m[tin[u]] = x;
        } else if (op == 3) {
            add_bonus(1, 0, n - 1, tin[u], tout[u] - 1, x);
        } else {
            solve(1, 0, n - 1, tin[u]);
            cout << bonuses[tin[u]] << '\n';
        }

        /*
        cout << "m: ";
        for (int i = 0; i < n; ++i) {
            cout << m[tin[i]] << ' ';
        }
        cout << '\n';

        cout << "ans: ";
        for (int i = 0; i < n; ++i) {
            cout << bonuses[tin[i]] << ' ';
        }
        cout << '\n';
        */
    }

    return 0;
}
