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
#include <numeric>
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
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

vi match;
vector<bool> seen;
bool find(int j, const vector<vi>& g) {
    if (match[j] == -1) return 1;
    seen[j] = 1; int di = match[j];
    for (auto& e : g[di]) {
        if (!seen[e] && find(e, g)) {
            match[e] = di;
            return 1;
        }
    }

    return 0;
}

int dfs_matching(const vector<vi>& g, int n, int m) {
    match.assign(m, -1);
    for (int i = 0; i < n; ++i) {
        seen.assign(m, 0);
        for (auto& j : g[i]) {
            if (find(j, g)) {
                match[j] = i;
                break;
            }
        }
    }

    return m - (int)count(begin(match), end(match), -1);
}

constexpr int MAXN = 1003;
constexpr int MAXC = 333;
constexpr ll INF = 1e16;
int n, m, c;
int client[MAXC];
vector<pii> graph[MAXN];
ll dist[MAXC][MAXN];

void dijkstra(int client_id) {
    int src = client[client_id];
    for (int i = 0; i < n; ++i)
        dist[client_id][i] = INF;

    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int>>> pq;
    pq.emplace(0LL, src);
    dist[client_id][src] = 0LL;
    ll cur_dist;
    int u, v, w;
    while (!pq.empty()) {
        tie(cur_dist, u) = pq.top();
        pq.pop();

        if (dist[client_id][u] != cur_dist) continue;
        for (auto& e : graph[u]) {
            tie(v, w) = e;
            ll next_dist = cur_dist + w;
            if (next_dist < dist[client_id][v]) {
                dist[client_id][v] = next_dist;
                pq.emplace(next_dist, v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d %d", &n, &m, &c);
    ++c;
    client[0] = 0;
    for (int i = 1; i < c; ++i) {
        scanf(" %d", &client[i]);
    }

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        graph[u].emplace_back(v, w);
    }

    for (int i = 0; i < c; ++i) {
        dijkstra(i);
    }

    // build the flow graph
    vector<vi> graph(c);
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i == j) continue;

            if (dist[0][client[j]] == dist[0][client[i]] + dist[i][client[j]]) {
                graph[i].push_back(j);
            }
        }
    }

    int res = c - dfs_matching(graph, c, c);

    printf("%d\n", res);

    return 0;
}
