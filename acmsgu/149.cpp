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
int n;
vector<pii> graph[MAXN];
int dist[2][MAXN];

void dfs(int k, int u, int p = -1, int d = 0) {
    dist[k][u] = d;
    for (auto&& [v, w] : graph[u]) {
        if (v == p) continue;
        dfs(k, v, u, d + w);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    int p, w;
    for (int u = 2; u <= n; ++u) {
        scanf(" %d %d", &p, &w);
        graph[p].emplace_back(u, w);
        graph[u].emplace_back(p, w);
    }

    dfs(0, 1);
    int cap = 1;
    for (int u = 2; u <= n; ++u) {
        if (dist[0][u] > dist[0][cap])
            cap = u;
    }

    dfs(0, cap);
    int cap2 = 1;
    for (int u = 2; u <= n; ++u) {
        if (dist[0][u] > dist[0][cap2])
            cap2 = u;
    }

    dfs(1, cap2);

    for (int u = 1; u <= n; ++u) {
        printf("%d\n", max(dist[0][u], dist[1][u]));
    }

    return 0;
}
