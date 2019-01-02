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

constexpr int MAXN = 100005;
int n, m;
vector<int> tree[MAXN];
vector<int> deps[MAXN];

int tin[MAXN], tout[MAXN], rtin[MAXN];

bool active[MAXN];
bool ans[MAXN];

int g_timer = 0;

void dfs1(int u, int p = -1) {
    tin[u] = g_timer++;
    rtin[tin[u]] = u;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs1(v, u);
    }

    tout[u] = g_timer;
}

void dfs2(int u, int p, int cur) {
    if (!cur)
        ans[u] = 1;

    for (int v : tree[u]) {
        if (v == p) continue;
        int new_cur = cur;
        // deactivate things that went from u to the subtree of v
        for (int w : deps[u]) {
            if (tin[v] <= tin[w] and tin[w] < tout[v]) {
                --new_cur;
            }
        }

        // activate things that start in v and go into some other subtree of u
        for (int w : deps[v]) {
            if (!(tin[v] <= tin[w] and tin[w] < tout[v])) {
                ++new_cur;
            }
        }

        dfs2(v, u, new_cur);
    }
}

bool has_cycle() {
    vector<int> in_deg(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : deps[u]) {
            in_deg[v] += 1;
        }
    }

    queue<int> q;
    for (int u = 0; u < n; ++u) {
        if (!in_deg[u])
            q.push(u);
    }

    int seen = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++seen;
        for (int v : deps[u]) {
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    return seen != n;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("gathering.in", "r", stdin);
    freopen("gathering.out", "w", stdout);

    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf(" %d %d", &u, &v);
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs1(0);

    int tot_active = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf(" %d %d", &a, &b);
        --a; --b;
        deps[a].push_back(b);
        if (tin[a] <= tin[b] and tin[b] < tout[a]) {
            tot_active += 1;
        }
    }

    if (has_cycle()) {
        for (int i = 0; i < n; ++i) {
            printf("0\n");
        }
        return 0;
    }

    // Orient the tree edges as directions
    // there is only a cycle if some ancestor has to leave before its child
    // dp[u] = how many edges from u go into a subtree of u
    // doable if and only if sum(dp[i]) = 0
    //
    // when you rotate the tree, say u is the cur root and v is the new root
    // subtract out all deps going from u to something in the subtree of v
    // add in all deps going from v to something in the subtree of u (sub subtree of v)
    dfs2(0, -1, tot_active);

    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
