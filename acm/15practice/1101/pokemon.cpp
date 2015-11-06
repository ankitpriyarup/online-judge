#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int V, E;
vector<vector<pair<int, double> > > graph;

double dijkstra() {
    bool visited[V];
    priority_queue<pair<double, int> > pq;

    memset(visited, 0, sizeof(visited));
    pq.push(make_pair(1, 0));

    while (!pq.empty()) {
        pair<double, int> cur = pq.top();
        pq.pop();

        double dist = cur.first;
        int node = cur.second;

        if (node == 1) {
            return dist;
        }

        if (visited[node]) {
            continue;
        }

        //cout << "Distance to " << node << " is " << dist << '\n';
        visited[node] = true;

        for (auto it = graph[node].begin(); it != graph[node].end(); ++it) {
            int next_node = it->first;
            double weight = it->second;
            pq.push(make_pair(weight * dist, next_node));
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        graph.clear();
        cin >> V >> E;

        for (int i = 0; i < V; ++i)
            graph.push_back(vector<pair<int, double> >());

        int x, y;
        double w;
        for (int i = 0; i < E; ++i) {
            cin >> x >> y >> w;
            graph[x].push_back(make_pair(y, w));
            graph[y].push_back(make_pair(x, w));
        }

        printf("Case %d: %.2f\n", case_num, dijkstra());
    }
    return 0;
}
