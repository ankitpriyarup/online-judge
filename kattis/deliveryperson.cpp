#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

// 13 * 13 = 169
// 169 * 4 = 676 nodes
// should be small enough for floyd warshalls

constexpr int MAXN = 30004;
constexpr ll INF = 1e18;
constexpr int NODES = 4 * 13 * 13;
constexpr int COORD = 6;
int b, s, l, r, n;

vector<pii> graph[NODES];
ll dist[NODES][NODES];

pii pts[MAXN];

// min cost to visit the first locations, ending in direction
ll dp[MAXN][4];

// RIGHT, UP, LEFT, DOWN
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// x and y range from [-COORD, COORD]
int encode(int x, int y, int dir) {
    return dir + 4 * (y + 6) + 4 * 13 * (x + 6);
}

bool in_bounds(const int& x, const int& y) {
    return -COORD <= x and x <= COORD
        and -COORD <= y and y <= COORD;
}

void read() {
    scanf("%d %d %d %d %d", &b, &s, &l, &r, &n);

    for (int x = -COORD; x <= COORD; ++x) {
        for (int y = -COORD; y <= COORD; ++y) {
            for (int d = 0; d < 4; ++d) {
                int node = encode(x, y, d);

                // 3 moves: straight (no change), straight (turn left), straight (turn right)
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (in_bounds(nx, ny)) {
                    // straight
                    int next_node = encode(nx, ny, d);
                    graph[node].push_back({next_node, b + s});

                    // right turns
                    next_node = encode(nx, ny, (d + 1) % 4);
                    graph[node].push_back({next_node, b + r});

                    // left turns
                    next_node = encode(nx, ny, (d + 3) % 4);
                    graph[node].push_back({next_node, b + l});
                }
            }
        }
    }

    pts[0] = {0, 0};
    int x, y;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &x, &y);
        pts[i] = {x, y};
    }

    for (int j = 0; j < 4; ++j) {
        dp[0][j] = 0;
    }
}

void calc_dist(int src) {
    if (dist[src][src] != -1) {
        return;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    dist[src][src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        ll cur_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[src][node] < cur_dist) {
            continue;
        }

        for (pii edge : graph[node]) {
            ll new_dist = cur_dist + edge.second;
            int next_node = edge.first;
            if (dist[src][next_node] == -1 or new_dist < dist[src][next_node]) {
                dist[src][next_node] = new_dist;
                pq.push({new_dist, next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(dist, -1, sizeof(dist));
    read();
    for (int i = 1; i <= n; ++i) {
        for (int j1 = 0; j1 < 4; ++j1) {
            dp[i][j1] = INF;
            int node = encode(pts[i].first, pts[i].second, j1);

            for (int j2 = 0; j2 < 4; ++j2) {
                int old_node = encode(pts[i - 1].first, pts[i - 1].second, j2);
                calc_dist(old_node);

                dp[i][j1] = min(dp[i][j1], dp[i - 1][j2] + dist[old_node][node]);
            }
        }
    }

    ll ans = INF;
    for (int j = 0; j < 4; ++j) {
        ans = min(ans, dp[n][j]);
    }

    printf("%lld\n", ans);

    return 0;
}
