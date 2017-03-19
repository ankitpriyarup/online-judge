#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>

#define MAXN 200002
#define LOGN 20

using namespace std;

int n;
vector<int> graph[MAXN];
int parent[MAXN][LOGN];
int depth[MAXN];

void dfs(int x, int p, int d) {
    for (int i = 0; i < (int)graph[x].size(); ++i) {
        int child = graph[x][i];
        if (child != p) {
            parent[child][0] = x;
            depth[child] = d + 1;
            dfs(child, x, d + 1);
        }
    }
}

void gen_lca() {
    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i][j - 1] != -1) 
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int walk(int x, int l) {
    int n = x;
    for (int up = 1 << (LOGN - 1), j = LOGN - 1; j >= 0; up >>= 1, --j) {
        if (up <= l) {
            n = parent[n][j];
            l -= up;
        }

        if (n == -1)
            return n;
    }

    return n;
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) {
        return lca(y, x);
    }

    if (depth[y] > depth[x]) {
        y = walk(y, depth[y] - depth[x]);
    }

    if (x == y) {
        return x;
    }

    int lo = 0;
    int hi = 1 << LOGN;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (walk(x, mid) == walk(y, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return walk(x, hi);
}

int dist(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)] + 1;
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(parent, -1, sizeof(parent));
    depth[1] = 0;
    dfs(1, -1, 0);
    gen_lca();

    long long ans = 0LL;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            ans += dist(i, j);
        }
    }

    cout << ans << '\n';

    return 0;
}
