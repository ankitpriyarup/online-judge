#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 300005;
constexpr int LOGN = 20;
int n, q;
int a[MAXN];
vector<pii> queries[MAXN];
int by_bit[LOGN];
int dp[MAXN][LOGN];
int ans[MAXN];
int ans2[MAXN];

void dfs(const vector<vi>& graph, vi& vis, int u) {
    vis[u] = 1;
    for (int v : graph[u]) {
        dfs(graph, vis, v);
    }
}

void brute() {
    return;
    for (int j = 0; j < LOGN; ++j) {
        by_bit[j] = n;
    }

    vector<vi> graph(n);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < LOGN; ++j) {
            if (a[i] & (1 << j)) {
                int k = by_bit[j];
                if (k < n) {
                    graph[i].push_back(k);
                    // cout << i << " -> " << k << '\n';
                }

                by_bit[j] = i;
            }
        }

        vi vis(n, 0);
        dfs(graph, vis, i);

        for (auto& query : queries[i]) {
            int r, idx;
            tie(r, idx) = query;

            ans2[idx] = vis[r];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        queries[l].emplace_back(r, i);
    }

    for (int j = 0; j < LOGN; ++j) {
        by_bit[j] = n;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < LOGN; ++j) {
            dp[i][j] = n;
        }

        for (int j = 0; j < LOGN; ++j) {
            if (a[i] & (1 << j)) {
                dp[i][j] = i;

                int k = by_bit[j];
                if (k < n) {
                    for (int j2 = 0; j2 < LOGN; ++j2) {
                        dp[i][j2] = min(dp[i][j2], dp[k][j2]);
                    }
                }
                by_bit[j] = i;
            }
        }

        for (auto& query : queries[i]) {
            int r, idx;
            tie(r, idx) = query;
            bool poss = false;
            for (int j = 0; j < LOGN; ++j) {
                if ((a[r] & (1 << j)) > 0 and dp[i][j] <= r) {
                    poss = true;
                    break;
                }
            }

            ans[idx] = poss;
        }
    }

    // brute();
    for (int i = 0; i < q; ++i) {
        if (ans[i]) {
            cout << "Shi\n";
        } else {
            cout << "Fou\n";
        }
        // cout << ans[i] << ' ' << ans2[i] << '\n';
        // assert(ans[i] == ans2[i]);
    }
    
    return 0;
}

