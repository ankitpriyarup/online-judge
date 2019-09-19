#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

inline int check(char c) {
    if (c == 'R')
        return 2;
    else if (c == 'T')
        return 3;
    else if (c == 'S' or c == 'B')
        return 1;
    else
        return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<string> names(n);
    map<string, int> lookup;
    vi change(n);

    vector<vector<pii>> graph(4 * n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i] >> change[i];
        lookup[names[i]] = i;

        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (j == k) continue;
                int u = 4 * i + j;
                int v = 4 * i + k;

                graph[u].emplace_back(v, change[i]);
                graph[v].emplace_back(u, change[i]);
            }
        }
    }

    // cerr << "READ CITIES\n";

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string u_name, v_name, type;
        int w;

        cin >> u_name >> v_name >> type >> w;
        int u = lookup[u_name];
        int v = lookup[v_name];
        int t = check(type[0]);

        // cerr << "GOT " << u << ' ' << v << ' ' << t << ' ' << w << '\n';

        graph[4 * u + t].emplace_back(4 * v + t, w);
        graph[4 * v + t].emplace_back(4 * u + t, w);
    }

    // cerr << "READ INPUT\n";

    string src_name, sink_name;
    cin >> src_name >> sink_name;
    int src = lookup[src_name];

    vector<ll> dist(4 * n, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int j = 0; j < 4; ++j) {
        dist[4 * src + j] = 0;
        pq.emplace(0LL, 4 * src + j);
    }

    while (!pq.empty()) {
        ll cur_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] != cur_dist) {
            continue;
        }

        for (auto& e : graph[u]) {
            int v = e.first;
            int w = e.second;
            ll new_dist = cur_dist + w;
            if (dist[v] == -1 or new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    ll ans = 1e18;
    int sink = lookup[sink_name];
    for (int j = 0; j < 4; ++j) {
        ans = min(ans, dist[4 * sink + j]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
