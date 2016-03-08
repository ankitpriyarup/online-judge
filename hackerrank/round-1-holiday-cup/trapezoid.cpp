#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

long long graph[1001][1001];
long long dist[1001];

long long dijkstra(int start, int end) {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    pq.push(make_pair(0, start));
    memset(dist, -1, sizeof(dist));

    while (!pq.empty()) {
        pair<long long, int> cur = pq.top();
        pq.pop();

        long long c_dist = cur.first;
        int loc = cur.second;

        if (loc == end) return c_dist;
        if (dist[loc] > -1 and dist[loc] <= c_dist) continue;

        dist[loc] = c_dist;

        for (int i = 0; i <= 1000; ++i) {
            if (i != loc and graph[loc][i] > -1) {
                long long new_dist = c_dist + graph[loc][i];
                pq.push(make_pair(new_dist, i));
            }
        }

    }

    return -1;
}

int main() {
    int N;
    int A, B, H;
    while (cin >> N) {
        if (N == 0) break;
        memset(graph, -1, sizeof(graph));

        for (int i = 0; i < N; ++i) {
            cin >> A >> B >> H;
            long long area = (B + A) * H;

            if (graph[A][B] < 0) {
                graph[A][B] = graph[B][A] = area;
            } else {
                graph[A][B] = min(area, graph[A][B]);
                graph[B][A] = graph[A][B];
            }
        }

        cin >> A >> B;
        printf("%.02f\n", dijkstra(A, B) * 0.01);
    }

    return 0;
}
