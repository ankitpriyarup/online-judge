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

constexpr int INF = 1e8 + 89;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q;
    while (scanf(" %d %d %d", &n, &m, &q) == 3) {
        if (!n) break;

        vector<edge> edges;
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf(" %d %d %d", &u, &v, &w);
            edges.emplace_back(u, v, w);
        }

        vector<vector<char>> conn(n, vector<char>(n, 0));
        vector<vector<char>> is_inf(n, vector<char>(n, 0));
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; ++i) {
            conn[i][i] = true;
            dist[i][i] = 0;
        }

        for (int s = 0; s < n; ++s) {
            for (int i = 0; i < n - 1; ++i) {
                for (auto& e : edges) {
                    tie(u, v, w) = e;
                    if (!conn[s][u]) continue;
                    conn[s][v] = true;
                    dist[s][v] = min(dist[s][v], dist[s][u] + w);
                }
            }
        }

        for (int s = 0; s < n; ++s) {
            for (int i = 0; i < n; ++i) {
                for (auto& e : edges) {
                    tie(u, v, w) = e;
                    if (!conn[s][u]) continue;
                    if (dist[s][u] + w < dist[s][v]) {
                        dist[s][v] = dist[s][u] + w;
                        is_inf[s][v] = true;
                    }
                }
            }
        }

        while (q-- > 0) {
            scanf(" %d %d", &u, &v);
            if (!conn[u][v]) {
                printf("Impossible\n");
            } else if (is_inf[u][v]) {
                printf("-Infinity\n");
            } else {
                printf("%d\n", dist[u][v]);
            }
        }

        printf("\n");
    }
    
    return 0;
}
