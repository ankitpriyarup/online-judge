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
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100005;
int n, m;
vector<pii> graph[MAXN];
ll dist[MAXN];

// cannot go from i to bad[i]
int bad[MAXN];

int previous[MAXN];

void dijkstra() {
    // Run reverse dijkstra, keep track of prev

    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push({0, 1});
    ll cur_dist, u;
    while (!pq.empty()) {
        tie(cur_dist, u) = pq.top();
        pq.pop();
        if (cur_dist > dist[u]) continue;
        for (auto& e : graph[u]) {
            ll new_dist = cur_dist + e.second;
            int v = e.first;
            if (dist[v] == -1 or new_dist < dist[v]) {
                bad[v] = u;
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

void dfs(int u, int par) {
    for (auto& e : graph[u]) {
        if (e.first == par or e.first == bad[u]) {
            continue;
        }
        if (previous[e.first] == -1) {
            previous[e.first] = u;
            dfs(e.first, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra();

    memset(previous, -1, sizeof(previous));
    dfs(0, -1);

    if (previous[1] == -1) {
        printf("impossible\n");
        return 0;
    }

    vector<int> stk;
    u = 1;
    while (u != 0) {
        stk.push_back(u);
        u = previous[u];
    }

    stk.push_back(0);

    printf("%d", stk.size());
    reverse(begin(stk), end(stk));
    for (int x : stk) {
        printf(" %d", x);
    }
    printf("\n");

    return 0;
}
