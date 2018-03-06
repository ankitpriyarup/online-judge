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
vector<int> tree[MAXN];
int depth[MAXN];
int by_depth[MAXN];

void dfs(int u, int par) {
    for (int v : tree[u]) {
        if (v == par) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int v;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &v);
        tree[v].push_back(i);
    }

    depth[1] = 0;
    dfs(1, -1);

    for (int i = 1; i <= n; ++i) {
        ++by_depth[depth[i]];
    }

    int ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        ans += (by_depth[i] & 1);
    }

    printf("%d\n", ans);

    return 0;
}
