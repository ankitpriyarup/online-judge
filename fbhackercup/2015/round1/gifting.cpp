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

constexpr int MAXN = 200005;
constexpr int MAXA = 25;
constexpr ll INF = 1e18;
int n;
vector<int> tree[MAXN];
bool done[MAXN][MAXA];
ll dp[MAXN][MAXA];

ll dfs(int u, int p) {
    if (done[u][p])
        return dp[u][p];

    ll res = p;
    for (int v : tree[u]) {
        ll cur = 1e18;
        for (int p2 = 1; p2 < MAXA; ++p2) {
            if (p2 == p) continue;

            cur = min(cur, dfs(v, p2));
        }

        if (cur == INF) {
            done[u][p] = true;
            return dp[u][p] = INF;
        }

        res += cur;
    }

    done[u][p] = true;
    return dp[u][p] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int tc = 1;
    while (T-- > 0) {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
            tree[i].clear();

        memset(done, false, sizeof(done));
        memset(dp, 0, sizeof(dp));

        int par;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &par);
            if (par)
                tree[par].push_back(i);
        }

        ll ans = 1e18;
        for (int val = 1; val < MAXA; ++val) {
            ans = min(ans, dfs(1, val));
        }

        printf("Case #%d: %lld\n", tc++, ans);
    }
    
    return 0;
}
