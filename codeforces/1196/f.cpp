#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 200005;
vector<pii> graph[MAXN];

ll dist[MAXN];
int src[MAXN];

int k;
set<tuple<ll, int, int>> paths;

void dijkstra(int s) {
    using state = pair<ll, int>;
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.emplace(0, s);
    src[s] = s;
    dist[s] = 0;
    while (!pq.empty()) {
        ll cur_dist;
        int u;
        tie(cur_dist, u) = pq.top();
        pq.pop();

        if (cur_dist != dist[u])
            continue;

        // cout << (s + 1) << " -> " << (u + 1) << " = " << cur_dist << '\n';
        {
            int a = u;
            int b = s;
            if (a > b)
                swap(a, b);
            if (a < b)
                paths.emplace(cur_dist, a, b);
        }

        while (paths.size() > k) {
            paths.erase(prev(paths.end()));
        }

        if (paths.size() >= k and get<0>(*prev(end(paths))) < cur_dist)
            break;

        for (auto& e : graph[u]) {
            int v, w;
            tie(v, w) = e;

            ll new_dist = cur_dist + w;
            if (src[v] != s or (src[v] == s and dist[v] > new_dist)) {
                if (paths.size() >= k and get<0>(*prev(end(paths))) < new_dist)
                    continue;
                src[v] = s;
                dist[v] = new_dist;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; ++i) {
        sort(begin(graph[i]), end(graph[i]), [](const pii& a, const pii& b) {
            return a.second < b.second;
        });

        while (graph[i].size() >= 2 * k) {
            graph[i].pop_back();
        }
    }

    memset(src, -1, sizeof(src));
    for (int u = 0; u < n; ++u) {
        dijkstra(u);
    }

    cout << get<0>(*prev(end(paths))) << '\n';

    return 0;
}
