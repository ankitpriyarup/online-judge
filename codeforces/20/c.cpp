#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<long long, int> pli;

int N, M;

// Adjacency list representation of a graph
vector<pair<int, long long> > graph[100005];
int previous[100005];
long long total_dist[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    int a, b, w;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }

    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.push(make_pair(0LL, 0));

    memset(previous, -1, sizeof(previous));
    memset(total_dist, -1, sizeof(total_dist));
    total_dist[0] = 0;

    while (!pq.empty()) {
        pli cur = pq.top();
        pq.pop();
        long long dist = cur.first;
        int node = cur.second;

        if (node == N - 1)
            break;

        if (total_dist[node] != -1 && dist > total_dist[node])
            continue;

        for (auto it = graph[node].begin(); it != graph[node].end(); ++it) {
            int next = it->first;
            int weight = it->second;
            long long new_dist = dist + weight;

            if (total_dist[next] == -1 || new_dist < total_dist[next]) {
                total_dist[next] = new_dist;
                previous[next] = node;
                pq.push(make_pair(new_dist, next));
            }
        }
    }

    if (previous[N - 1] == -1) {
        cout << "-1\n";
    } else {
        vector<int> path;
        int node = N - 1;

        while (node > 0) {
            path.push_back(node + 1);
            node = previous[node];
        }

        cout << "1";
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << " " << path[i];
        }
        cout << '\n';
    }

    return 0;
}
