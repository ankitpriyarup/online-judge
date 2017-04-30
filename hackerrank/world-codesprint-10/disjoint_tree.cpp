#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 300005;

typedef long long (*f)(long long, long long);

int n;

pair<int, int> edges[2 * MAXN];
long long w[MAXN];
// u => v, index
vector<pair<int, int> > tree[MAXN];

f funcs[] = { [](long long a, long long b) { return min(a, b); }, 
              [](long long a, long long b) { return max(a, b); } };

// dp[e][j] = max subtree with edge e
// if j == 1, the root is required
// k specifies which function to use
long long dp[MAXN][2][2];

void dfs(int index) {
    if (dp[index][0][1] != -1) return;

    int node = edges[index].first;
    int parent = edges[index].second;

    for (int k = 0; k < 2; ++k) {
        dp[index][0][k] = funcs[k](w[node], 0);
        dp[index][1][k] = w[node];
    }


    for (pair<int, int> edge : tree[node]) {
        if (edge.first == parent) continue;

        int ind = edge.second ^ 1;
        int u = edges[ind].first;
        int v = edges[ind].second;

        // printf("Node %d parent %d u %d v %d\n", node, parent, u, v);

        assert(node == v);
        dfs(ind);

        for (int k = 0; k < 2; ++k) {
            dp[index][1][k] += funcs[k](0, dp[ind][1][k]);
            dp[index][0][k] = funcs[k](dp[index][0][k], dp[ind][0][k]);
        }
    }

    for (int k = 0; k < 2; ++k) {
        dp[index][0][k] = funcs[k](dp[index][0][k], dp[index][1][k]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", w + i);
    }

    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[2 * i] = {u, v};
        edges[2 * i + 1] = {v, u};
        tree[u].push_back({v, 2 * i});
        tree[v].push_back({u, 2 * i + 1});
    }

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < n; ++i) {
        dfs(2 * i);
        dfs(2 * i + 1);
    }

    long long ans = 0LL;
    for (int i = 1; i < n; ++i) {
        for (int k1 = 0; k1 < 2; ++k1) {
            for (int k2 = 0; k2 < 2; ++k2) {
                ans = max(ans, 1LL * dp[2 * i][0][k1] * dp[2 * i + 1][0][k2]);
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
