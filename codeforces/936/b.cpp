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
using vi = vector<int>;

constexpr int MAXN = 200005;
int n, m;

bool vis[MAXN][2];
int previous[MAXN][2];
template<class G>
void bfs(G& g, int src) {
    vis[src][0] = true;
    queue<pii> q;
    q.emplace(src, 0);
    int u, k;

    while (!q.empty()) {
        tie(u, k) = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!vis[v][1 ^ k]) {
                vis[v][1 ^ k] = true;
                q.emplace(v, 1 ^ k);
                previous[v][1 ^ k] = u;
            }
        }
    }
}

bool in_stk[MAXN];
template <class G>
bool find_loop(G& g, int u) {
    vis[u][0] = true;
    in_stk[u] = true;
    bool res = false;
    for (int v : g[u]) {
        if (!vis[v][0]) {
            res |= find_loop(g, v);
        } else if (in_stk[v]) {
            res = true;
        }
    }

    in_stk[u] = false;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    vector<vi> graph(n + 1, vector<int>());
    for (int u = 1; u <= n; ++u) {
        int k, v;
        scanf("%d", &k);
        while (k-- > 0) {
            scanf("%d", &v);
            graph[u].push_back(v);
        }
    }

    int src;
    scanf("%d", &src);
    memset(vis, 0, sizeof(vis));
    bfs(graph, src);
    bool found = false;
    int cur = -1;
    for (int u = 1; u <= n; ++u) {
        if (graph[u].empty() and vis[u][1]) {
            found = true;
            cur = u;
            break;
        }
    }

    if (found) {
        vector<int> stk;
        int k = 1;
        while (cur != src or k != 0) {
            stk.push_back(cur);
            cur = previous[cur][k];
            k = 1 - k;
        }

        stk.push_back(src);
        printf("Win\n");
        while (!stk.empty()) {
            printf("%d ", stk.back());
            stk.pop_back();
        }
        printf("\n");
    } else {
        memset(vis, 0, sizeof(vis));
        memset(in_stk, 0, sizeof(in_stk));
        if (find_loop(graph, src)) {
            printf("Draw\n");
        } else {
            printf("Lose\n");
        }
    }

    return 0;
}
