#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#define MAXN 10005

using namespace std;

int N, M, X;

vector<pair<int, int> > graph[MAXN];
long long dist[MAXN];

// find the shortest path from 0 to n - 1 with edge cap
long long shortest_path(int edge_cap) {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    pq.push(make_pair(0, 0));
    dist[0] = 0LL;

    memset(dist, -1, sizeof(dist));
    while (!pq.empty()) {
        pair<long long, int> state = pq.top();
        pq.pop();
        long long dist_so_far = state.first;
        int location = state.second;
        if (dist[location] != -1) {
            continue;
        }

        dist[location] = dist_so_far;

        for (pair<int, int> next_state : graph[location]) {
            int next_loc = next_state.first;
            int edge_weight = next_state.second;
            if (edge_weight > edge_cap) {
                continue;
            }

            long long next_dist = dist_so_far + edge_weight;

            if (dist[next_loc] == -1) {
                pq.push(make_pair(next_dist, next_loc));
            }
        }
    }

    return dist[N - 1] == -1 ? 1e18 : dist[N - 1];
}

int main() {
    cin >> N >> M >> X;

    int x, y, w;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> w;
        --x;
        --y;
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }

    long long base = shortest_path(1e9 + 7);
    //cout << base << '\n';

    int lo = 0;
    int hi = 1e9 + 7;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        long long cost = shortest_path(mid);
        /*
        cout << mid << ' ' << cost << '\n';
        cout << (base * (1.0 + X / 100.0)) << '\n';
        */
        if (100LL * cost < 100LL * base + base * X) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << '\n';

    return 0;
}
