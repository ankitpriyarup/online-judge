#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 300005;
int n, m;

vector<int> colors[MAXN];
vector<int> tree[MAXN];

int ans[MAXN];

void dfs(int node, int par) {
    set<int> bad;
    for (int color : colors[node]) {
        if (ans[color] != -1) {
            bad.insert(ans[color]);
        }
    }

    int next_ans = 1;
    while (bad.find(next_ans) != bad.end())
        ++next_ans;

    for (int color : colors[node]) {
        if (ans[color] == -1) {
            ans[color] = next_ans++;
            while (bad.find(next_ans) != bad.end())
                ++next_ans;
        }
    }

    for (int child : tree[node]) {
        if (child == par) continue;

        dfs(child, node);
    }
}

inline int myabs(const int& x) {
    return x < 0 ? -x : x;
}

int main() {
    scanf("%d %d", &n, &m);

    int s, x;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s);
        for (int j = 0; j < s; ++j) {
            scanf("%d", &x);
            colors[i].push_back(x);
        }
    }

    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(ans, -1, sizeof(ans));

    dfs(1, -1);

    int ct = 1;
    for (int i = 1; i <= m; ++i) 
        ct = max(ans[i], ct);

    printf("%d\n", ct);
    for (int i = 1; i <= m; ++i) {
        printf("%d%c", myabs(ans[i]), i == m ? '\n' : ' ');
    }

    return 0;
}
