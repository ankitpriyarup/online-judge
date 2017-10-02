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
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;

constexpr int MAXN = 1010;
int e, f;
int n, m;
char grid[MAXN][MAXN];

int num_pts;
pair<int, int> pts[MAXN];
vector<int> graph[2][MAXN];

bool elsa_edge(int a, int b) {
    int xd = pts[a].first - pts[b].first;
    int yd = pts[a].second - pts[b].second;

    return xd * xd + yd * yd <= e * e;
}

bool dad_edge(int a, int b) {
    if (pts[a].first == pts[b].first) {
        return abs(pts[b].second - pts[a].second) <= f;
    } else if (pts[a].second == pts[b].second) {
        return abs(pts[b].first - pts[a].first) <= f;
    } else {
        return false;
    }
}

int find(int g, int src, int sink) {
    vector<int> dist(MAXN, -1);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == sink) break;

        for (int child : graph[g][node]) {
            if (dist[child] == -1) {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }

    return dist[sink];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &e, &f);
    scanf("%d %d", &n, &m);
    num_pts = 0;

    int src, sink;
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                grid[i][j] = 'W';
                src = num_pts;
            } else if (grid[i][j] == 'G') {
                grid[i][j] = 'W';
                sink = num_pts;
            }

            if (grid[i][j] == 'W') {
                pts[num_pts] = {i, j};
                ++num_pts;
            }
        }
    }

    for (int i = 0; i < num_pts; ++i) {
        for (int j = i + 1; j < num_pts; ++j) {
            if (elsa_edge(i, j)) {
                graph[0][i].push_back(j);
                graph[0][j].push_back(i);
            }

            if (dad_edge(i, j)) {
                graph[1][i].push_back(j);
                graph[1][j].push_back(i);
            }
        }
    }

    int elsa_dist = find(0, src, sink);
    int dad_dist = find(1, src, sink);

    if (elsa_dist == -1 and dad_dist == -1) {
        printf("NO WAY\n");
    } else if (elsa_dist == dad_dist) {
        printf("SUCCESS\n");
    } else if (dad_dist == -1 or elsa_dist < dad_dist) {
        printf("GO FOR IT\n");
    } else {
        printf("NO CHANCE\n");
    }

    return 0;
}
