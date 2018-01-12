#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int n;
vector<int> adj[105];
int par[105];
int val[105];
int sz[105];
int sum[105];

double dfs(int u) {
    sz[u] = 1;
    sum[u] = val[u];
    double ans = -1e9;
    for (int v : adj[u]) {
        ans = max(ans, dfs(v));
        sz[u] += sz[v];
        sum[u] += sum[v];
    }
    
    return max(ans, 1.0 * sum[u] / sz[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d %d", &par[i], &val[i]);
        adj[par[i]].push_back(i);
    }

    printf("%0.3f\n", dfs(1));

    return 0;
}
