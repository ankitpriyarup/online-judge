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

constexpr int MAXN = 100005;
int n, m;
int p[MAXN];
vector<int> graph[MAXN];
bool vis[MAXN];

int dfs(int u) {
    vis[u] = true;
    int res = p[u];
    for (int v : graph[u]) {
        if (!vis[v]) {
            res = min(res, dfs(v));
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", p + i);
    }

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ans += dfs(i);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
