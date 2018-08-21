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
int n;
ll cost[MAXN];
int a[MAXN];
int in_deg[MAXN];
bool vis[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf(" %lld", &cost[i]);
    }

    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &a[i]);
        if (i == a[i]) {
            ans += cost[i];
            vis[i] = true;
        } else {
            ++in_deg[a[i]];
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;

        vis[u] = true;
        if (--in_deg[a[u]] == 0) {
            q.push(a[u]);
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (vis[u]) continue;

        ll min_cost = cost[u];
        for (int v = a[u]; v != u; v = a[v]) {
            min_cost = min(min_cost, cost[v]);
            vis[v] = true;
        }

        vis[u] = true;
        ans += min_cost;
    }

    printf("%lld\n", ans);

    return 0;
}
