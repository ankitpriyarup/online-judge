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
constexpr int LOGN = 19;
int n;
vector<pii> tree[MAXN];
int depth[MAXN];
int st[LOGN][MAXN];
pii big[LOGN][MAXN];

inline void merge(pii& a, const pii& b) {
    if (a.first >= b.second) {
        return;
    } else if (b.first >= a.second) {
        a.first = b.first;
        a.second = b.second;
    } else {
        int x = a.second;
        int y = b.second;
        if (x <= y) {
            a.first = a.second;
            a.second = b.second;
        } else {
            a.first = b.second;
            a.second = a.second;
        }
    }
}

void read() {
    scanf(" %d", &n);
    int u, v, w;
    for (int i = 1; i < n; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }
}

void dfs(int u, int p = 0) {
    int v, w;
    for (auto& e : tree[u]) {
        tie(v, w) = e;
        if (v == p) continue;

        st[0][v] = u;
        big[0][v] = {-1, w};
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void precomp() {
    dfs(1);
    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int u = 1; u <= n; ++u) {
            big[j + 1][u] = {-1, -1};
            if (st[j][u]) {
                st[j + 1][u] = st[j][st[j][u]];
                merge(big[j + 1][u], big[j][u]);
                merge(big[j + 1][u], big[j][st[j][u]]);
            }
        }
    }
}

int solve(int u, int v) {
    if (depth[v] < depth[u]) {
        swap(u, v);
    }
    pii ans = {-1, -1};
    int delta = depth[v] - depth[u];
    for (int j = LOGN - 1; delta > 0 and j >= 0; --j) {
        if (delta & (1 << j)) {
            merge(ans, big[j][v]);
            v = st[j][v];
            delta -= (1 << j);
        }
    }

    for (int j = LOGN - 1; u != v and j >= 0; --j) {
        if (st[j][u] != st[j][v]) {
            merge(ans, big[j][u]);
            merge(ans, big[j][v]);
            u = st[j][u];
            v = st[j][v];
        }
    }

    if (u != v) {
        merge(ans, big[0][u]);
        merge(ans, big[0][v]);
    }
    
    return ans.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    read();
    precomp();

    int q;
    scanf(" %d", &q);
    int u, v;
    while (q-- > 0) {
        scanf(" %d %d", &u, &v);
        printf("%d\n", solve(u, v));
    }
    
    return 0;
}
