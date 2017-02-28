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

const int MAXN = 1003;
const int INF = 1e7;

int n, m;
vector<pair<int, int> > graph[MAXN];

long long bf_dist[MAXN];
int bf_points[MAXN];

// returns true if an edge was relaxed
bool relax() {
    bool ret = false;
    for (int i = 1; i <= n; ++i) {
        for (pair<int, int> edge : graph[i]) {
            int dest = edge.first;
            int weight = edge.second;

            long long new_dist = bf_dist[i] + weight;
            int new_points = bf_points[i] + 1;

            if (new_dist < bf_dist[dest]
                or (new_dist == bf_dist[dest] and new_points > bf_points[dest])) {
                bf_dist[dest] = new_dist;
                bf_points[dest] = new_points;

                ret = true;
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &m);

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, - w));
    }

    for (int i = 2; i <= n; ++i) {
        bf_dist[i] = INF;
        bf_points[i] = 0;
    }

    bf_dist[1] = 0;
    bf_points[1] = 1;

    for (int i = 0; i < n - 1; ++i) {
        relax();
    }

    if (relax()) {
        printf("%d\n", -1);
    } else {
        printf("%lld %d\n", -bf_dist[n], bf_points[n]);
    }

    return 0;
}
