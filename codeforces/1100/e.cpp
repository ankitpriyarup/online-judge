#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using edge = tuple<int, int, int>;

pair<bool, vi> works(const vector<edge> edges, int n, int k) {
    vector<vi> graph(n);
    vi later;
    vi in_deg(n, 0);
    for (int i = 0; i < edges.size(); ++i) {
        int u, v, c;
        tie(u, v, c) = edges[i];
        if (c <= k) {
            // undirected
            later.push_back(i);
        } else {
            // directed
            graph[u].push_back(v);
            ++in_deg[v];
        }
    }

    // try and do a top sort
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    int timer = 0;
    vi tin(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        tin[u] = timer++;
        for (int v : graph[u]) {
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (timer != n) {
        return {false, {}};
    }

    vi flipped;
    for (int x : later) {
        int u, v, c;
        tie(u, v, c) = edges[x];
        if (tin[u] > tin[v]) {
            flipped.push_back(x);
        }
    }

    return {true, flipped};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        edges.emplace_back(u, v, c);
    }

    int lo = -1;
    int hi = 1e9 + 7;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (works(edges, n, mid).first) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    vi flipped = works(edges, n, hi).second;
    cout << hi << ' ' << flipped.size() << '\n';
    for (int x : flipped) {
        cout << (x + 1) << ' ';
    }
    cout << '\n';

    return 0;
}
