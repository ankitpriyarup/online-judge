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

constexpr int MAXN = 1003;
int n, m;
vector<int> graph[MAXN];
int dist[2][MAXN];

void bfs(int k, int s) {
    dist[k][s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[k][v] == -1) {
                dist[k][v] = dist[k][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int s, t;
    scanf(" %d %d %d %d", &n, &m, &s, &t);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i <= n; ++i) {
        sort(begin(graph[i]), end(graph[i]));
    }

    memset(dist, -1, sizeof(dist));
    bfs(0, s);
    bfs(1, t);

    int start = dist[0][t];
    assert(start == dist[1][s]);

    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v = u + 1; v <= n; ++v) {
            auto it = lower_bound(begin(graph[u]), end(graph[u]), v);
            if (it != end(graph[u]) and *it == v)
                continue;

            int new_dist = min(dist[0][u] + 1 + dist[1][v], dist[1][u] + 1 + dist[0][v]);
            if (new_dist >= start) {
                ++ans;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
