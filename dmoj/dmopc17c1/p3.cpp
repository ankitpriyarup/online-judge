#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 100005;
int n, m;
vector<pair<int, int> > graph[MAXN];

struct state {
    int node;
    int danger;
    int total;
    
    bool operator<(const state& other) const {
        return danger < other.danger or (danger == other.danger and total < other.total);
    }

    bool operator==(const state& other) const {
        return node == other.node and danger == other.danger and total == other.total;
    }

    bool operator>(const state& other) const {
        return !(*this < other) and !(*this == other);
    }
};

state dist[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);

    int u, v, danger;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &danger);
        graph[u].push_back({v, danger});
        graph[v].push_back({u, danger});
    }

    for (int i = 1; i <= n; ++i) {
        dist[i] = {i, -1, -1};
    }

    dist[1] = {1, 0, 0};
    priority_queue<state, vector<state>, greater<state> > pq;
    pq.push({1, 0, 0});
    
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        if (cur.danger != dist[cur.node].danger or cur.total != dist[cur.node].total) {
            continue;
        }

        for (auto edge : graph[cur.node]) {
            int child = edge.first;
            int dangerous = edge.second;

            state new_state = {child, cur.danger + dangerous, cur.total + 1};
            if (dist[child].danger == -1 or (new_state < dist[child])) {
                dist[child] = new_state;
                pq.push(new_state);
            }
        }
    }

    if (dist[n].danger == -1) {
        printf("%d\n", -1);
    } else {
        printf("%d %d\n", dist[n].danger, dist[n].total);
    }

    return 0;
}
