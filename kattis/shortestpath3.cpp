#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int INF = 1e9 + 7;

void solve(int n) {
    int m, q, s;
    cin >> m >> q >> s;

    vector<vector<pii>> graph(n);
    while (m-- > 0) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    vi dist(n, INF);
    vector<bool> can_reach(n, false);
    vector<bool> neg_inf(n, false);

    can_reach[s] = true;
    dist[s] = 0;
    for (int iter = 0; iter < n - 1; ++iter) {
        for (int u = 0; u < n; ++u) {
            if (!can_reach[u]) continue;
            for (auto& e : graph[u]) {
                int v, w;
                tie(v, w) = e;

                if (!can_reach[v]) {
                    can_reach[v] = true;
                    dist[v] = dist[u] + w;
                } else {
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }
        }
    }

    for (int iter = 0; iter < n - 1; ++iter) {
        for (int u = 0; u < n; ++u) {
            if (!can_reach[u]) continue;
            for (auto& e : graph[u]) {
                int v, w;
                tie(v, w) = e;

                if (neg_inf[u] or dist[u] + w < dist[v]) {
                    neg_inf[v] = true;
                }
            }
        }
    }

    while (q-- > 0) {
        int t;
        cin >> t;
        if (can_reach[t]) {
            if (neg_inf[t]) {
                cout << "-Infinity\n";
            } else {
                cout << dist[t] << '\n';
            }
        } else {
            cout << "Impossible\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        solve(n);
        cout << '\n';
    }
    
    return 0;
}
