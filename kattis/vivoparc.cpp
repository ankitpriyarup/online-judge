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

constexpr int MAXN = 103;
int n;
int adj[MAXN][MAXN];
int color[MAXN];
bool done;
vector<int> inds;

void dfs(int u) {
    if (!done) return;

    int seen = 0;
    for (int i = 0; i < n; ++i) {
        int v = inds[i];
        if (u == v) continue;
        if (adj[u][v] and color[v] != -1)
            seen |= (1 << color[v]);
    }

    int col = 1;
    while (seen & (1 << col))
        ++col;

    if (col > 4) {
        done = false;
        return;
    }

    color[u] = col;
    for (int i = 0; i < n; ++i) {
        int v = inds[i];
        if (u == v) continue;
        if (adj[u][v] and color[v] == -1)
            dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    memset(adj, 0, sizeof(adj));
    int u, v;
    while (scanf("%d-%d", &u, &v) == 2) {
        adj[u][v] = adj[v][u] = true;
    }

    inds.resize(n);
    iota(begin(inds), end(inds), 1);

    while (!done) {
        done = true;
        random_shuffle(begin(inds), end(inds));
        memset(color, -1, sizeof(color));
        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1)
                dfs(i);
        }
    }

    for (int i = 1; i <= n; ++i) 
        printf("%d %d\n", i, color[i]);

    return 0;
}
