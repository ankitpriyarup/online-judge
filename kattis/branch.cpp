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

constexpr int MAXN = 5003;
constexpr ll INF = 1e18;
int n, b, s, r;

vector<ll> dijkstra(vector<vector<pii>>& graph) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[b + 1] = 0LL;
    pq.emplace(0LL, b + 1);

    ll cur_dist;
    int u;
    while (!pq.empty()) {
        tie(cur_dist, u) = pq.top();
        pq.pop();

        if (dist[u] != cur_dist)
            continue;

        for (pii& p : graph[u]) {
            int v = p.first;
            int w = p.second;

            ll new_dist = cur_dist + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    return dist;
}

ll d[MAXN];
ll memo[MAXN][MAXN];

ll solve(int start, int rem) {
    if (rem == 0 and start == b + 1)
        return 0;
    else if (rem == 0 or start > b)
        return INF;

    if (memo[start][rem] != -1)
        return memo[start][rem];

    ll res = INF;
    ll num_elems = b - start + 1;
    for (ll sz = 1; start + sz - 1 <= b and rem * sz <= num_elems; ++sz) {
        ll cost = (sz - 1LL) * (d[start + sz - 1] - d[start - 1]);
        res = min(res, cost + solve(start + sz, rem - 1));
    }

    return memo[start][rem] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d %d", &n, &b, &s, &r);
    vector<vector<pii> > graph(n + 1), rev(n + 1);

    int u, v, w;
    for (int i = 0; i < r; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].emplace_back(v, w);
        rev[v].emplace_back(u, w);
    }

    vector<ll> d1 = dijkstra(graph);
    vector<ll> d2 = dijkstra(rev);

    d[0] = 0LL;
    for (int i = 1; i <= b; ++i) {
        d[i] = d1[i] + d2[i];
    }

    sort(d + 1, d + b + 1);
    reverse(d + 1, d + b + 1);

    for (int i = 1; i <= b; ++i)
        d[i] += d[i - 1];

    /*
    for (int i = 0; i <= b; ++i)
        printf("%lld ", d[i] - (i ? d[i - 1] : 0LL));
    printf("\n");
    */

    memset(memo, -1, sizeof(memo));
    ll ans = solve(1, s);

    printf("%lld\n", ans);

    return 0;
}
