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

constexpr int MAXN = 50004;
constexpr int INF = (1LL << 31LL) - 1LL;
int n, m;
vector<int> tree[MAXN];
multiset<int> raw[MAXN];
multiset<int> *vals[MAXN];
int ans[MAXN];
int sz[MAXN];

void dfs(int u) {
    if (tree[u].empty())
        return;

    int big = tree[u][0];
    for (int v : tree[u]) {
        dfs(v);
        sz[u] += sz[v];
        if (sz[v] > sz[big])
            big = v;
    }

    vals[u] = vals[big];

    ans[u] = ans[big];
    for (int v : tree[u]) {
        if (v == big) continue;
        for (int x : *vals[v]) {
            auto it = vals[u]->lower_bound(x);
            if (it != end(*vals[u])) {
                ans[u] = min(ans[u], *it - x);
            }
            if (it != begin(*vals[u])) {
                auto pit = prev(it);
                ans[u] = min(ans[u], x - *pit);
            }
            vals[u]->insert(x);
        }

        ans[u] = min(ans[u], ans[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);

    int p;
    for (int u = 2; u <= n; ++u) {
        scanf(" %d", &p);
        tree[p].push_back(u);
    }

    int x;
    for (int i = n - m + 1; i <= n; ++i) {
        scanf("%d", &x);
        raw[i].insert(x);
        vals[i] = &raw[i];
        sz[i] = 1;
        ans[i] = INF;
    }

    dfs(1);
    for (int u = 1; u <= n - m; ++u)
        printf("%d ", ans[u]);
    return 0;
}
