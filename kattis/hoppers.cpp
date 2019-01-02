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

constexpr int MAXN = 500005;
int n, m;
vector<int> graph[MAXN];
int vis[MAXN];

void dfs(int u, int c = 1) {
    if ((vis[u] & c) == c) {
        return;
    }

    vis[u] |= c;
    for (int v : graph[u])
        dfs(v, 3 ^ c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf(" %d %d", &u, &v);
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // answer is cc - 1 to connect all components
    // +1 if result is not bipartite
    vector<int> starts;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
            starts.push_back(i);
        }
    }

    int ans = starts.size();
    --ans;

    for (int i = 1; i < starts.size(); ++i) {
        int u = starts[i - 1];
        int v = starts[i];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(vis, 0, sizeof(vis));
    dfs(0);
    if (vis[0] != 3) {
        ++ans;
    }

    printf("%d\n", ans);

    return 0;
}
