#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int INF = 1e9;

namespace maxflow {
    const int MAXN = 60;
    const int MAXM = 2 * 60 * 60;

    // n is number of nodes
    // m is number of edges
    int n, m;

    // All of these arrays are indexed by edge
    // start[i] = start of edge i
    // dest[i]  = destination of edge i
    // cap[i]   = capacity of edge i
    int start[MAXM], dest[MAXM], cap[MAXM];

    // Linked list of edges by node
    // Head picks an edge, next gives the next edge
    int next[MAXM], head[MAXN];

    void init(int num_nodes) {
        n = num_nodes;
        m = 0;

        memset(head, -1, sizeof(head));
        memset(next, -1, sizeof(next));
    }

    // Add edges x -> y  and y -> x with capacities c1 and c2
    void edge(int x, int y, int c1, int c2) {
        start[m] = x;
        dest[m] = y;
        cap[m] = c1;
        next[m] = head[x];
        head[x] = m;
        ++m;

        start[m] = y;
        dest[m] = x;
        cap[m] = c2;
        next[m] = head[y];
        head[y] = m;
        ++m;
    }

    // Structures used for the BFS
    bool visit[MAXN];
    int prev[MAXM], aug[MAXN];

    bool bfs(int src, int sink) {
        memset(visit, 0, sizeof(visit));
        memset(prev, -1, sizeof(prev));
        memset(aug, 0, sizeof(aug));

        queue<int> q;

        q.push(src);
        visit[src] = true;
        aug[src] = INF;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == sink)
                return true;

            for (int edge = head[node]; edge != -1; edge = next[edge]) {
                int next_node = dest[edge];
                if (cap[edge] > 0 and !visit[next_node]) {
                    visit[next_node] = true;
                    prev[next_node] = edge;
                    aug[next_node] = min(aug[node], cap[edge]);
                    q.push(next_node);
                }
            }
        }

        return false;
    }

    int augment(int src, int sink) {
        int node = sink;
        int flow = aug[sink];
        int edge = prev[sink];

        for (int edge = prev[sink]; edge != -1; edge = prev[start[edge]]) {
            cap[edge] -= flow;
            cap[edge ^ 1] += flow;
        }

        return flow;
    }

    int run(int src, int sink) {
        int flow = 0;
        while (bfs(src, sink)) {
            flow += augment(src, sink);
        }

        return flow;
    }
};

using namespace std;

int adjmat[52][52];

int get_label(char c) {
    assert(('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z'));

    if (c <= 'Z')
        return c - 'A';
    else
        return c - 'a' + 26;
}

int main() {
    int n;
    scanf("%d", &n);

    char u[3], v[3];
    int w;
    maxflow::init(52);

    memset(adjmat, 0, sizeof(adjmat));
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %d", u, v, &w);
        int x = get_label(u[0]);
        int y = get_label(v[0]);
        adjmat[x][y] += w;
    }

    for (int i = 0; i < 52; ++i) {
        for (int j = i + 1; j < 52; ++j) {
            if (adjmat[i][j] or adjmat[j][i])
                maxflow::edge(i, j, adjmat[i][j], adjmat[j][i]);
        }
    }

    printf("%d\n", maxflow::run(get_label('A'), get_label('Z')));

    return 0;
}
