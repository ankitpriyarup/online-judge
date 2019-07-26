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

    int n; 
    ll l, r, c;
    cin >> n >> l >> r >> c;
    int src, dst;
    cin >> src >> dst;
    --src; --dst;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        --x;
    }

    vector<int> compressed(all(a));
    sort(all(compressed));
    compressed.erase(unique(all(compressed)), end(compressed));

    int m = compressed.size();
    vector<vector<int>> occ(m);
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(all(compressed), a[i]) - begin(compressed);
        occ[a[i]].push_back(i);
    }

    constexpr ll INF = 1e18;
    vector<ll> dist(n + m, INF);
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        ll cur_dist;
        int u;
        tie(cur_dist, u) = pq.top();
        pq.pop();

        if (dist[u] != cur_dist) {
            continue;
        }

        if (u < n) {
            if (u > 0 and dist[u - 1] > dist[u] + l) {
                dist[u - 1] = dist[u] + l;
                pq.emplace(dist[u - 1], u - 1);
            }
            if (u + 1 < n and dist[u + 1] > dist[u] + r) {
                dist[u + 1] = dist[u] + r;
                pq.emplace(dist[u + 1], u + 1);
            }
            if (dist[n + a[u]] > dist[u] + c) {
                dist[n + a[u]] = dist[u] + c;
                pq.emplace(dist[n + a[u]], n + a[u]);
            }
        } else {
            for (int v : occ[u - n]) {
                if (dist[v] > cur_dist) {
                    dist[v] = cur_dist;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }

    cout << dist[dst] << '\n';
   
    return 0;
}
