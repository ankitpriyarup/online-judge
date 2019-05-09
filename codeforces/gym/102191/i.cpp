#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1000006;
constexpr int LOGN = 21;
int n, m;
vi tree[MAXN];
vi project[MAXN];
int st[LOGN][MAXN];
int depth[MAXN];

int timer = 0;
int tin[MAXN];

void dfs(int u) {
    tin[u] = timer++;
    for (int v : tree[u]) {
        st[0][v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

void gen_st() {
    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int i = 0; i <= n; ++i) {
            if (st[j][i] != -1) {
                st[j + 1][i] = st[j][st[j][i]];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);

    int d = depth[v] - depth[u];
    for (int j = 0; j < LOGN; ++j) {
        if ((1 << j) & d) {
            v = st[j][v];
        }
    }

    if (u == v) return u;
    for (int j = LOGN - 1; j >= 0; --j) {
        if (st[j][u] != st[j][v]) {
            u = st[j][u];
            v = st[j][v];
        }
    }

    return st[0][u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        project[x].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    // for the i-th projectect
    // everyone who manages someone who's going is going
    // sort the people on each projectect in dfs order
    // take intermediate lcas
    // then what?
    // between any two consecutive nodes its a straight line
    // so just sum the distances?
    memset(st, -1, sizeof(st));
    dfs(0);
    gen_st();

    /*
    for (int i = 0; i <= n; ++i) {
        cout << "depth[" << i << "] = " << depth[i] << '\n';
    }
    */

    auto cmp = [&](int a, int b) {
        return tin[a] < tin[b];
    };
    for (int i = 1; i <= m; ++i) {
        project[i].push_back(0);
        sort(all(project[i]), cmp);

        int k = project[i].size();
        int ans = 0;
        for (int j = 1; j < k; ++j) {
            int u = project[i][j - 1];
            int v = project[i][j];
            int l = lca(u, v);

            ans += depth[v] - depth[l];
        }

        cout << ans << ' ';
    }

    return 0;
}
