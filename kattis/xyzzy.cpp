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
constexpr int INF = 1e8;
int n;
int energy[MAXN];
vector<int> graph[MAXN], rev[MAXN];
int dist[MAXN];
int first[MAXN];
bool vis[MAXN];
bool hit[MAXN];

void dfs(int u) {
    if (hit[u]) return;
    hit[u] = true;
    for (int v : rev[u]) {
        dfs(v);
    }
}

void bf() {
    for (int iter = 0; iter < n; ++iter) {
        for (int u = 1; u <= n; ++u) {
            if (!vis[u]) continue;

            for (int v : graph[u]) {
                int new_dist = dist[u] + energy[v];
                if (new_dist > 0 and new_dist > dist[v]) {
                    dist[v] = new_dist;
                    vis[v] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf(" %d", &n) == 1) {
        if (n == -1) break;

        for (int u = 1; u <= n; ++u) {
            int deg, v;

            graph[u].clear();
            rev[u].clear();
            scanf(" %d %d", &energy[u], &deg);
            for (int j = 0; j < deg; ++j) {
                scanf(" %d", &v);
                graph[u].push_back(v);
            }

            dist[u] = -INF;
            vis[u] = false;
            hit[u] = false;
        }

        for (int u = 1; u <= n; ++u) {
            for (int v : graph[u]) {
                rev[v].push_back(u);
            }
        }

        dfs(n);

        dist[1] = 100;
        vis[1] = true;
        bf();

        for (int u = 1; u <= n; ++u) {
            first[u] = dist[u];
        }

        bf();

        bool poss = dist[n] > 0;
        for (int u = 1; u <= n; ++u) {
            if (hit[u] and first[u] != dist[u])
                poss = true;
        }

        if (poss) {
            printf("winnable\n");
        } else {
            printf("hopeless\n");
        }
    }

    return 0;
}
