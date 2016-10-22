#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int n, k;
vector<int> graph[50004];
int parent[50004][20];
int depth[50004];
int value[50004];

void dfs1(int n, int p, int d) {
    parent[n][0] = p;
    depth[n] = d;

    for (int child : graph[n]) {
        if (child != p) {
            dfs1(child, n, d + 1);
        }
    }
}

void gen_lca() {
    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i < n; ++i) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int walk_up(int n, int d) {
    int x = n;
    for (int i = 19, p = 1 << 19; i >= 0; --i, p >>= 1) {
        if (p <= d) {
            x = parent[x][i];
            d -= p;
        }

        if (x == -1) {
            return -1;
        }
    }

    return x;
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) {
        return lca(y, x);
    }

    if (depth[y] > depth[x]) {
        y = walk_up(y, depth[y] - depth[x]);
    }

    if (x == y) {
        return x;
    }
    
    int lo = 0;
    int hi = n + 1;
    while (lo + 1 < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (walk_up(x, mid) == walk_up(y, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return walk_up(x, hi);
}

void dfs2(int n) {
    for (int child : graph[n]) { 
        if (child != parent[n][0]) {
            dfs2(child);
            value[n] += value[child];
        }
    }
}

int main() {
    ifstream fin("maxflow.in");
    ofstream fout("maxflow.out");

    fin >> n >> k;
    int x, y;

    for (int i = 0; i < n - 1; ++i) {
        fin >> x >> y;
        --x;
        --y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs1(0, -1, 0);
    gen_lca();

    /*
    for (int i = 0; i < n; ++i) {
        cout << parent[i][0] << ' ';
    }
    cout << '\n';

    for (int i = 0; i < n; ++i) {
        cout << depth[i] << ' ';
    }
    cout << '\n';
    */

    for (int i = 0; i < k; ++i) {
        fin >> x >> y;
        --x;
        --y;

        int l = lca(x, y);
        //cout << "LCA(" << x << ", " << y << ") = " << l << '\n';
        if (depth[y] > depth[x]) {
            swap(x, y);
        }

        value[x] += 1;
        value[y] += 1;
        value[l] -= 1;
        if (parent[l][0] != -1) {
            value[parent[l][0]] -= 1;
        }

    }

    /*
    for (int i = 0; i < n; ++i) {
        cout << value[i] << ' ';
    }
    cout << '\n';
    */

    dfs2(0);

    /*
    for (int i = 0; i < n; ++i) {
        cout << value[i] << ' ';
    }
    cout << '\n';
    */

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, value[i]);
    }

    fout << ans << '\n';

    return 0;
}
