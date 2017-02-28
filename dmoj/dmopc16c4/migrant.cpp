#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 100005;
const int INF = 1e9 + MAXN;
int n, m;
vector<pair<int, int> > graph[MAXN];

int dist[MAXN];

void dijkstra() {
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(INF, 1));

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cur_dist = cur.first;
        int loc = cur.second;

        for (pair<int, int> edge : graph[loc]) {
            int next_loc = edge.first;
            int path_weight = min(cur_dist, edge.second);

            if (dist[next_loc] == INF or path_weight > dist[next_loc]) {
                dist[next_loc] = path_weight;
                pq.push(make_pair(path_weight, next_loc));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &m);

    int u, v, p;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &p);
        graph[u].push_back(make_pair(v, p));
        graph[v].push_back(make_pair(u, p));
    }

    dijkstra();

    puts("0");
    for (int i = 2; i <= n; ++i) {
        printf("%d\n", dist[i]);
    }
    return 0;
}
