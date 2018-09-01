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

template <typename T>
void dfs(const T& tree, vector<int>& parents, vector<int>& depths, int u, int p = -1) {
    for (int v : tree[u]) {
        if (v == p)
            continue;

        parents[v] = u;
        depths[v] = depths[u] + 1;
        dfs(tree, parents, depths, v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<vector<int>> tree(n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf(" %d %d", &u, &v);
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> parents(n, -1), depths(n, 0);
    dfs(tree, parents, depths, 0);

    set<pii> nodes;
    for (int i = 0; i < n; ++i) {
        nodes.emplace(depths[i], i);
    }

    int ans = 0;
    while (!nodes.empty()) {
        pii far = *prev(end(nodes));
        if (depths[far.second] <= 2) break;

        int u = parents[far.second];
        ++ans;

        for (int v : tree[u]) {
            auto it = nodes.find({depths[v], v});
            if (it != end(nodes)) {
                nodes.erase(it);
            }
        }
        auto it = nodes.find({depths[u], u});
        if (it != end(nodes)) {
            nodes.erase(it);
        }
    }

    printf("%d\n", ans);

    return 0;
}
