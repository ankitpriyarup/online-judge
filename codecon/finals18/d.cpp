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
using edge = tuple<int, int, int>;

constexpr int MAXN = 50;
int n, b;
bool has_bathroom[MAXN];
bool has_elevator[MAXN];
int dist[MAXN][2];

vector<edge> graph[MAXN][2];

void build_graph() {
    for (int i = 0; i < n; ++i) {
        if (i) {
            graph[i - 1][0].push_back(make_tuple(i, 0, 20));
            graph[i][0].push_back(make_tuple(i - 1, 0, 10));

            graph[i - 1][1].push_back(make_tuple(i, 1, 5));
            graph[i][1].push_back(make_tuple(i - 1, 1, 5));
        }

        if (has_elevator[i]) {
            graph[i][0].push_back(make_tuple(i, 1, 15));
            graph[i][1].push_back(make_tuple(i, 0, 0));
        }
    }
}

void dijkstra(int src) {
    priority_queue<edge, vector<edge>, greater<edge> > pq;
    pq.push(make_tuple(0, src, 0));
    for (int i = 0; i < n; ++i) {
        dist[i][0] = dist[i][1] = 1e9;
    }
    dist[src][0] = 0;

    int d, u, k;
    while (!pq.empty()) {
        tie(d, u, k) = pq.top();
        pq.pop();

        if (dist[u][k] < d) {
            continue;
        }

        for (edge& e : graph[u][k]) {
            int nd = d + get<2>(e);
            int v = get<0>(e);
            int kk = get<1>(e);
            if (nd < dist[v][kk]) {
                dist[v][kk] = nd;
                pq.push(make_tuple(nd, v, kk));
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &b);
    int x;
    for (int i = 0; i < b; ++i) {
        scanf("%d", &x);
        has_bathroom[x] = true;
    }

    int e;
    scanf("%d", &e);
    for (int i = 0; i < e; ++i) {
        scanf("%d", &x);
        has_elevator[x] = true;
    }

    int src;
    scanf("%d", &src);

    build_graph();
    dijkstra(src);

    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        if (has_bathroom[i]) {
            ans = min(ans, dist[i][0]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
