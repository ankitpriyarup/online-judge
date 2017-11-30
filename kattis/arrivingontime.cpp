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
int n, m, s;

struct tram {
    int dest;
    ll t0, p, d;
};
vector<tram> graph[MAXN];
ll dist[MAXN];

ll dijkstra(ll init_dist) {
    memset(dist, -1, sizeof(dist));
    dist[0] = init_dist;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push({init_dist, 0});

    while (!pq.empty()) {
        ll cur_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] != cur_dist) continue;

        for (tram t : graph[u]) {
            // find min value > cur_dist of the form
            // t0 + k p
            ll k = max(0LL, cur_dist - t.t0) / t.p;
            ll leave_time = t.t0 + k * t.p;
            while (leave_time < cur_dist)
                leave_time += t.p;

            ll dest_time = leave_time + t.d;
            if (dist[t.dest] == -1 or dest_time < dist[t.dest]) {
                dist[t.dest] = dest_time;
                pq.push({dest_time, t.dest});
            }
        }
    }

    return dist[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &s);
    int u, v, t0, p, d;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d %d", &u, &v, &t0, &p, &d); graph[u].push_back({v, t0, p, d});
    }

    ll min_time = dijkstra(0);
    if (min_time == -1 or min_time > s) {
        printf("impossible\n");
        return 0;
    }

    ll lo = 0;
    ll hi = s + 1;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (dijkstra(mid) <= s) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%lld\n", lo);
    
    return 0;
}
