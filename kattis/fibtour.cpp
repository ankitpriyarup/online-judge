#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 100005;
int n, m;
vector<int> graph[MAXN];

vector<ll> fibs;
map<ll, int> inv_fib;

ll heights[MAXN];
int dp[MAXN];
int has_two[MAXN];

int dfs(int node, int fib_ind) {
    if (dp[node] != -1) {
        return dp[node];
    }

    dp[node] = 1;
    if (fib_ind == fibs.size() - 1) {
        return dp[node];
    }

    for (int child : graph[node]) {
        if (heights[child] == fibs[fib_ind + 1]) {
            dp[node] = max(dp[node], 1 + dfs(child, fib_ind + 1));
        }
    }

    return dp[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll a = 1;
    ll b = 1;
    while (b < 1e18) {
        inv_fib[b] = fibs.size();
        fibs.push_back(b);

        ll c = a + b;
        a = b;
        b = c;
    }

    for (int i = 0; i < fibs.size(); ++i) {
        assert(i == inv_fib[fibs[i]]);
    }

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", heights + i);
    }

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (inv_fib.find(heights[i]) != inv_fib.end()) {
            dfs(i, inv_fib.at(heights[i]));
        }

        ans = max(ans, dp[i]);
    }

    for (int i = 1; i <= n; ++i) {
        if (heights[i] == 1) {
            for (int child : graph[i]) {
                if (heights[child] == 1) {
                    ans = max(ans, 1 + dp[child]);
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
