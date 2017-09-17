#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using ll = long long;

constexpr int MAXN = 100005;
constexpr ll INF = 1e18;
int n;
int c[MAXN];
vector<int> tree[MAXN];

bool is_child[MAXN];

ll dp[2][MAXN];

ll solve(int node, bool required) {
    ll& ret = dp[required][node];
    if (ret != -1) {
        return ret;
    }

    if (!required) {
        ll opt1 = solve(node, true);

        ll opt2 = INF;
        ll none_req = 0LL;
        for (int child : tree[node]) {
            none_req += solve(child, false);
        }

        for (int child : tree[node]) {
            opt2 = min(opt2, none_req - solve(child, false) + solve(child, true));
        }

        return dp[0][node] = min(opt1, opt2);
    } else {
        ll cost = c[node];
        for (int child : tree[node]) {
            for (int grandchild : tree[child]) {
                cost += solve(grandchild, false);
            }
        }

        return dp[1][node] = cost;
    }
}

int main() {
    scanf("%d", &n);

    int children, x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", c + i);
        scanf("%d", &children);

        while (children-- > 0) {
            scanf("%d", &x);
            tree[i].push_back(x);
            is_child[x] = true;
        }
    }

    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (!is_child[i]) {
            root = i;
            break;
        }
    }

    memset(dp, -1, sizeof(dp));
    ll ans = solve(root, 0);

    printf("%lld\n", ans);

    return 0;
}
