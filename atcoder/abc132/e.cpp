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

    vector<vi> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        graph[u].push_back(v);
    }

    int src, sink;
    cin >> src >> sink;
    --src; --sink;

    vector<int> dist(3 * n, -1);
    queue<int> q;
    dist[3 * src] = 0;
    q.push(3 * src);

    while (!q.empty()) {
        int uk = q.front();
        q.pop();

        int u = uk / 3;
        int k = uk % 3;
        int l = (k + 1) % 3;

        for (int v : graph[u]) {
            int vl = 3 * v + l;
            if (dist[vl] == -1) {
                dist[vl] = dist[uk] + 1;
                q.push(vl);
            }
        }
    }

    if (dist[3 * sink] == -1) {
        cout << -1 << '\n';
    } else {
        cout << (dist[3 * sink] / 3) << '\n';
    }

    return 0;
}
