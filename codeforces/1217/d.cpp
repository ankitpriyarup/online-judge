#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 5003;
int n, m;
vector<pair<int, int>> graph[MAXN];
int ans[MAXN];
bool vis[MAXN];
bool in_stack[MAXN];

void dfs(int u) {
    in_stack[u] = true;
    for (auto& e : graph[u]) {
        int v = e.first;
        int idx = e.second;

        if (in_stack[v]) {
            // back edge
            ans[idx] = 2;
        } else {
            ans[idx] = 1;
            if (!vis[v]) {
                vis[v] = true;
                dfs(v);
            }
        }
    }

    in_stack[u] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[u].emplace_back(v, i);
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }

    int k = *max_element(ans, ans + n);
    cout << k << '\n';
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}
