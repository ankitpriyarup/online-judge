#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vi c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<vi> graph(n);
    vi in_deg(n, 0);
    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        ++in_deg[t];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0)
            q.push(i);
    }

    vi top_sort;
    while (!q.empty()) {
        top_sort.push_back(q.front());
        q.pop();
        for (int u : graph[top_sort.back()]) {
            if (--in_deg[u] == 0) {
                q.push(u);
            }
        }
    }

    vector<double> dp(n, 0.0);
    while (!top_sort.empty()) {
        int u = top_sort.back();
        top_sort.pop_back();

        dp[u] = c[u];
        for (int v : graph[u]) {
            dp[u] = max(dp[u], dp[v]);
            dp[u] = max(dp[u], c[u] + 0.5 * dp[v]);
        }
    }

    cout << fixed << setprecision(12) << dp[0] << '\n';
    
    return 0;
}
