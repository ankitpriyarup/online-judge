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

constexpr int INF = 1e8 + 89;
constexpr int MAXN = 155;
bool conn[MAXN][MAXN];
bool is_inf[MAXN][MAXN];
int dist[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q;
    while (scanf(" %d %d %d", &n, &m, &q) == 3) {
        if (!n) break;

        memset(conn, 0, sizeof(conn));
        memset(is_inf, 0, sizeof(is_inf));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = INF;
            }

            conn[i][i] = true;
            dist[i][i] = 0;
        }

        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf(" %d %d %d", &u, &v, &w);
            conn[u][v] = true;
            dist[u][v] = min(dist[u][v], w);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!conn[i][k] or !conn[k][j])
                        continue;
                    conn[i][j] = true;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!conn[i][k] or !conn[k][j])
                        continue;
                    if (dist[k][k] < 0 
                            or is_inf[i][k] 
                            or is_inf[k][j] 
                            or dist[i][k] + dist[k][j] < dist[i][j]) {
                        is_inf[i][j] = true;
                        dist[i][j] = -INF;
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
