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

constexpr int MAXN = 100005;
constexpr int MAXK = 102;
constexpr int INF = 1e9 + 7;
int n, m, k, s;
vector<int> graph[MAXN];
vector<int> has_good[MAXK];
int dist[MAXN][MAXK];

void bfs(int kind) {
    queue<int> q;
    for (int x : has_good[kind]) {
        dist[x][kind] = 0;
        q.push(x);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v][kind] == -1) {
                dist[v][kind] = dist[u][kind] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d %d %d", &n, &m, &k, &s);
    int g;
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &g);
        has_good[g].push_back(i);
    }

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(dist, -1, sizeof(dist));

    for (int i = 1; i <= k; ++i) {
        bfs(i);
    }

    for (int i = 1; i <= n; ++i) {
        sort(dist[i] + 1, dist[i] + 1 + k);
        ll ans = 0LL;
        for (int j = 1; j <= s; ++j) {
            ans += dist[i][j];
        }

        printf("%lld ", ans);
    }

    return 0;
}
