#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 10000;
int n;
vector<pii> tree[MAXN];
int deg[MAXN];
bool used_edge[MAXN], in_queue[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].emplace_back(v, i);
        tree[v].emplace_back(u, i);
        ++deg[u]; ++deg[v];
    }

    queue<int> q;
    for (int u = 0; u < n; ++u) {
        if (deg[u] <= 1) {
            q.push(u);
            in_queue[u] = true;
        }
    }

    vi c(n);
    for (auto& x : c) {
        cin >> x;
    }
    sort(all(c));

    ll tot = 0;
    vi ans(n, -1);
    for (int x : c) {
        int u = q.front();
        q.pop();
        // cout << "ans[" << u << "] = " << x << '\n';
        ans[u] = x;
        for (auto& e : tree[u]) {
            int v = e.first;
            int idx = e.second;
            if (!used_edge[idx]) {
                used_edge[idx] = true;
                tot += x;
                --deg[u]; --deg[v];
                // cout << "v: " << v << " deg[v] = " << deg[v] << '\n';
                if (deg[v] <= 1 and !in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }

    cout << tot << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
    
    return 0;
}
