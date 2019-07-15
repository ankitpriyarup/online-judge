#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using edge = tuple<int, int, int>;

constexpr int MAXN = 100005;
constexpr int LOGN = 19;
int n, q;
vector<edge> tree[MAXN];
int depth[MAXN];
int st[LOGN][MAXN];

vi queries[MAXN];
int query_color[MAXN], query_weight[MAXN];

int color_freq[MAXN], color_weight[MAXN];

ll dist_ans[MAXN];
int freq_ans[MAXN];

ll dist = 0;

void dfs1(int u, int p = -1) {
    for (auto& e : tree[u]) {
        int v = get<0>(e);
        if (v == p) continue;
        st[0][v] = u;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
    }
}

void gen_st() {
    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int i = 0; i < n; ++i) {
            if (st[j][i] != -1) {
                st[j + 1][i] = st[j][st[j][i]];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    for (int j = LOGN - 1; j >= 0; --j) {
        if ((depth[v] - depth[u]) & (1 << j)) {
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

void dfs2(int u, int p = -1) {
    for (int q_idx : queries[u]) {
        int idx = q_idx < 0 ? ~q_idx : q_idx;
        if (q_idx < 0) {
            dist_ans[idx] -= 2 * dist;
            dist_ans[idx] += 2 * color_weight[query_color[idx]];
            freq_ans[idx] -= 2 * color_freq[query_color[idx]];
        } else {
            dist_ans[idx] += dist;
            dist_ans[idx] -= color_weight[query_color[idx]];
            freq_ans[idx] += color_freq[query_color[idx]];
        }
    }

    for (auto& e : tree[u]) {
        int v, c, w;
        tie(v, c, w) = e;
        if (v == p) continue;

        dist += w;
        ++color_freq[c];
        color_weight[c] += w;

        dfs2(v, u);

        color_weight[c] -= w;
        --color_freq[c];
        dist -= w;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        --u; --v; --c;
        tree[u].emplace_back(v, c, w);
        tree[v].emplace_back(u, c, w);
    }

    memset(st, -1, sizeof(st));
    dfs1(0, -1);
    gen_st();

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> query_color[i] >> query_weight[i] >> u >> v;
        --query_color[i]; --u; --v;
        queries[u].push_back(i);
        queries[v].push_back(i);
        queries[lca(u, v)].push_back(~i);
    }

    dfs2(0, -1);
    for (int i = 0; i < q; ++i) {
        ll ans = dist_ans[i] + freq_ans[i] * query_weight[i];
        cout << ans << '\n';
    }

    return 0;
}
