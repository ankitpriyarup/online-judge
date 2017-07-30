#include <cstdio>
#include <cstring> #include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;
const int INF = 1e9;
int n, num_ores, num_coals;
int ores[MAXN];
int coals[MAXN];

vector<int> bfs(const vector<vector<int> >& graph, int src, int delta = 0) {
    queue<int> q;
    vector<int> dist(graph.size(), -1);
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto& node : graph[cur]) {
            if (dist[node] == -1) {
                dist[node] = dist[cur] + 1;
                q.push(node);
            }
        }
    }

    for (int i = 0; i < dist.size(); ++i) {
        dist[i] += delta;
    }

    return dist;
}

int main() {
    scanf("%d %d %d", &n, &num_ores, &num_coals);
    // node n + 1 is the ore sink, n + 2 is the coal sink
    int ore_sink = n + 1;
    int coal_sink = n + 2;

    vector<vector<int> > graph(coal_sink + 1, vector<int>());
    vector<vector<int> > rev_graph(coal_sink + 1, vector<int>());

    for (int i = 0; i < num_ores; ++i) {
        scanf("%d", ores + i);
        rev_graph[ore_sink].push_back(ores[i]);
    }
    for (int i = 0; i < num_coals; ++i) {
        scanf("%d", coals + i);
        rev_graph[coal_sink].push_back(coals[i]);
    }

    int degree, u, v;
    for (u = 1; u <= n; ++u) {
        scanf("%d", &degree); while (degree-- > 0) {
            scanf("%d", &v);
            graph[u].push_back(v);
            rev_graph[v].push_back(u);
        }
    }

    vector<int> src_dist = bfs(graph, 1);
    vector<int> ore_dist = bfs(rev_graph, ore_sink, -1);
    vector<int> coal_dist = bfs(rev_graph, coal_sink, -1);

    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        if (src_dist[i] < 0 or ore_dist[i] < 0 or coal_dist[i] < 0) {
            continue;
        }

        ans = min(ans, src_dist[i] + ore_dist[i] + coal_dist[i]);
    }

    if (ans == INF) {
        printf("impossible\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
