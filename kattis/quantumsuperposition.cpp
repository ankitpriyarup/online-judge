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

constexpr int MAXN = 2003;
int n[2], m[2];
vector<int> graph[2][MAXN];
bitset<MAXN> dists[2][MAXN];
bool vis[2][MAXN];

void dfs(int k, int u) {
    if (u == n[k]) {
        dists[k][u].set(0, true);
        return;
    }

    if (vis[k][u]) return;

    vis[k][u] = true;
    for (int v : graph[k][u]) {
        dfs(k, v);
        for (int d = 0; d < MAXN - 1; ++d) {
            if (dists[k][v][d]) {
                dists[k][u].set(d + 1, true);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d %d", &n[0], &n[1], &m[0], &m[1]);
    int u, v;
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < m[k]; ++i) {
            scanf("%d %d", &u, &v);
            graph[k][u].push_back(v);
        }

        dfs(k, 1);
    }

    int q;
    scanf("%d", &q);
    int x;
    while (q-- > 0) {
        scanf("%d", &x);
        bool works = false;
        for (int i = 0; !works and i <= x; ++i) {
            if (dists[0][1][i] and dists[1][1][x - i]) {
                works = true;
            }
        }

        printf("%s\n", works ? "Yes" : "No");
    }

    return 0;
}
