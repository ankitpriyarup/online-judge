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

constexpr int MAXN = 50003;
int n;
vector<pii> graph[MAXN];
map<int, int> colors[MAXN];
int res[MAXN];

int dfs_down(int u, int par = -1, int col = -1) {
    int res = max(0, colors[u][col] - 1);
    for (pii& edge : graph[u]) {
        if (edge.first == par) {
            continue;
        }

        res += dfs_down(edge.first, u, edge.second);
    }

    return res;
}

void dfs_up(int u, int par, int col, int score) {
    res[u] = score;
    for (pii& edge : graph[u]) {
        if (edge.first == par)
            continue;

        int new_score = score;
        new_score += colors[u][edge.second] - 1;
        new_score -= colors[edge.first][edge.second] - 1;

        dfs_up(edge.first, u, edge.second, new_score);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int u, v, c;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});

        ++colors[u][c];
        ++colors[v][c];
    }

    int p = dfs_down(1);
    dfs_up(1, -1, -1, p);

    int total = 0;
    for (int u = 1; u <= n; ++u) {
        if (res[u] == 0) {
            ++total;
        }
    }

    printf("%d\n", total);
    for (int u = 1; u <= n; ++u) {
        if (res[u] == 0) {
            printf("%d\n", u);
        }
    }

    return 0;
}
