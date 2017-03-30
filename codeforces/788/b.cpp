#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1000006;
int n, m;

vector<pair<int, int> > edges;
vector<int> graph[MAXN];
int deg[MAXN];
bool has_loop[MAXN];
bool visit[MAXN];

void dfs(int node) {
    visit[node] = true;
    for (int child : graph[node]) {
        if (!visit[child]) {
            dfs(child);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &m);

    int self = 0;
    int norm = 0;

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        edges.push_back({u, v});

        if (u == v) {
            ++self;
            has_loop[u] = true;
        } else {
            ++norm;
            deg[u]++;
            deg[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 0 or has_loop[i]) {
            dfs(i);
            break;
        }
    }

    bool connected = true;
    for (int i = 0; i < m; ++i) {
        if (!visit[edges[i].first] or !visit[edges[i].second]) {
            connected = false;
            break;
        }
    }

    long long ans = 0LL;
    if (connected) {
        ans += 1LL * self * (self - 1LL) / 2LL;
        ans += 1LL * self * norm;
        for (int i = 1; i <= n; ++i) {
            ans += 1LL * deg[i] * (deg[i] - 1LL) / 2LL;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
