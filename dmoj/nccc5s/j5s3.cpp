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

constexpr int MAXN = 55;
constexpr int MAXM = MAXN * MAXN;
int n, m;
pii edges[MAXM];
vector<int> graph[MAXM];
bool vis[MAXN];

bool dfs(int u, int banned) {
    vis[u] = true;
    if (u == n)
        return true;

    bool res = false;
    for (int e : graph[u]) {
        int v = edges[e].second;
        if (e == banned or vis[v])
            continue;

        res |= dfs(v, banned);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        edges[i] = make_pair(u, v);
        graph[u].push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        memset(vis, 0, sizeof(vis));
        printf("%s\n", dfs(1, i) ? "YES" : "NO");
    }

    return 0;
}
