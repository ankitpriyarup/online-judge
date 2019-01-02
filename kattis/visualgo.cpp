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

int solve(int u, const vector<vector<int>>& dag, vector<int>& memo) {
    if (memo[u] != -1)
        return memo[u];

    int res = 0;
    for (int v : dag[u]) {
        res += solve(v, dag, memo);
    }

    return memo[u] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int s, t;
    cin >> s >> t;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, s);

    constexpr int INF = 1e9 + 7;
    vector<int> dist(n, INF);
    dist[s] = 0;
    while (!pq.empty()) {
        int cur_dist, u;
        tie(cur_dist, u) = pq.top();
        pq.pop();
        if (dist[u] != cur_dist) continue;

        for (auto& e : graph[u]) {
            int v, w;
            tie(v, w) = e;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    vector<vector<int>> dag(n);
    for (int u = 0; u < n; ++u) {
        for (auto& e : graph[u]) {
            int v, w;
            tie(v, w) = e;
            if (dist[u] + w == dist[v]) {
                dag[u].push_back(v);
            }
        }
    }

    vector<int> memo(n, -1);
    memo[t] = 1;
    int ans = solve(s, dag, memo);

    printf("%d\n", ans);
    return 0;
}
