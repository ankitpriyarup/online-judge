#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

constexpr int MAXN = 200005;
int n, m;
vector<int> graph[MAXN];
bool vis[MAXN];

set<int> unseen;

int bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    set<int> further;

    auto it = unseen.find(src);
    if (it != unseen.end())
        unseen.erase(it);

    int res = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ++res;

        for (int v : graph[u]) {
            if (vis[v]) continue;

            auto it = unseen.find(v);
            if (it != unseen.end()) {
                further.insert(v);
                unseen.erase(it);
            }
        }

        for (int v : unseen) {
            vis[v] = true;
            q.push(v);
        }

        unseen.clear();
        swap(further, unseen);
    }

    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        unseen.insert(i);
    }

    vector<int> comps;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            int res = bfs(i);
            comps.push_back(res);
        }
    }

    sort(begin(comps), end(comps));
    printf("%lu\n", comps.size());
    for (int x : comps)
        printf("%d ", x);
    printf("\n");

    return 0;
}
