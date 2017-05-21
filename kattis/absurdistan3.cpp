#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

int n;
vector<int> graph[MAXN];
int degree[MAXN];

void dfs(int node, int parent) {
    if (degree[node] == 0) return;

    printf("%d %d\n", parent, node);
    degree[node] = 0;
    for (int child : graph[node])
        if (child != parent)
            dfs(child, node);
}

int main() {
    memset(degree, 0, sizeof(degree));
    scanf("%d", &n);

    int u, v;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &u, &v);
        ++degree[u];
        ++degree[v];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int v = graph[u].front();

        --degree[u];
        --degree[v];

        graph[u].pop_back();
        graph[v].erase(find(graph[v].begin(), graph[v].end(), u));

        if (degree[v] == 1) {
            q.push(v);
        }

        printf("%d %d\n", u, v);
    }

    // you're now left with a series of cycles. for each cycle just pick an
    // orientation and print all the edges.
    
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 2) {
            dfs(i, graph[i].back());
        }
    }

    return 0;
}
