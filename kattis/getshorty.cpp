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

constexpr int MAXN = 20004;
int n, m;
vector<pair<int, ld> > graph[MAXN];
ld dist[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 and m == 0)
            break;

        int u, v;
        ld x;

        for (int i = 0; i < n; ++i) {
            dist[i] = 1e18;
            graph[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d %d %Lf", &u, &v, &x);
            graph[u].push_back({v, -log(x)});
            graph[v].push_back({u, -log(x)});
        }

        dist[0] = 0;
        priority_queue<pair<ld, int>, vector<pair<ld, int> >, greater<pair<ld, int> > > pq;
        pq.push({0.0L, 0});

        ld cur_dist;
        while (!pq.empty()) {
            tie(cur_dist, u) = pq.top();
            pq.pop();

            if (dist[u] < cur_dist)
                continue;

            for (auto& e : graph[u]) {
                int v = e.first;
                ld next_dist = cur_dist + e.second;
                if (next_dist < dist[v]) {
                    dist[v] = next_dist;
                    pq.push({next_dist, v});
                }
            }
        }

        printf("%.4Lf\n", exp(-dist[n - 1]));
    }

    return 0;
}
