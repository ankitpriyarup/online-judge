#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

constexpr int MAXN = 103;
constexpr int INF = 1e9;
int n, m, q;
int adj[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            adj[i][j] = INF;
        }

        adj[i][i] = 0;
    }

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    while (q-- > 0) {
        scanf("%d %d %d", &u, &v, &w);
        if (min(adj[1][u] + w + adj[v][n], adj[1][v] + w + adj[u][n]) < adj[1][n]) {
            printf("%d\n", 1);
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    adj[i][j] = min(adj[i][j], adj[i][u] + w + adj[v][j]);
                    adj[i][j] = min(adj[i][j], adj[i][v] + w + adj[u][j]);
                }
            }
        } else {
            printf("%d\n", 0);
        }
    }

    return 0;
}
