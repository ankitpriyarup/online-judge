#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MAXN = 100005;
int n, m, start;
long long l;

vector<pair<int, long long> > graph[MAXN];
long long dist[MAXN];

typedef pair<long long, int> state;

void dijkstra() {
    // find the shortest path from the source to all nodes

    memset(dist, -1, sizeof(dist));
    priority_queue<state, vector<state>, greater<state> > pq;
    pq.push(make_pair(0LL, start));

    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        long long dist_here = cur.first;
        int pos = cur.second;

        if (dist[pos] != -1 and dist[pos] <= dist_here)
            continue;

        dist[pos] = dist_here;

        for (pair<int, long long> edge : graph[pos]) {
            int next_place = edge.first;
            long long next_dist = dist_here + edge.second;

            if (dist[next_place] == -1 or dist_here < dist[next_place]) {
                pq.push(make_pair(next_dist, next_place));
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &start);

    int u, v;
    long long w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %lld", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    scanf("%lld", &l);

    dijkstra();

    long long ans = 0;
    for (u = 1; u <= n; ++u) {
        // printf("City %d at dist %lld\n", u, dist[u]);
        if (dist[u] == l) {
            // printf("Silo at city %d\n", u);
            ++ans;
            continue;
        }

        if (dist[u] > l) {
            continue;
        }

        for (pair<int, long long> edge : graph[u]) {
            v = edge.first;
            w = edge.second;

            if (dist[u] + w <= l) {
                continue;
            }

            // edge case: the distance is the same from either side
            if (u < v and
                dist[u] < l and l < dist[u] + w and
                dist[v] < l and l < dist[v] + w and
                dist[u] + dist[v] + w == 2 * l) {
                // printf("Midpoint silo between %d and %d\n", u, v);
                ++ans;
            }

            // consider the point coming from u
            if (dist[u] < l and l < dist[u] + w) {
                // the point is l - dist[u] away from u
                long long u_dist = l - dist[u];
                // the point is dist[v] + w - u_dist away from v
                if (l < dist[v] + w - u_dist) {
                    // printf("Silo at distance %lld along edge between %d and %d\n", u_dist, u, v);
                    ++ans;
                }
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
