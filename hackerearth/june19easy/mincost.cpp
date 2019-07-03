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

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        vi p(n);
        vector<vector<pii>> graph(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            --p[i];

            if (i != p[i]) {
                graph[i].emplace_back(p[i], 0);
            }

            if (i) {
                graph[i - 1].emplace_back(i, 1);
                graph[i].emplace_back(i - 1, 1);
            }
        }

        deque<pii> q;
        q.emplace_front(0, 0);
        vi dist(n, -1);
        dist[0] = 0;
        while (!q.empty()) {
            int u = q.front().first;
            int ed = q.front().second;
            q.pop_front();

            if (dist[u] != ed) continue;

            for (auto& e : graph[u]) {
                int v = e.first;
                int w = e.second;
                if (dist[v] == -1 or ed + w < dist[v]) {
                    dist[v] = ed + w;
                    if (w) {
                        q.emplace_back(v, dist[v]);
                    } else {
                        q.emplace_front(v, dist[v]);
                    }
                }
            }
        }

        cout << dist[n - 1] << '\n';
    }
    
    return 0;
}
