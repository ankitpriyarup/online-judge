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
int n;
vector<int> tree[MAXN];
int deg[MAXN];
int children[MAXN];
int src;
bool valid = true;

void dfs(int u, int p = -1) {
    for (int v : tree[u]) {
        if (v == p) continue;

        ++children[u];
        dfs(v, u);
    }

    if (u != src and children[u] > 1)
        valid = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf(" %d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }

    src = 1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > deg[src])
            src = i;
    }

    dfs(src);
    if (valid) {
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (children[i] == 0) {
                ans.push_back(i);
            }
        }

        printf("Yes\n");
        printf("%lu\n", ans.size());
        for (int x : ans)
            printf("%d %d\n", src, x);
        printf("\n");
    } else {
        printf("No\n");
    }

    return 0;
}
