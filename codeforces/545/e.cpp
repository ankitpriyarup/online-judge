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

struct edge {
    int v, w, id;

    bool operator<(const edge& other) const {
        if (w != other.w)
            return w < other.w;

        return v < other.v;
    }
};

constexpr int MAXN = 300005;
int n, m;
vector<edge> graph[MAXN];
ll dist[MAXN];
bool vis[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w, i});
        graph[v].push_back({u, w, i});
    }

    int src;
    scanf("%d", &src);

    priority_queue<pair<ll, edge>, vector<pair<ll, edge> >, greater<pair<ll, edge> > > pq;

    pq.push({0LL, {src, 0, 0}});

    memset(dist, -1, sizeof(dist));
    dist[src] = 0LL;

    ll cur_dist;
    edge e;

    ll total = 0LL;
    vector<int> ans;

    while (!pq.empty()) {
        tie(cur_dist, e) = pq.top();
        pq.pop();

        if (cur_dist != dist[e.v] or vis[e.v])
            continue;

        vis[e.v] = true;

        if (e.id) {
            total += e.w;
            ans.push_back(e.id);
        }

        for (const edge& next_edge : graph[e.v]) {
            int v = next_edge.v;
            ll next_dist = next_edge.w + cur_dist;

            if (dist[v] == -1 or next_dist <= dist[v]) {
                dist[v] = next_dist;
                pq.push({dist[v], next_edge});
            }
        }
    }

    printf("%lld\n", total);
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}
