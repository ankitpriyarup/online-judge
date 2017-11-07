#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

constexpr int MAXN = 100005;
int n, m;
vector<int> graph[MAXN];
bool visit[MAXN];

// diameter, height
pii dfs(int node, int par = -1) {
    visit[node] = true;
    pii res = {0, 0};
    vector<int> heights;

    for (int child : graph[node]) {
        if (child == par) continue;

        pii vals = dfs(child, node);
        res.first = max(res.first, vals.first);
        res.second = max(res.second, vals.second + 1);
        heights.push_back(vals.second + 1);
    }

    sort(begin(heights), end(heights));
    reverse(begin(heights), end(heights));

    if (heights.size() >= 2) {
        res.first = max(res.first, heights[0] + heights[1]);
    } else {
        res.first = max(res.first, res.second);
    }

    // printf("node %d, diam %d, height %d\n", node, res.first, res.second);
    return res;
}

int main() {
    scanf("%d %d", &n, &m);

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(visit, 0, sizeof(visit));
    vector<int> diameters;
    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            pii res = dfs(i);
            // printf("Node %d has diam %d\n", i, res.first);
            diameters.push_back(res.first);
        }
    }

    sort(begin(diameters), end(diameters));

    int ans = diameters.back();
    while (diameters.size() >= 2) {
        int d1 = diameters.back();
        int r1 = (d1 + 1) / 2;
        diameters.pop_back();

        int d2 = diameters.back();
        int r2 = (d2 + 1) / 2;
        diameters.pop_back();

        diameters.push_back(max(max(d1, d2), 1 + r1 + r2));
        ans = max(ans, diameters.back());
    }

    printf("%d\n", ans);

    return 0;
}
