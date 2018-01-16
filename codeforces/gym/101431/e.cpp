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

constexpr int MAXN = 19;
constexpr ll INF = 1e18;
int n;
ll t[MAXN];
vector<int> tree[MAXN];
ll dp[1 << MAXN];

int dfs(int u, int vis) {
    if (vis & (1 << u)) return 0;

    int res = (1 << u);
    for (int v : tree[u]) {
        res |= dfs(v, vis | (1 << u));
    }

    return res;
}

ll solve(int mask) {
    // printf("solve(%x)\n", mask);
    if (dp[mask] != -1)
        return dp[mask];

    ll ans = INF;
    for (int u = 0; u < n; ++u) {
        if ((mask & (1 << u)) == 0)
            continue;

        ll cur = 0;
        for (int v : tree[u]) {
            if ((mask & (1 << v)) == 0)
                continue;
            int submask = dfs(v, ~mask | (1 << u));
            cur = max(cur, t[u] + solve(submask));
        }

        ans = min(ans, cur);
    }

    return dp[mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        dp[1 << i] = 0;
    }
    int par;
    for (int i = 1; i < n; ++i) {
        cin >> par;
        --par;
        tree[par].push_back(i);
        tree[i].push_back(par);
    }

    cout << solve((1 << n) - 1) << '\n';

    return 0;
}
