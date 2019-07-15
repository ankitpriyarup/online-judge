#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 102;
constexpr int MOD = 998244353;
int n, g;
string colors;
vi tree[MAXN];
int sz[MAXN];

// number of subtrees at i that have
// j nodes
// k red nodes (stop counting at 2)
// l black nodes (stop counting at 2)
int dp[MAXN][MAXN][3][3];
int ndp[MAXN][3][3];

void read() {
    cin >> n >> g;
    cin >> colors;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

void dfs(int u, int p) {
    if (colors[u] == 'B') {
        dp[u][1][0][1] = 1;
    } else {
        dp[u][1][1][0] = 1;
    }

    sz[u] = 1;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs(v, u);

        memset(ndp, 0, sizeof(ndp));

        for (int j2 = sz[v]; j2 >= 1; --j2) {
            for (int k2 = 0; k2 <= 2; ++k2) {
                for (int l2 = 0; l2 <= 2; ++l2) {
                    if (dp[v][j2][k2][l2] == 0) {
                        continue;
                    }

                    for (int j1 = sz[u]; j1 >= 1; --j1) {
                        for (int k1 = 0; k1 <= 2; ++k1) {
                            for (int l1 = 0; l1 <= 2; ++l1) {
                                if (dp[u][j1][k1][l1] == 0) {
                                    continue;
                                }

                                int j = j1 + j2;
                                int k = min(2, k1 + k2);
                                int l = min(2, l1 + l2);

                                ndp[j][k][l] += 1LL * dp[u][j1][k1][l1] * dp[v][j2][k2][l2] % MOD;
                                if (ndp[j][k][l] >= MOD) {
                                    ndp[j][k][l] -= MOD;
                                }
                            }
                        }
                    }
                }
            }
        }

        sz[u] += sz[v];
        for (int j = 1; j <= sz[u]; ++j) {
            for (int k = 0; k <= 2; ++k) {
                for (int l = 0; l <= 2; ++l) {
                    dp[u][j][k][l] += ndp[j][k][l];
                    if (dp[u][j][k][l] >= MOD) {
                        dp[u][j][k][l] -= MOD;
                    }
                }
            }
        }
    }
}

int fast() {
    memset(sz, 0, sizeof(sz));
    memset(dp, 0, sizeof(dp));
    dfs(0, -1);

    int ans = 0;
    for (int u = 0; u < n; ++u) {
        ans += dp[u][g][2][2];
        if (ans >= MOD)
            ans -= MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    read();
    int f = fast();
    cout << f << '\n';

    return 0;
}
