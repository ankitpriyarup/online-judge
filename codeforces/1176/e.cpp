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

    // find a spanning tree
    // choose all odd dists or even dists
    
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;
        vector<vi> graph(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vi dist(n, -1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = 1 + dist[u];
                    q.push(v);
                }
            }
        }

        int evens = 0;
        int odds = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] % 2 == 0) {
                ++evens;
            } else {
                ++odds;
            }
        }

        cout << min(evens, odds) << '\n';
        for (int i = 0; i < n; ++i) {
            if (dist[i] % 2 == (evens > odds)) {
                cout << (i + 1) << ' ';
            }
        }
        cout << '\n';

    }

    return 0;
}
