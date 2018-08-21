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
void dfs(const T& tree, vector<int>& depths, int u, int p = -1) {
    for (int v : tree[u]) {
        if (v == p) continue;
        depths[v] = depths[u] + 1;
        dfs(tree, depths, v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, src;
    scanf(" %d %d", &n, &src);
    vector<vector<int>> tree(n + 1);

    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf(" %d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> depths(n + 1, 0);
    dfs(tree, depths, src);

    printf("%d\n", 1 + *max_element(begin(depths), end(depths)));
    
    return 0;
}
