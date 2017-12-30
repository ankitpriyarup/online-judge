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
constexpr int INF = 1e9;
int n, k;
vector<int> tree[MAXN];
int dist[2][MAXN];
bool flagged[MAXN];
int diam[2];

bool dfs1(int k, int u, bool mark = false, int par = -1) {
    if (mark and u == diam[0])
        flagged[u] = true;

    for (int v : tree[u]) {
        if (v == par) continue;

        dist[k][v] = 1 + dist[k][u];

        if (dfs1(k, v, mark, u) and mark)
            flagged[u] = true;
    }

    return flagged[u];
}

ll ans = 0LL;
vector<tuple<int, int, int> > res;

void dfs2(int u, int par = -1) {
    for (int v : tree[u]) {
        if (v == par) continue;
        dfs2(v, u);
    }

    if (!flagged[u]) {
        int i = dist[0][u] > dist[1][u];
        res.push_back(make_tuple(u, diam[i], u));
        ans += dist[1 - i][u];
    }
}

void dfs3(int u, int par = -1) {
    if (u == diam[1]) return;

    ans += dist[0][u];
    res.push_back(make_tuple(u, diam[1], u));

    for (int v : tree[u]) {
        if (v != par and flagged[v])
            dfs3(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dist[0][1] = 0;
    dfs1(0, 1);
    diam[0] = 1;
    for (int u = 1; u <= n; ++u) {
        if (dist[0][u] >= dist[0][diam[0]]) {
            diam[0] = u;
        }
    }

    dist[1][diam[0]] = 0;
    dfs1(1, diam[0]);
    diam[1] = 1;

    for (int u = 1; u <= n; ++u) {
        if (dist[1][u] >= dist[1][diam[1]]) {
            diam[1] = u;
        }
    }

    dist[0][diam[1]] = 0;
    dfs1(0, diam[1], true, -1);

    for (int u = 1; u <= n; ++u) {
        if (!flagged[u]) {
        }
    }

    dfs2(diam[0]);
    dfs3(diam[0]);

    /*
    printf("Dist from %d\n", diam[0]);
    for (int u = 1; u <= n; ++u)
        printf("%d%c", dist[1][u], u == n ? '\n' : ' ');

    printf("Dist from %d\n", diam[1]);
    for (int u = 1; u <= n; ++u)
        printf("%d%c", dist[0][u], u == n ? '\n' : ' ');
    */

    printf("%lld\n", ans);
    int a, b, c;
    for (tuple<int, int, int> t : res) {
        tie(a, b, c) = t;
        printf("%d %d %d\n", a, b, c);
    }

    return 0;
}
