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

constexpr int MAXN = 200005;
int n, r;
vector<int> tree[MAXN];
int dist[MAXN], par[MAXN], depth[MAXN];

void bfs(queue<int>& q) {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int child : tree[cur]) {
            if (dist[child] == -1) {
                dist[child] = dist[cur] + 1;
                q.push(child);
            }
        }
    }
}

void dfs(int node, int p = -1, int d = 0) {
    depth[node] = d;
    par[node] = p;
    for (int child : tree[node]) {
        if (child == p) continue;
        dfs(child, node, d + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &r);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(dist, -1, sizeof(dist));
    queue<int> q;
    for (int i = 0; i < r; ++i) {
        scanf("%d", &u);
        q.push(u);
        dist[u] = 0;
    }

    bfs(q);

    scanf("%d %d", &u, &v);
    dfs(1);
    int ans = min(dist[u], dist[v]);
    while (u != v) {
        if (depth[u] > depth[v]) {
            u = par[u];
            ans = min(ans, dist[u]);
        } else {
            v = par[v];
            ans = min(ans, dist[v]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
