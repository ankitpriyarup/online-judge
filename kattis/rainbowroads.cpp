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

constexpr int MAXN = 50004;
int n;
vector<pii> tree[MAXN];
map<int, int> colors[MAXN];
int num_good;
bool good[MAXN];

int dfs_up(int node, int par, int col) {
    int ret = max(0, colors[node][col] - 1);
    for (pii edge : tree[node]) {
        if (edge.first == par) continue;

        ret += dfs_up(edge.first, node, edge.second);
    }

    return ret;
}

void dfs_down(int node, int par, int score) {
    // printf("Score at %d is %d\n", node, score);
    if (score == 0) {
        ++num_good;
        good[node] = true;
    }

    for (pii edge : tree[node]) {
        if (edge.first == par) continue;

        int new_score = score;
        new_score += colors[node][edge.second] - 1;
        new_score -= colors[edge.first][edge.second] - 1;

        dfs_down(edge.first, node, new_score);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int u, v, c;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});

        ++colors[u][c];
        ++colors[v][c];
    }

    int start = dfs_up(1, -1, -1);

    num_good = 0;
    dfs_down(1, -1, start);

    printf("%d\n", num_good);
    for (int i = 1; i <= n; ++i)
        if (good[i])
            printf("%d\n", i);

    return 0;
}
