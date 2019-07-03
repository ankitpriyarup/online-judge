#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 666;
constexpr int INF = 1e9 + 7;
int a[MAXN][MAXN];
pii dist[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                dist[i][j] = {INF, INF};
            }
        }

        dist[n - 1][0] = {0, 0};
        priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq;
        pq.push({{0, 0}, {n - 1, 0}});

        while (!pq.empty()) {
            pii cur_dist = pq.top().first;
            int x, y;
            tie(x, y) = pq.top().second;
            pq.pop();
            if (cur_dist != dist[x][y])
                continue;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                    int dh = a[nx][ny] - a[x][y];
                    pii new_dist = {INF, INF};
                    if (0 <= dh and dh <= 2) {
                        new_dist = {cur_dist.first + dh, cur_dist.second};
                    } else if (-4 <= dh and dh < 0) {
                        new_dist = {cur_dist.first, cur_dist.second - dh};
                    }

                    if (new_dist < dist[nx][ny]) {
                        dist[nx][ny] = new_dist;
                        pq.push({new_dist, {nx, ny}});
                    }
                }
            }
        }

        if (dist[0][m - 1].first == INF) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << dist[0][m - 1].first << ' ' << dist[0][m - 1].second << '\n';
        }
    }
    
    return 0;
}
