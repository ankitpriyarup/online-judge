#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
using state = pair<long long, pair<int, int> >;

constexpr int MAXN = 50050;
int n, m, f, s, t;
vector<state> graph[2][MAXN];
ll dist[2][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d %d %d", &n, &m, &f, &s, &t);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);

        for (int k = 0; k < 2; ++k) {
            graph[k][u].push_back({w, {k, v}});
            graph[k][v].push_back({w, {k, u}});
        }
    }

    for (int i = 0; i < f; ++i) {
        scanf("%d %d", &u, &v);
        graph[0][u].push_back({0, {1, v}});
    }

    for (int i = 0; i < n; ++i) {
        graph[0][i].push_back({0, {1, i}});
    }

    priority_queue<state, vector<state>, greater<state> > pq;
    pq.push({0, {0, s}});

    memset(dist, -1, sizeof(dist));
    dist[0][s] = 0;
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        ll cur_dist = cur.first;
        int n1 = cur.second.first;
        int n2 = cur.second.second;

        if (dist[n1][n2] < cur_dist) {
            continue;
        }

        for (auto edge : graph[n1][n2]) {
            ll new_dist = cur_dist + edge.first;
            int nn1 = edge.second.first;
            int nn2 = edge.second.second;

            if (dist[nn1][nn2] == -1 or new_dist < dist[nn1][nn2]) {
                dist[nn1][nn2] = new_dist;
                pq.push({new_dist, {nn1, nn2}});
            }
        }
    }

    printf("%lld\n", min(dist[0][t], dist[1][t]));

    return 0;
}
