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
int n, m, l;
vector<int> graph[MAXN];
bool vis[MAXN];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : graph[u])
        dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d %d %d", &n, &m, &l);
        for (int i = 1; i <= n; ++i)
            graph[i].clear();

        memset(vis, 0, sizeof(vis));
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf(" %d %d", &u, &v);
            graph[u].push_back(v);
        }

        while (l-- > 0) {
            scanf(" %d", &u);
            dfs(u);
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += vis[i];
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
