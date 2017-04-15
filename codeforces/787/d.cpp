#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 100005;
int n;

// Adjacency list representation of a graph
// 1..n original nodes in the graph
// n + 1..5n nodes in the out tree
// 5n..9n nodes in the in tree
vector<pair<int, int> > graph[9 * MAXN];
long long dist[9 * MAXN];

void dijkstra(const int& s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    pq.push(make_pair(0LL, s));

    memset(dist, -1, sizeof(dist));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<long long, int> cur = pq.top();
        pq.pop();

        int node = cur.second;

        if (dist[node] != -1 && cur.first > dist[node])
            continue;

        for (auto it = graph[node].begin(); it != graph[node].end(); ++it) {
            int next = it->first;
            int weight = it->second;
            long long new_dist = cur.first + weight;

            if (dist[next] == -1 || new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push(make_pair(new_dist, next));
            }
        }
    }
}

int setup(int node, int l, int r, int delta, bool out) {
    if (l == r) return l;

    int mid = (l + r) >> 1;
    int lchild = setup(2 * node, l, mid, delta, out);
    int rchild = setup(2 * node + 1, mid + 1, r, delta, out);

    if (out) {
        graph[node + delta].push_back({lchild, 0});
        graph[node + delta].push_back({rchild, 0});
    } else {
        graph[lchild].push_back({node + delta, 0});
        graph[rchild].push_back({node + delta, 0});
    }

    return node + delta;
}

void connect_out(int node, int l, int r, int u, int ql, int qr, int w, int delta, bool out) {
    if (qr < l or ql > r) {
        return;
    }

    if (l == r) {
        if (out) {
            graph[u].push_back({l, w});
        } else {
            graph[l].push_back({u, w});
        }
        return;
    }

    if (ql <= l and r <= qr) {
        if (out) {
            graph[u].push_back({node + delta, w});
        } else {
            graph[node + delta].push_back({u, w});
        }

        return;
    }

    int mid = (l + r) >> 1;
    connect_out(2 * node, l, mid, u, ql, qr, w, delta, out);
    connect_out(2 * node + 1, mid + 1, r, u, ql, qr, w, delta, out);
}

int main() {
    ios_base::sync_with_stdio(false);
    int q, s;
    scanf("%d %d %d", &n, &q, &s);

    setup(1, 1, n, n + 1, true);
    setup(1, 1, n, 4 * n + 4, false);

    int t, u, v, l, r, w;
    for (int i = 0; i < q; ++i) {
        scanf("%d", &t);

        if (t == 1) {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(make_pair(v, w));
        } else if (t == 2) {
            scanf("%d %d %d %d\n", &u, &l, &r, &w);
            connect_out(1, 1, n, u, l, r, w, n + 1, true);
        } else if (t == 3) {
            scanf("%d %d %d %d\n", &v, &l, &r, &w);
            connect_out(1, 1, n, v, l, r, w, 4 * n + 4, false);
        }
    }

    dijkstra(s);
    
    for (int i = 1; i <= n; ++i) {
        printf("%lld%c", dist[i], i == n ? '\n' : ' ');
    }

    return 0;
}
