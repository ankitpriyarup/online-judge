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

constexpr int LOGN = 18;

template <typename T>
void dfs(const T& tree, vector<int>& depths, int u, int p = -1) {
    for (int v : tree[u]) {
        if (v == p) continue;
        depths[v] = depths[u] + 1;
        dfs(tree, depths, v, u);
    }
}

int lca(const vector<vector<int>>& st, const vector<int>& depths, int u, int v) {
    if (depths[u] > depths[v]) {
        swap(u, v);
    }

    int delta = depths[v] - depths[u];
    for (int j = LOGN - 1; j >= 0; --j) {
        if (delta & (1 << j))
            v = st[j][v];
    }

    if (u == v)
        return u;

    for (int j = LOGN - 1; j >= 0; --j) {
        if (st[j][u] != st[j][v]) {
            u = st[j][u];
            v = st[j][v];
        }
    }

    return st[0][u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    scanf(" %d %d", &n, &q);
    vector<vector<int>> st(LOGN, vector<int>(n, -1));
    vector<vector<int>> tree(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &st[0][i]);
        if (st[0][i] != -1)
            tree[st[0][i]].push_back(i);
    }

    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int i = 0; i < n; ++i) {
            if (st[j][i] != -1) {
                st[j + 1][i] = st[j][st[j][i]];
            }
        }
    }

    vector<int> depths(n, 0);
    for (int i = 0; i < n; ++i) {
        if (st[0][i] == -1) {
            dfs(tree, depths, i);
        }
    }

    int u, v;
    while (q-- > 0) {
        scanf(" %d %d", &u, &v);
        if (lca(st, depths, u, v) == v) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
