#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 200005;
const int MAXM = 22;
const int LOGN = 19;

int n;
int parent[MAXN][LOGN];
int sizes[MAXN];
int depth[MAXN];

vector<int> tree[MAXN];

void dfs(int node, int par, int dep) {
    parent[node][0] = par;
    sizes[node] = 1;
    depth[node] = dep;

    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node, dep + 1);
            sizes[node] += sizes[child];
        }
    }
}

void gen_parents() {
    for (int j = 1; j < LOGN; ++j) {
        for (int i = 0; i <= n; ++i) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < LOGN; ++j) {
            cout << parent[i][j] << ' ';
        }
        cout << '\n';
    }
    */
}

int walk_up(int x, int steps) {
    int node = x;
    for (int p = 1, i = 0; p <= steps; p <<= 1, ++i) {
        if (steps & p) {
            node = parent[node][i];
            if (node == -1) {
                return node;
            }
        }
    }

    return node;
}

int lca(int a, int b) {
    if (a == 0 or b == 0) {
        return 0;
    }

    if (depth[b] < depth[a]) {
        swap(a, b);
    }

    if (depth[b] > depth[a]) {
        b = walk_up(b, depth[b] - depth[a]);
    }
    if (a == b) {
        return a;
    }

    int lo = 0;
    int hi = n + 2;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (walk_up(a, mid) == walk_up(b, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return walk_up(a, hi);
}

bool cmp(const int& a, const int& b) {
    return depth[a] < depth[b];
}

int query[MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);

    int par;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &par);
        tree[i].push_back(par);
        tree[par].push_back(i);
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    dfs(0, -1, 0);
    gen_parents();

    int q, m;
    scanf("%d", &q);

    while (q-- > 0) {
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &query[i]);
        }

        sort(query, query + m, cmp);

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            bool use = true;
            for (int j = i - 1; j >= 0; --j) {
                int l = lca(query[i], query[j]);
                if (l == query[j]) {
                    use = false;
                    break;
                }
            }

            if (use) {
                ans += sizes[query[i]];
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
