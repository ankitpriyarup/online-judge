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

constexpr int MAXN = 10004;
constexpr ll INF = 1e18;
int n, m, a, k;
vector<pii> graph[MAXN];
ll dist[MAXN];
bool safe[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%d %d %d %d", &n, &m, &a, &k) == 4) {
        if (n == 0) break;

        for (int u = 1; u <= n; ++u) {
            graph[u].clear();
            dist[u] = INF;
            safe[u] = true;
        }

        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
        int src;
        int safe_count = n;

        for (int i = 0; i < a; ++i) {
            scanf("%d", &src);
            pq.emplace(0LL, src);
            dist[src] = 0LL;
            if (safe[src]) {
                safe[src] = false;
                --safe_count;
            }

            ll cur_dist;
            while (!pq.empty()) {
                tie(cur_dist, u) = pq.top();
                pq.pop();

                if (cur_dist != dist[u])
                    continue;

                for (const auto& e : graph[u]) {
                    tie(v, w) = e;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.emplace(dist[v], v);

                        if (safe[v] and dist[v] < k) {
                            safe[v] = false;
                            --safe_count;
                        }
                    }
                }
            }

            printf("%d\n", safe_count);
        }
        printf("\n");
    }

    return 0;
}
