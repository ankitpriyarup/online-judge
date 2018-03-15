#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 1003;
constexpr int INF = 1e9 + 7;
int n, m;
int a[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            dist[i][j] = INF;
        }
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;
    for (int i = 0; i < n; ++i) {
        pq.push({a[i][0], {i, 0}});
        dist[i][0] = a[i][0];
    }

    int cur;
    pii pos;
    int x, y;
    while (!pq.empty()) {
        tie(cur, pos) = pq.top();
        pq.pop();
        tie(x, y) = pos;
        if (dist[x][y] != cur) continue;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                int new_dist = max(cur, a[nx][ny]);
                if (new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    pq.push({new_dist, make_pair(nx, ny)});
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dist[i][m - 1]);
    }

    printf("%d\n", ans);
    
    return 0;
}
