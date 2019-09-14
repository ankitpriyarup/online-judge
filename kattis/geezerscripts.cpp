#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int n;
ll a;
vector<pii> graph[MAXN];
ll atk[MAXN], health[MAXN];
ll dist[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll h;
    int m;
    cin >> a >> h;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v >> atk[i] >> health[i];
        --u; --v;
        graph[u].emplace_back(v, i);
    }

    priority_queue<pair<ll, int>> pq;
    pq.emplace(h, 0);
    memset(dist, -1, sizeof(dist));
    dist[0] = h;
    while (!pq.empty()) {
        ll cur_h = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // cout << u << ' ' << cur_h << '\n';

        if (cur_h != dist[u]) continue;

        for (auto& e : graph[u]) {
            int v = e.first;
            ll aa = atk[e.second];
            ll hh = health[e.second];

            ll swings = (hh + a - 1) / a;

            ll new_h = cur_h - (swings - 1) * aa;
            if (new_h > 0 and new_h > dist[v]) {
                dist[v] = new_h;
                pq.emplace(new_h, v);
            }
        }
    }

    if (dist[n - 1] < 0) {
        cout << "Oh no\n";
    } else {
        cout << dist[n - 1] << '\n';
    }

    return 0;
}
