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

constexpr int MAXN = 12;
constexpr int MAXK = 16;
constexpr int MOD = 9901;

int n, k;
vector<pii> edges;
bool used[MAXN];
bool adj[MAXN][MAXN];
int used_nodes;
int ans;

void dfs(int u) {
    used[u] = true;
    ++used_nodes;

    if (used_nodes == n) {
        if (adj[u][0])
            ++ans;
    } else {
        for (int v = 0; v < n; ++v) {
            if (!used[v] and adj[u][v])
                dfs(v);
        }
    }

    --used_nodes;
    used[u] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int tc = 1;
    while (T-- > 0) {
        scanf("%d %d", &n, &k);
        edges.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] = true;

        memset(used, 0, sizeof(used));
        int u, v;
        for (int i = 0; i < k; ++i) {
            scanf("%d %d", &u, &v);
            --u; --v;
            edges.emplace_back(u, v);
            adj[u][v] = adj[v][u] = false;
        }

        ans = 0;
        dfs(0);

        printf("Case #%d: %lld\n", tc++, (1LL * ans * (MOD + 1) / 2) % MOD);
    }
    
    return 0;
}
