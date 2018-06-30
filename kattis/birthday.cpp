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

constexpr int MAXN = 102;
int n, m;
vector<pii> graph[MAXN];
bool vis[MAXN];

void dfs(int edge_id, int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (auto&& [v, id] : graph[u]) {
        if (id != edge_id)
            dfs(edge_id, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf(" %d %d", &n, &m) == 2) {
        if (!n and !m) break;

        for (int u = 0; u < n; ++u)
            graph[u].clear();

        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf(" %d %d", &u, &v);
            graph[u].emplace_back(v, i);
            graph[v].emplace_back(u, i);
        }

        bool has_bridge = false;
        for (int i = 0; i < m; ++i) {
            memset(vis, 0, sizeof(vis));
            dfs(i, 0);

            bool bridge = false;
            for (int u = 0; u < n; ++u) {
                bridge |= !vis[u];
            }

            if (bridge) {
                has_bridge = true;
                break;
            }
        }

        printf("%s\n", has_bridge ? "Yes" : "No");
    }

    return 0;
}
