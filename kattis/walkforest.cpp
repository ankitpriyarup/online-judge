#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 1003;

int n, m;
vector<pair<int, int> > graph[MAXN];
ll dist[MAXN];

void dijkstra() {
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push({0, 2});
    memset(dist, -1, sizeof(dist));
    dist[2] = 0;

    while (!pq.empty()) {
        ll cur_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cur_dist) {
            continue;
        }

        for (auto edge : graph[node]) {
            int child = edge.first;
            ll new_dist = cur_dist + edge.second;
            if (dist[child] == -1 or new_dist < dist[child]) {
                dist[child] = new_dist;
                pq.push({new_dist, child});
            }
        }
    }
}

ll dp[MAXN];

ll solve(int node) {
    if (dp[node] != -1) {
        return dp[node];
    }

    ll ret = 0LL;
    for (auto edge : graph[node]) {
        int child = edge.first;
        if (dist[child] < dist[node]) {
            ret += solve(child);
        }
    }

    return dp[node] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &m);
        for (int i = 1; i <= n; ++i) {
            graph[i].clear();
        }
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        dijkstra();
        memset(dp, -1, sizeof(dp));
        dp[2] = 1;
        printf("%lld\n", solve(1));
    }
    return 0;
}
