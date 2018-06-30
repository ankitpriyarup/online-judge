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

constexpr int MAXN = 10004;
int n;
int marbles[MAXN];
vector<int> tree[MAXN];
int in_deg[MAXN], sz[MAXN];
int moves;

void dfs(int u) {
    sz[u] = 1;
    for (int v : tree[u]) {
        dfs(v);
        moves += abs(sz[v] - marbles[v]);
        sz[u] += sz[v];
        marbles[u] += marbles[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int u, v, deg, id;
    while (scanf(" %d", &n) == 1) {
        if (!n) break;

        memset(in_deg, 0, sizeof(in_deg));
        for (int u = 1; u <= n; ++u) {
            tree[u].clear();
            scanf(" %d", &id);
            assert(u == id);
            scanf(" %d", &marbles[u]);
            scanf(" %d", &deg);
            for (int i = 0; i < deg; ++i) {
                scanf(" %d", &v);
                tree[u].push_back(v);
                ++in_deg[v];
            }
        }

        moves = 0;
        int root = 1;
        for (int u = 1; u <= n; ++u)
            if (in_deg[u] == 0)
                root = u;

        dfs(root);
        printf("%d\n", moves);
    }

    return 0;
}
